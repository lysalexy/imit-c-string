#include "imit_sprintf.h"

#include "imit_sprintf_specifiers.h"
#include "stdlib.h"

int imit_sprintf_is_space_character(char ch) {
  return ch == ' ' || ch == '\t' || ch == '\n';
}

int imit_is_length(char ch) {
  int res = ((ch) == 'h' || (ch) == 'l' || (ch) == 'L');
  return res;
}

bool imit_is_digit_character(char ch) { return ('0' <= ch) && (ch <= '9'); }

int imit_sprintf_get_precision(char **format, imit_sprintf_format_data *form_data,
                              va_list *args) {
  int precision = 0;
  *format = *format + 1;
  char *ch = format[0];

  int result = 1;

  if ((*ch) != '*') {
    while ((imit_sprintf_is_specifier_character(*ch) == 0) &&
           (imit_sprintf_is_space_character(*ch) == 0) &&
           (imit_is_length(*ch) == 0)) {
      precision *= 10;
      if (imit_is_digit_character(*ch)) {
        precision += (int)(*ch - '0');
      } else {
        result = -1;
      }
      *format = *format + 1;
      ch = format[0];
    }
  } else {
    precision = va_arg(*args, int);
    if (precision < 0) {
      result = -2;
    }
  }
  if (result == 1) {
    form_data->precision = precision;
  }
  return result;
}

int imit_sprintf_parse_format_data(imit_sprintf_format_data *form_data,
                                  char **format, va_list *args) {
  char *ch = (char *)format[0];
  int result = 1;

  while (**format != '\0' || imit_sprintf_is_space_character(**format)) {
    while (imit_is_flag(*ch)) {
      imit_get_flag(form_data, *format);
      (*format)++;
      ch = (char *)*format;
    }

    while (imit_is_digit_character(*ch) || (**format == '*') ||
           (**format == '-')) {
      if (imit_is_digit_character(*ch)) {
        form_data->width = atoi(ch);

        while (imit_is_digit_character(*ch)) {
          *format = *format + 1;
          ch = format[0];
        }
        continue;

      } else if (**format == '*') {
        form_data->width = va_arg(*args, int);
      }
      (*format)++;
    }

    if (**format == '.') {
      int precisionResult = imit_sprintf_get_precision(format, form_data, args);
      result = (precisionResult == 1) ? result : precisionResult;
    }

    ch = (char *)format[0];

    if (imit_is_length(*ch)) {
      form_data->length = *ch;
      (*format)++;
      ch = (char *)*format;
    }

    if (imit_sprintf_is_specifier_character(*ch)) {
      form_data->specifier = *ch;
      return result;
    }
    (*format)++;
  }
  return result;
}

int imit_is_flag(char ch) {
  int res =
      ((ch) == '-' || (ch) == '+' || (ch) == ' ' || (ch) == '0' || (ch) == '#');
  return res;
}

void imit_get_flag(imit_sprintf_format_data *specifier, const char *format) {
  switch (*format) {
    case '-':
      specifier->flag_minus = 1;
      specifier->left = 1;
      break;
    case '+':
      specifier->flag_plus = 1;
      break;
    case ' ':
      specifier->flag_space = 1;
      break;
    case '0':
      specifier->flag_zero = 1;
      break;
    case '#':
      specifier->flag_sharp = 1;
      break;
    default:
      break;
  }
}

void imit_sprintf_process_arg(char **str, imit_sprintf_format_data form_data,
                             va_list *args, const char *beg) {
  switch (form_data.specifier) {
    case 'c':;
      char c = va_arg(*args, int);
      imit_sprintf_c(str, c, form_data, 1);
      break;
    case 'd':
    case 'i':;
      int64_t d;
      switch (form_data.length) {
        case ('h'):
          d = va_arg(*args, int);
          d = (short int)d;
          break;
        case ('l'):
          d = va_arg(*args, long int);
          break;
        default:
          d = va_arg(*args, int);
          break;
      }

      imit_sprintf_u_d_i(str, d, form_data, 1);
      break;
    case 'u':;
      uint64_t u;
      switch (form_data.length) {
        case ('h'):
          u = va_arg(*args, unsigned int);
          u = (unsigned short)u;
          break;
        case ('l'):
          u = va_arg(*args, long unsigned int);
          break;
        default:
          u = va_arg(*args, unsigned int);
          break;
      }
      imit_sprintf_u_d_i(str, u, form_data, 0);
      break;
    case 'f':;
      long double f;
      switch (form_data.length) {
        case ('L'):
          f = va_arg(*args, long double);
          break;
        case ('l'):
          f = va_arg(*args, double);
          break;
        default:
          f = va_arg(*args, double);
          f = (float)f;
          break;
      }
      imit_sprintf_f(str, f, form_data, 0);
      break;
    case 's':;
      char *s = va_arg(*args, char *);
      imit_sprintf_s(str, s, form_data);
      break;
    case 'e':;
      long double e;
      switch (form_data.length) {
        case ('L'):
          e = va_arg(*args, long double);
          break;
        case ('l'):
          e = va_arg(*args, double);
          break;
        default:
          e = va_arg(*args, double);
          e = (float)e;
          break;
      }
      imit_sprintf_e_E(str, e, 0, form_data, 0);
      break;
    case 'E':;
      long double E;
      switch (form_data.length) {
        case ('L'):
          E = va_arg(*args, long double);
          break;
        case ('l'):
          E = va_arg(*args, double);
          break;
        default:
          E = va_arg(*args, double);
          E = (float)E;
          break;
      }
      imit_sprintf_e_E(str, E, 1, form_data, 0);
      break;
    case 'g':;
      long double g;
      switch (form_data.length) {
        case ('L'):
          g = va_arg(*args, long double);
          break;
        case ('l'):
          g = va_arg(*args, double);
          break;
        default:
          g = va_arg(*args, double);
          g = (float)g;
          break;
      }
      imit_sprintf_g_G(str, g, 0, form_data);
      break;
    case 'G':;
      long double G;
      switch (form_data.length) {
        case ('L'):
          G = va_arg(*args, long double);
          break;
        case ('l'):
          G = va_arg(*args, double);
          break;
        default:
          G = va_arg(*args, double);
          G = (float)G;
          break;
      }
      imit_sprintf_g_G(str, G, 1, form_data);
      break;
    case 'o':;
      unsigned long o;
      switch (form_data.length) {
        case ('h'):
          o = va_arg(*args, unsigned);
          o = (unsigned short)o;
          break;
        case ('l'):
          o = va_arg(*args, unsigned long);
          break;
        default:
          o = va_arg(*args, unsigned);
          break;
      }

      imit_sprintf_o(str, o, form_data);
      break;
    case 'x':;
      uint32_t x = va_arg(*args, uint32_t);
      imit_sprintf_x_X(str, x, form_data, 0, 0);
      break;
    case 'X':;
      uint32_t X = va_arg(*args, uint32_t);
      imit_sprintf_x_X(str, X, form_data, 1, 0);
      break;
    case 'p':;
      imit_sprintf_p(str, form_data, args);
      break;
    case 'n':;
      int *n = va_arg(*args, int *);
      *n = (int)(*str - beg);
      break;
    case '%':;
      imit_sprintf_c(str, '%', form_data, 0);
      break;
    default:
      break;
  }
}

int imit_sprintf_is_specifier_character(char ch) {
  {
    char specifiers[] = "cdieEfgGosuxXpn%";
    char *symbolContains = imit_strchr(specifiers, ch);
    return symbolContains == imit_NULL ? 0 : 1;
  }
}

void imit_sprintf_invalid_pattern(char *iter, char *formatPointer, char **str) {
  imit_sprintf_format_data form_data;
  while (iter++ <= formatPointer) {
    if ((*(iter - 1) == '.') && (!(imit_is_digit_character(*iter)))) {
      imit_sprintf_c(str, '0', form_data, 0);
    }
    if (*iter != '\0') {
      imit_sprintf_c(str, *iter, form_data, 0);
    }
  }
}

int imit_sprintf(char *str, const char *format, ...) {
  const char *beg = (const char *)str;
  va_list args;
  va_start(args, format);
  int result = 1;
  int parsingResult = 1;
  char *formatPointer = (char *)format;

  while ((*formatPointer != '\0') && (result == 1) && (parsingResult == 1)) {
    switch (*formatPointer) {
      case PERCENT_SIGN:;
        const char *startPointer = (const char *)(formatPointer - 1);
        formatPointer++;

        imit_sprintf_format_data form = {0};
        form.precision = -1;
        form.length = '0';

        parsingResult =
            imit_sprintf_parse_format_data(&form, &formatPointer, &args);

        int negativePrecisionAsNumberIsPossible =
            ((parsingResult == -2) &&
             ((form.specifier == 'c') || (form.specifier == 'f') ||
              (form.specifier == 'e') || (form.specifier == 'E') ||
              (form.specifier == 'g') || (form.specifier == 'G')));

        if (parsingResult == 1 || negativePrecisionAsNumberIsPossible) {
          imit_sprintf_process_arg(&str, form, &args, beg);
          parsingResult = 1;
        } else {
          char *iter = (char *)startPointer;
          imit_sprintf_invalid_pattern(iter, formatPointer, &str);
        }
        break;
      default:
        *str = *formatPointer;
        str++;
        break;
    }
    formatPointer++;
  }
  *str = '\0';

  va_end(args);

  return (result == 1) ? str - beg : -1;
}
