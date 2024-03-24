#include "../imit_string.h"

char *imit_strstr(const char *haystack, const char *needle) {
  char *p = (char *)haystack;
  char *n = (char *)needle;
  char *tempP = p;
  int found = 0;
  while ((*p != '\0') && (found == 0)) {
    found = 1;
    n = (char *)needle;
    tempP = p;
    while ((*n != '\0') && found) {
      if (*tempP != *n) {
        found = 0;
      }
      tempP++;
      n++;
    }
    if (found == 0) {
      p++;
    }
  }
  return (*p == '\0') ? imit_NULL : p;
}