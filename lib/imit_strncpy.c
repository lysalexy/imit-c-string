#include "../imit_string.h"

char *imit_strncpy(char *dest, const char *src, imit_size_t n) {
  imit_size_t i;
  for (i = 0; i < n && src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
  for (; i < n; i++) {
    dest[i] = '\0';
  }
  return dest;
}
