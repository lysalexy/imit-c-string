#include "imit_sprintf_specifiers.h"

#include "../imit_string.h"
#include "stdlib.h"

void imit_get_width(char **src, int spacesAmount,
                   imit_sprintf_format_data format) {
  int whitespace_count = spacesAmount;
  while (whitespace_count > 0) {
    char paddingCh = format.flag_zero ? '0' : ' ';
    imit_sprintf_c(src, paddingCh, format, 0);
    whitespace_count--;
  }
}

void imit_sprintf_c(char **src, const char c, imit_sprintf_format_data format,
                   int needToImplementWidth) {
  int spacesAmount = format.width - 1;
  if ((needToImplementWidth) && (!format.left)) {
    imit_get_width(src, spacesAmount, format);
  }
  **src = c;
  *src = *src + 1;
  if ((needToImplementWidth) && (format.left)) {
    imit_get_width(src, spacesAmount, format);
  }
}

void imit_sprintf_s(char **src, const char *s, imit_sprintf_format_data format) {
  if (s != imit_NULL) {
    int string_precision = (int)imit_strlen(s);
    if ((string_precision > format.precision) && (format.precision != -1)) {
      string_precision = format.precision;
    }
    int primary_length = string_precision;
    int spacesAmount = format.width - primary_length;
    if (!format.left) {
      imit_get_width(src, spacesAmount, format);
    }
    while ((string_precision--) > 0) {
      imit_sprintf_c(src, *(s++), format, 0);
    }
    if (format.left) {
      imit_get_width(src, spacesAmount, format);
    }
  } else {
    imit_strncpy(*src, "(null)", 6);
    *src = *src + 6;
  }
}

void addLeadingZeros(char **src, int zerosAmount) {
  while ((zerosAmount--) > 0) {
    imit_sprintf_format_data format;
    imit_sprintf_c(src, '0', format, 0);
  }
}

void unsignedToString(const long unsigned n, int numberSize, char *str) {
  long unsigned number = n;

  for (int i = numberSize - 1; i >= 0; i--) {
    str[i] = number % 10 + '0';
    number /= 10;
  }
}

void imit_sprintf_u_d_i(char **src, const long long n,
                       imit_sprintf_format_data format, int isSigned) {
  long long number = n;
  long long numberCopy = n;

  if (numberCopy < 0) {
    numberCopy *= -1;
  }

  if (format.precision == 0 && n == 0) {
    return;
  }

  int numberSize = 0;
  while ((numberCopy > 0) || (numberSize == 0)) {
    numberCopy /= 10;
    numberSize++;
  }

  int amountOfLeadingZeros = 0;
  if (format.precision != -1) {
    amountOfLeadingZeros = (format.precision - numberSize) > 0
                               ? (format.precision - numberSize)
                               : 0;
  }
  char *tmp =
      calloc(numberSize + amountOfLeadingZeros + 1 + isSigned, sizeof(char));

  int startIndex = 0;

  char signValue = '0';
  if (isSigned) {
    startIndex = 1;
    if (n < 0) {
      signValue = '-';
      number *= -1;
    } else if (format.flag_plus == 1) {
      signValue = '+';
    } else if (format.flag_space == 1) {
      signValue = ' ';
    }
    if (signValue != '0') {
      tmp[0] = signValue;
    } else {
      startIndex = 0;
    }
  }

  for (int i = startIndex; i < amountOfLeadingZeros + startIndex; i++) {
    tmp[i] = '0';
  }

  unsignedToString(number, numberSize, tmp + amountOfLeadingZeros + startIndex);

  tmp[numberSize + amountOfLeadingZeros + startIndex] = '\0';
  format.precision = -1;
  imit_sprintf_s(src, tmp, format);
  free(tmp);
}

void imit_sprintf_o(char **src, const unsigned long o,
                   imit_sprintf_format_data format) {
  unsigned long number = o;
  unsigned long dec = o;
  int numberSize = 0;

  while ((number > 0) || (numberSize == 0)) {
    number /= 8;
    numberSize++;
  }
  int zerosAmount =
      (format.precision - numberSize > 0) ? format.precision - numberSize : 0;
  char *tmp = calloc(numberSize + 1 + zerosAmount, sizeof(char));

  if (format.precision != -1) {
    addLeadingZeros(&tmp, zerosAmount);
  }

  int i = numberSize - 1;
  if (dec == 0) {
    tmp[0] = '0';
  } else {
    while (dec != 0) {
      tmp[i] = "0123456789abcdef"[dec % 8];
      i--;
      dec /= 8;
    }
  }

  tmp[numberSize] = '\0';

  format.precision = -1;
  if (format.flag_sharp == 1 && o != 0) {
    imit_sprintf_c(src, '0', format, false);
  }
  imit_sprintf_s(src, tmp - zerosAmount, format);
  free(tmp - zerosAmount);
}

void imit_sprintf_x_X(char **src, unsigned long x,
                     imit_sprintf_format_data format, int upperX, int isP) {
  unsigned long num = x;

  char hex[100];
  int index = 0;

  while (num != 0) {
    int remainder = num % 16;
    char hexDigit;

    char aLetter = upperX ? 'A' : 'a';

    if (remainder < 10) {
      hexDigit = remainder + '0';
    } else {
      hexDigit = remainder - 10 + aLetter;
    }

    hex[index++] = hexDigit;
    num /= 16;
  }

  if (format.flag_sharp == 1 && x != 0) {
    char xLetter = upperX ? 'X' : 'x';
    hex[index++] = xLetter;
    hex[index++] = '0';
  }

  int zeroAndX = isP ? 2 : 0;

  int copyIndex = index;
  int spacesAmount;
  int addSymbol = (format.flag_plus == 1) || (format.flag_space == 1) ? 1 : 0;
  int amountOfLeadingZeros =
      (format.precision - copyIndex) > 0 ? (format.precision - copyIndex) : 0;
  int extra = (x == 0);

  spacesAmount = format.width - index - amountOfLeadingZeros - addSymbol -
                 zeroAndX - extra;

  if (index == 0 && format.precision > 0) {
    format.precision--;
    spacesAmount++;
  }

  if (!format.left) {
    imit_get_width(src, spacesAmount, format);
  }

  if (format.precision != -1) {
    addLeadingZeros(src, (format.precision - index - zeroAndX));
  }
  if (isP) {
    imit_sprintf_c(src, '0', format, 0);
    imit_sprintf_c(src, 'x', format, 0);
  }
  if (index == 0) {
    imit_sprintf_c(src, '0', format, 0);
  } else {
    for (int i = index - 1; i >= 0; i--) {
      imit_sprintf_c(src, hex[i], format, 0);
    }
  }

  if (format.left) {
    imit_get_width(src, spacesAmount, format);
  }
}

void imit_sprintf_p(char **src, imit_sprintf_format_data format, va_list *args) {
  unsigned long int ptr_name =
      (unsigned long int)va_arg(*args, unsigned long int);
  if (ptr_name == 0) {
    *src = imit_memcpy(*src, "(nil)", 5);
    *src += 5;
  } else {
    imit_sprintf_x_X(src, ptr_name, format, 0, 1);
  }
}

char *defineWholePart(long double n) {
  int symbolsAmount = log10(n) < 0 ? 0 : log10(n);

  char *fstr = calloc(symbolsAmount + 2, sizeof(char));

  int digit;
  int index = 0;

  while (index <= symbolsAmount) {
    long double weight = pow(10.0f, symbolsAmount - index);
    digit = (floor(n / weight) == 10) ? 9 : floor(n / weight);
    n -= (digit * weight);
    fstr[index] = '0' + digit;
    index++;
  }
  fstr[symbolsAmount + 1] = '\0';
  return fstr;
}

char *defineFraction(long double n, int precision) {
  char *fractionString = calloc(precision + 1, sizeof(char));
  char *symbolString = calloc(2, sizeof(char));
  symbolString[1] = '\0';
  fractionString[precision] = '\0';

  long double fraction = n - floor(n);

  for (int i = 1; i <= precision; i++) {
    long long unsigned symbol =
        (long long unsigned)(floor(fraction * pow(10.0f, i))) % 10;
    symbolString[0] = symbol + '0';
    fractionString = imit_strncat(fractionString, symbolString, 1);
  }
  free(symbolString);
  return fractionString;
}

char *roundFloat(long double n, char *src, int precision) {
  long double fraction = n - floor(n);
  long long unsigned symbol =
      (long long unsigned)(floor(fraction * pow(10.0f, precision + 1))) % 10;
  int hasOverflow = 1;
  if (symbol >= 5) {
    int i = imit_strlen(src) - 1;
    while ((i >= 0) && (hasOverflow == 1)) {
      if (src[i] != '.') {
        int current = (int)(src[i] - '0');
        if (current == 9) {
          src[i] = '0';
        } else {
          src[i] = (current + 1) + '0';
          hasOverflow = 0;
        }
      }
      i--;
    }
    if (hasOverflow) {
      char *result = imit_insert("1", src, 1);
      free(src);
      return result;
    }
  }
  return src;
}

void imit_sprintf_f(char **src, const long double n,
                   imit_sprintf_format_data format, int getRidOfTrailingZeros) {
  char *sign = calloc(2, sizeof(char));
  sign[1] = '\0';

  long double copy = n;
  char signValue = '0';
  if (n < 0) {
    signValue = '-';
    copy *= -1;
  } else if (format.flag_plus == 1) {
    signValue = '+';
  } else if (format.flag_space == 1) {
    signValue = ' ';
  }
  sign[0] = signValue;

  if (format.precision == -1) {
    format.precision = 6;
  }

  char *wholePart = defineWholePart(copy);
  int needSign = (n < 0) || (format.flag_plus == 1) || (format.flag_space == 1);
  int result_length = imit_strlen(wholePart) + format.precision + 1 + needSign;

  char *ftoi = calloc(result_length + 2, sizeof(char));
  ftoi[result_length + 1] = '\0';

  imit_strncat(ftoi, wholePart, imit_strlen(wholePart));
  imit_strncat(ftoi, ".", 1);

  int outputLenght = -1;
  if (format.precision == 0) {
    outputLenght =
        log10(copy) < 0 ? 1 + needSign : ceil(log10(copy)) + needSign;
  }

  char *fraction = defineFraction(copy, format.precision);
  imit_strncat(ftoi, fraction, format.precision);

  char *result = roundFloat(copy, ftoi, format.precision);

  format.precision = outputLenght;

  if ((ftoi != result) && (format.precision != -1)) {
    format.precision = format.precision + 1;
  }
  if ((getRidOfTrailingZeros) && (format.flag_sharp == 0)) {
    int lastSignificantFound = 0;
    int lastSignificant = imit_strlen(result) - 1;
    char symbol = result[lastSignificant];
    while ((symbol != '.') && (!lastSignificantFound)) {
      lastSignificantFound = (symbol != '0');
      if (!lastSignificantFound) {
        symbol = result[--lastSignificant];
      }
    }
    if (symbol == '.') {
      lastSignificant--;
    }
    result[lastSignificant + 1] = '\0';
  }

  if (needSign) {
    char *res = imit_insert(result, sign, 0);
    imit_sprintf_s(src, res, format);
    free(res);
  } else {
    imit_sprintf_s(src, result, format);
  }

  free(sign);
  free(wholePart);
  free(fraction);
  free(result);
}

void imit_sprintf_e_E(char **src, const long double n, int expInUpperCase,
                     imit_sprintf_format_data format,
                     int getRidOfTrailingZeros) {
  long double copy = n;
  if (copy < 0) {
    copy *= -1;
  }
  long double expPower = log10(copy);
  if (expPower == -INFINITY) {
    expPower = 0;
  }
  int offset = floor(expPower);

  if (format.precision == -1) {
    format.precision = 6;
  }

  char *res = calloc(format.precision * 2 + 3 + format.width, sizeof(char));

  const char *resStart = (const char *)res;

  imit_sprintf_format_data formatF = format;
  formatF.flag_minus = 0;
  formatF.flag_plus = 0;
  formatF.flag_space = 0;

  imit_sprintf_f(&res, copy / pow(10.0f, offset), formatF, 0);
  *res = '\0';

  char *dotPointer = imit_strchr(resStart, '.');
  if ((dotPointer - resStart == 2) ||
      ((dotPointer == imit_NULL) && (imit_strlen(resStart) == 2))) {
    offset += 1;
  }
  free((char *)resStart);

  char *res2 =
      calloc(50 + format.precision * 2 + 3 + format.width, sizeof(char));

  const char *res2Start = (const char *)res2;
  imit_sprintf_format_data formatS = format;
  formatS.width = 0;

  imit_sprintf_f(&res2, n / pow(10.0f, offset), formatS, getRidOfTrailingZeros);
  char expC = expInUpperCase ? 'E' : 'e';
  imit_sprintf_c(&res2, expC, format, 0);

  imit_sprintf_format_data formatU = format;
  formatU.precision = 2;
  formatU.width = 0;
  formatU.flag_plus = 1;

  imit_sprintf_u_d_i(&res2, offset, formatU, 1);

  format.precision = -1;

  imit_sprintf_s(src, res2Start, format);
  free((char *)res2Start);
}

int fractionHasSignificantDigits(long double fraction, int precision) {
  int digit = 0;
  int i = precision;
  int significantFound = 0;
  if (i <= 0) {
    i = i + 1;
    while (significantFound == 0) {
      digit = (int)(floor(fraction * pow(10.0f, i))) % 10;
      if (digit != 0) {
        significantFound = i;
      }
      i++;
    }
  } else {
    while ((i >= 0) && (significantFound == 0)) {
      digit = (int)(floor(fraction * pow(10.0f, i))) % 10;
      if (digit != 0) {
        significantFound = i;
      }
      i--;
    }
  }
  return significantFound;
}

void imit_sprintf_g_G(char **src, const long double n, int expInUpperCase,
                     imit_sprintf_format_data format) {
  long double copy = n;
  if (copy < 0) {
    copy *= -1;
  }
  char *wholePart = defineWholePart(copy);

  int whole_lenght = imit_strlen(wholePart);

  free(wholePart);

  long double expPower = log10(copy);
  if (expPower == -INFINITY) {
    expPower = 0;
  }

  if (format.precision == -1) {
    format.precision = 6;
  }

  if ((format.precision > expPower) && (expPower >= -4)) {
    int oldPrecision = format.precision;
    format.precision = format.precision - whole_lenght > 0
                           ? format.precision - whole_lenght
                           : 0;

    long double fraction = copy - floor(copy);

    int lastSignificantDigit =
        fractionHasSignificantDigits(fraction, format.precision);
    format.precision = (whole_lenght >= oldPrecision) && (oldPrecision != 0)
                           ? 0
                           : lastSignificantDigit;

    imit_sprintf_f(src, n, format, 1);
  } else {
    format.precision = format.precision - 1;
    imit_sprintf_e_E(src, n, expInUpperCase, format, 1);
  }
}
