#include "../imit_string.h"

int imit_memcmp(const void *str1, const void *str2, imit_size_t n) {
  if (!n) {
    return (0);
  }

  while (--n && *(char *)str1 == *(char *)str2) {
    str1 = (char *)str1 + 1;
    str2 = (char *)str2 + 1;
  }

  int str1_val = *((unsigned char *)str1);
  int str2_val = *((unsigned char *)str2);
  if (str1_val == str2_val) {
    return 0;
  }

  return str1_val > str2_val ? 1 : -1;
}