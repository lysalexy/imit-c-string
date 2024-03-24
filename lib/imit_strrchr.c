#include "../imit_string.h"

char *imit_strrchr(const char *str, int c) {
  char *p = (char *)str;
  char *lastOcc = imit_NULL;
  while (*p != '\0') {
    if (*p == c) {
      lastOcc = p;
    }
    p++;
  }
  return c == '\0' ? p : lastOcc;
}