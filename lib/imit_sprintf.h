#ifndef imit_SPRINTF_H_
#define imit_SPRINTF_H_

#define PERCENT_SIGN '%'

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

typedef struct imit_sprintf_format_data {
  int flag_minus;
  int flag_plus;
  int flag_space;
  int flag_zero;
  int flag_sharp;
  int width;
  bool left;
  int precision;
  char length;

  char specifier;
} imit_sprintf_format_data;

void imit_sprintf_process_arg(char **str, imit_sprintf_format_data form_data,
                             va_list *args, const char *beg);

int imit_sprintf_is_format_character(char ch);
int imit_sprintf_is_specifier_character(char ch);
int imit_sprintf_is_space_character(char ch);

int imit_is_length(char ch);
int imit_is_flag(char ch);
void imit_get_flag(imit_sprintf_format_data *specifier, const char *format);
#endif