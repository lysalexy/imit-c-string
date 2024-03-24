#include "../imit_string.h"

void *imit_memchr(const void *str, int c, imit_size_t n) {
  unsigned char *byte = (unsigned char *)str;
  while (n-- > 0) {
    if (*byte == c) {
      return byte;
    }
    byte++;
  }
  return imit_NULL;
}