#include "../imit_string.h"

imit_size_t imit_strlen(const char *str) {
  imit_size_t count = 0;
  while (*str != '\0') {
    count++;
    str++;
  }
  return count;
}