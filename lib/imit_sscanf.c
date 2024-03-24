#include "imit_sscanf.h"

#include "../imit_string.h"

int imit_sscanf(const char *str, const char *format, ...) {
  if (str[0] == '\0') {
    return -1;
  }

  int res = 0;
  if (imit_strchr(format, PERCENT_SIGN) == imit_NULL) {
    return res;
  }

  va_list args;
  va_start(args, format);

  int is_space_symbol_before = 0;
  char *f = (char *)format;
  char *s = (char *)str;
  while (*f != '\0') {
    if (is_space_character(*f)) {
      is_space_symbol_before = 1;
      f++;
      continue;
    }

    if (*f == PERCENT_SIGN) {
      f++;
      format_data form_data;
      init_form_data(&form_data);
      if (!is_space_symbol_before) {
        form_data.is_need_check_space = 1;
      }

      if (!parse_format_data(&form_data, &f)) break;
      if (!process_arg(&s, form_data, &args, s - str)) break;
      if (form_data.assignments && form_data.specifier != '%' &&
          form_data.specifier != 'n') {
        res++;
      }
    } else {
      if (!is_space_symbol_before && is_space_character(*s)) return res;
      while (is_space_character(*s)) {
        s++;
      }

      if (*f != *s) return res;
      s++;
    }

    f++;
  }

  va_end(args);
  return is_only_space(str) && res == 0 ? -1 : res;
}

int is_only_space(const char *str) {
  const char *p = str;
  int is_only_space = 1;
  while (*p) {
    if (!is_space_character(*p)) {
      is_only_space = 0;
      break;
    }
    p++;
  }

  return is_only_space;
}

void init_form_data(format_data *form_data) {
  form_data->assignments = 1;
  form_data->length = 0;
  form_data->length_len = 0;
  form_data->width = 0;
  form_data->is_need_check_space = 0;
}

int process_arg(char **str, format_data form_data, va_list *args,
                const int read) {
  int res = 1;
  switch (form_data.specifier) {
    case 's':;
      res = process_specifier_s(str, args, form_data);
      break;
    case 'c':;
      res = process_specifier_c(str, args, form_data);
      break;
    case 'd':;
    case 'i':;
      res = process_specifier_d_i(str, args, form_data);
      break;
    case 'o':
    case 'u':
    case 'x':
    case 'X':
      res = process_specifier_u_o_x(str, args, form_data);
      break;
    case 'p':;
      res = process_specifier_p(str, args, form_data);
      break;
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
      res = process_specifier_eEfgG(str, args, form_data);
      break;
    case 'n':
      process_specifier_n(str, args, form_data, read);
      break;
    case '%':;
      while (is_space_character(**str)) {
        (*str)++;
      }

      if (**str != '%')
        res = 0;
      else {
        *str += 1;
      }
      break;
    default:
      res = 0;
      break;
  }

  return res;
}

void process_specifier_n(char **str, va_list *args, format_data form_data,
                         const int read) {
  int spacing = 0;
  if (!form_data.is_need_check_space && is_space_character(**str)) {
    char *str_p;
    while ((str_p = imit_strchr(" \n\t\r\x0B\f", **str)) && *str_p) {
      *str += 1;
      ;
      ++spacing;
    }
  }
  *(int *)va_arg(*args, void *) = read + spacing;
}

int process_specifier_eEfgG(char **str, va_list *args,
                            format_data format_modifiers) {
  while (is_space_character(**str)) {
    (*str)++;
  }

  char *str_p;
  int success = 1;

  if (*str == imit_NULL) {
    success = 0;
  } else {
    str_p = *str;

    if (format_modifiers.width &&
        format_modifiers.width < (int)imit_strlen(*str)) {
      str_p = (char *)calloc(format_modifiers.width + 1, sizeof(char));
      if (str_p == imit_NULL) {
        success = 0;
      } else {
        str_p = imit_strncat(str_p, *str, format_modifiers.width);
      }
    }
    if (success) {
      char *end;
      if (format_modifiers.length == 'L') {
        long double res = strtold(str_p, &end);
        if (end == str_p) {
          success = 0;
        } else if (format_modifiers.assignments) {
          *(long double *)va_arg(*args, void *) = res;
        }
      } else if (format_modifiers.length == 'l') {
        double res = strtod(str_p, &end);
        if (end == str_p) {
          success = 0;
        } else if (format_modifiers.assignments) {
          *(double *)va_arg(*args, void *) = res;
        }
      } else {
        float res = strtof(str_p, &end);
        if (end == str_p) {
          success = 0;
        } else if (format_modifiers.assignments) {
          *(float *)va_arg(*args, void *) = res;
        }
      }
      char *tmp = *str;
      *str += end - str_p;
      if (format_modifiers.width &&
          format_modifiers.width < (int)imit_strlen(tmp))
        free(str_p);
    }
  }
  return success;
}

int process_specifier_d_i(char **str, va_list *args, format_data form_data) {
  while (is_space_character(**str)) {
    (*str)++;
  }

  int success = 1;
  int is_shortest = form_data.width && form_data.width < (int)imit_strlen(*str);

  char *str_p = *str;
  char *end;

  if (is_shortest) {
    str_p = (char *)calloc(form_data.width + 1, sizeof(char));
    str_p = imit_strncat(str_p, *str, form_data.width);
  }

  long res = strtol(str_p, &end, form_data.specifier == 'd' ? 10 : 0);
  if (end == str_p) {
    success = 0;
  } else {
    if (form_data.assignments) {
      if (form_data.length == 'h') {
        if (form_data.length_len == 1)
          *(short int *)va_arg(*args, void *) = (short int)res;
        if (form_data.length_len == 2)
          *(signed char *)va_arg(*args, void *) = (signed char)res;
      } else if (form_data.length == 'l') {
        if (form_data.length_len == 1) *(long int *)va_arg(*args, void *) = res;
        if (form_data.length_len == 2)
          *(long long int *)va_arg(*args, void *) = (long long int)res;
      } else
        *(int *)va_arg(*args, void *) = (int)res;
    }
  }

  *str += end - str_p;
  if (is_shortest) {
    free(str_p);
  }

  return success;
}

int process_specifier_u_o_x(char **str, va_list *args, format_data form_data) {
  while (is_space_character(**str)) {
    (*str)++;
  }

  int success = 1;
  int is_shortest = form_data.width && form_data.width < (int)imit_strlen(*str);

  char *str_p = *str;
  char *end;

  if (is_shortest) {
    str_p = (char *)calloc(form_data.width + 1, sizeof(char));
    str_p = imit_strncat(str_p, *str, form_data.width);
  }

  int base = 16;
  if (form_data.specifier == 'o')
    base = 8;
  else if (form_data.specifier == 'u')
    base = 10;

  long res = strtoul(str_p, &end, base);
  if (end == str_p) {
    success = 0;
  } else {
    if (form_data.assignments) {
      if (form_data.length == 'h') {
        if (form_data.length_len == 1)
          *(unsigned short *)va_arg(*args, void *) = (unsigned short)res;
        if (form_data.length_len == 2)
          *(unsigned char *)va_arg(*args, void *) = (unsigned char)res;
      } else if (form_data.length == 'l') {
        if (form_data.length_len == 1)
          *(unsigned long *)va_arg(*args, void *) = res;
        if (form_data.length_len == 2)
          *(unsigned long long *)va_arg(*args, void *) = res;
      } else
        *(unsigned int *)va_arg(*args, void *) = (unsigned int)res;
    }
  }

  *str += end - str_p;
  if (is_shortest) {
    free(str_p);
  }

  return success;
}

int process_specifier_p(char **str, va_list *args, format_data form_data) {
  int success = 1;
  char *end;

  unsigned long int res = strtoul(*str, &end, 16);
  if (end == *str) {
    success = 0;
  } else if (form_data.assignments) {
    unsigned long int *ptr = va_arg(*args, unsigned long int *);
    *ptr = res;
  }

  *str = end;

  return success;
}

int process_specifier_s(char **str, va_list *args, format_data form_data) {
  while (is_space_character(**str)) {
    (*str)++;
  }

  if (!(**str)) {
    return 0;
  }

  if (form_data.assignments) {
    if (form_data.length == 'l') {
      process_specifier_s_l(str, args, form_data);
    } else {
      process_specifier_s_default(str, args, form_data);
    }
  } else {
    while (!is_space_character(**str)) {
      (*str)++;
    }
  }

  return 1;
}

int process_specifier_c(char **str, va_list *args, format_data form_data) {
  if (!(**str)) {
    return 0;
  }

  if (!form_data.is_need_check_space && is_space_character(**str)) {
    while (is_space_character(**str)) {
      (*str)++;
    }
  }

  int success = 1;
  if (form_data.assignments) {
    if (form_data.length == 'l') {
      int res = mbtowc(va_arg(*args, wchar_t *), *str, 2);
      if (res == -1 || !res) success = 0;
    } else {
      *va_arg(*args, char *) = **str;
    }
  }

  (*str)++;

  return success;
}

void process_specifier_s_l(char **str, va_list *args, format_data form_data) {
  int cnt = 0;
  wchar_t *wstr = va_arg(*args, wchar_t *);
  while (!is_space_character(**str) && **str) {
    cnt++;
    *wstr = (wchar_t) * *str;
    (*str)++;
    wstr++;
    if (form_data.width > 0 && cnt >= form_data.width) {
      break;
    }
  }
  *wstr = L'\0';
}

void process_specifier_s_default(char **str, va_list *args,
                                 format_data form_data) {
  int cnt = 0;
  char *s = va_arg(*args, char *);
  while (!is_space_character(**str) && **str) {
    cnt++;
    *s = **str;
    (*str)++;
    s++;
    if (form_data.width > 0 && cnt >= form_data.width) {
      break;
    }
  }
  *s = '\0';
}

int parse_format_data(format_data *form_data, char **format) {
  int res = 1;
  while (**format != '\0' || **format != PERCENT_SIGN) {
    if (**format >= '0' && **format <= '9') {
      form_data->width = atoi(*format);
      while (**format && **format >= '0' && **format <= '9') (*format)++;
    } else if (**format == '*') {
      form_data->assignments = 0;
      (*format)++;
    }

    if (**format == 'L') {
      form_data->length = **format;
      form_data->length_len++;
      (*format)++;
    }

    if (**format == 'h') {
      form_data->length = **format;
      form_data->length_len++;
      (*format)++;
      if (**format == 'h') {
        form_data->length_len++;
        (*format)++;
      }
    }

    if (**format == 'l') {
      form_data->length = **format;
      form_data->length_len++;
      (*format)++;
      if (**format == 'l') {
        form_data->length_len++;
        (*format)++;
      }
    }

    if (!is_specifier_character(**format)) {
      res = 0;
    } else {
      form_data->specifier = **format;
    }

    break;
  }

  return res;
}

int is_specifier_character(char ch) {
  return imit_strchr("csdipouxXeEfgGn%", ch) != imit_NULL;
}

int is_space_character(char ch) {
  return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r' || ch == '\x0B' ||
         ch == '\f';
}