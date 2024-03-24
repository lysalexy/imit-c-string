#include "../imit_string.h"

void *imit_memcpy(void *dest, const void *src, imit_size_t n) {
  char *d = (char *)dest;
  char *s = (char *)src;
  while (n-- > 0) {
    *d++ = *s++;
  }
  return dest;
}