#include <stdlib.h>

#ifndef imit_STRING_H_
#define imit_STRING_H_

#define imit_NULL ((void *)0)

typedef long unsigned imit_size_t;

void *imit_memchr(const void *str, int c, imit_size_t n);
imit_size_t imit_strcspn(const char *str1, const char *str2);
imit_size_t imit_strlen(const char *str);
char *imit_strpbrk(const char *str1, const char *str2);
char *imit_strerror(int errnum);

int imit_memcmp(const void *str1, const void *str2, imit_size_t n);
void *imit_memcpy(void *dest, const void *src, imit_size_t n);
void *imit_memset(void *str, int c, imit_size_t n);
char *imit_strrchr(const char *str, int c);
char *imit_strstr(const char *haystack, const char *needle);
char *imit_strtok(char *str, const char *delim);

char *imit_strchr(const char *str, int c);
char *imit_strncat(char *dest, const char *src, imit_size_t n);
int imit_strncmp(const char *str1, const char *str2, imit_size_t n);
char *imit_strncpy(char *dest, const char *src, imit_size_t n);

int imit_sprintf(char *str, const char *format, ...);
int imit_sscanf(const char *str, const char *format, ...);

void *imit_to_upper(const char *str);
void *imit_to_lower(const char *str);
void *imit_insert(const char *src, const char *str, imit_size_t start_index);
void *imit_trim(const char *src, const char *trim_chars);

#endif
