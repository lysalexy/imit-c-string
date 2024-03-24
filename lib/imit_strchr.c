#include "../imit_string.h"

char *imit_strchr(const char *str, int c) {
  char *res = imit_NULL;
  for (char *p = (char *)str; *p != '\0'; p++) {
    if (*p == (char)c) {
      res = p;
      break;
    }
  }
  return res;
}
