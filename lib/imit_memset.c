#include "../imit_string.h"

void *imit_memset(void *str, int c, imit_size_t n) {
  char *p = (char *)str;
  while (n-- > 0) {
    *p++ = c;
  }
  return str;
}