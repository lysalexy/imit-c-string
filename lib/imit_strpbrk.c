#include "../imit_string.h"

char *imit_strpbrk(const char *str1, const char *str2) {
  while (*str1 != '\0') {
    const char *a = str2;
    while (*a != '\0')
      if (*a++ == *str1) return (char *)str1;
    str1++;
  }
  return imit_NULL;
}