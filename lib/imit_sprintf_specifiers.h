#ifndef imit_SPRINTF_SPECIFIERS_H_
#define imit_SPRINTF_SPECIFIERS_H_

#include "../imit_string.h"
#include "imit_sprintf.h"

void imit_sprintf_c(char **src, const char c, imit_sprintf_format_data format,
                   int needToImplementWidth);

void imit_sprintf_u_d_i(char **src, const long long n,
                       imit_sprintf_format_data format, int isSigned);
void imit_sprintf_f(char **src, const long double n,
                   imit_sprintf_format_data format, int getRidOfTrailingZeros);
void imit_sprintf_o(char **src, const unsigned long o,
                   imit_sprintf_format_data format);
void imit_sprintf_x_X(char **src, unsigned long x,
                     imit_sprintf_format_data format, int upperX, int isP);
void imit_sprintf_p(char **src, imit_sprintf_format_data format, va_list *args);
void imit_sprintf_s(char **src, const char *s, imit_sprintf_format_data format);

void imit_sprintf_e_E(char **src, const long double n, int expInUpperCase,
                     imit_sprintf_format_data format, int getRidOfTrailingZeros);
void imit_sprintf_g_G(char **src, const long double n, int expInUpperCase,
                     imit_sprintf_format_data format);

char *signFlag(char *str, imit_sprintf_format_data *format);

#endif