#include <stdarg.h>

#ifndef imit_SSCANF_H_
#define imit_SSCANF_H_

#define PERCENT_SIGN '%'

typedef struct format_data {
  int is_need_check_space;
  int assignments;
  int width;
  char length;
  int length_len;
  char specifier;
} format_data;

int parse_format_data(format_data *form_data, char **format);
void init_form_data(format_data *form_data);

int process_arg(char **str, format_data form_data, va_list *args,
                const int read);
int process_specifier_s(char **str, va_list *args, format_data form_data);
int process_specifier_c(char **str, va_list *args, format_data form_data);
void process_specifier_s_default(char **str, va_list *args,
                                 format_data form_data);
void process_specifier_s_l(char **str, va_list *args, format_data form_data);
int process_specifier_d_i(char **str, va_list *args, format_data form_data);
int process_specifier_u_o_x(char **str, va_list *args, format_data form_data);
int process_specifier_p(char **str, va_list *args, format_data form_data);
int process_specifier_eEfgG(char **str, va_list *args,
                            format_data format_modifiers);
void process_specifier_n(char **str, va_list *args, format_data form_data,
                         const int read);

int is_only_space(const char *str);
int is_format_character(char ch);
int is_specifier_character(char ch);
int is_space_character(char ch);
int is_length_character(char ch);

#endif