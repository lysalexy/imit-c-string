#include "../imit_string.h"

imit_size_t imit_strcspn(const char *str1, const char *str2) {
  imit_size_t counter_len = 0;
  const char *s1, *s2;
  for (s1 = str1; *s1; s1++) {
    int found = 0;
    for (s2 = str2; *s2; s2++) {
      if (*s1 == *s2) {
        found = 1;
        break;
      }
    }
    if (found) {
      break;
    } else {
      counter_len++;
    }
  }
  return counter_len;
}