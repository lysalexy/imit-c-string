#include "../imit_string.h"
#include "stdlib.h"

void *imit_insert(const char *src, const char *str, imit_size_t start_index) {
  char *result = imit_NULL;
  if ((src != imit_NULL) && (str != imit_NULL)) {
    imit_size_t strLenght = imit_strlen(str);
    imit_size_t srcLenght = imit_strlen(src);
    if (srcLenght >= start_index) {
      result = calloc(strLenght + srcLenght + 1, sizeof(char));
      result[strLenght + srcLenght] = '\0';

      if (start_index == 0) {
        imit_strncpy(result, str, strLenght);
        imit_strncpy(result + strLenght, src, srcLenght);
      } else if (start_index == srcLenght) {
        imit_strncpy(result, src, srcLenght);
        imit_strncpy(result + srcLenght, str, strLenght);
      } else {
        imit_strncpy(result, src, start_index);
        imit_strncpy(result + start_index, str, strLenght);
        imit_strncpy(result + start_index + strLenght, src + start_index,
                    srcLenght - start_index);
      }
    }
  }
  return result;
}