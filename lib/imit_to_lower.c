#include "../imit_string.h"
#include "stdlib.h"

void *imit_to_lower(const char *str) {
  char *to_lower;
  if (str != imit_NULL) {
    imit_size_t strLenght = imit_strlen(str);
    to_lower = calloc(strLenght + 1, sizeof(char));
    to_lower[strLenght] = '\0';
    for (imit_size_t i = 0; i < strLenght; i++) {
      char value = str[i];
      if ((value >= 'A') && (value <= 'Z')) {
        int diff = (int)'A' - (int)'a';
        value = (char)(str[i] - diff);
      }
      to_lower[i] = value;
    }
  } else {
    to_lower = imit_NULL;
  }
  return to_lower;
}