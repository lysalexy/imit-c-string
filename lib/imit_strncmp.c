#include "../imit_string.h"

int imit_strncmp(const char *str1, const char *str2, imit_size_t n) {
  imit_size_t i;
  for (i = 0; i < n && str1[i] != '\0' && str2[i] != '\0'; i++) {
    if (str1[i] != str2[i]) {
      return (int)(unsigned char)str1[i] - (int)(unsigned char)str2[i];
    }
  }
  if (i < n) {
    return (int)(unsigned char)str1[i] - (int)(unsigned char)str2[i];
  }
  return 0;
}
