#include "../imit_string.h"

char *imit_strncat(char *dest, const char *src, imit_size_t n) {
  imit_size_t dest_len = imit_strlen(dest);
  imit_size_t i;
  imit_size_t src_len = imit_strlen(src);
  for (i = 0; i < n && i < src_len; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + i] = '\0';
  return dest;
}
