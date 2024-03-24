#include "../imit_string.h"
#include "stdlib.h"

void *imit_to_upper(const char *str) {
  char *to_upper;
  if (str != imit_NULL) {
    imit_size_t strLenght = imit_strlen(str);
    to_upper = calloc(strLenght + 1, sizeof(char));
    to_upper[strLenght] = '\0';
    for (imit_size_t i = 0; i < strLenght; i++) {
      char value = str[i];
      if ((value >= 'a') && (value <= 'z')) {
        int diff = (int)'A' - (int)'a';
        value = (char)(str[i] + diff);
      }
      to_upper[i] = value;
    }
  } else {
    to_upper = imit_NULL;
  }
  return to_upper;
}