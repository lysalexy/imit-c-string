#include "../imit_string.h"

void *imit_trim(const char *src, const char *trim_chars) {
  char *result = imit_NULL;

  if (src != imit_NULL && trim_chars != imit_NULL) {
    size_t length = imit_strlen(src);
    size_t start_pos = 0;
    while (start_pos < length &&
           imit_strchr(trim_chars, src[start_pos]) != imit_NULL) {
      start_pos++;
    }
    size_t end_pos = length;
    while (end_pos > start_pos &&
           imit_strchr(trim_chars, src[end_pos - 1]) != imit_NULL) {
      end_pos--;
    }
    size_t result_length = (end_pos > start_pos) ? (end_pos - start_pos) : 0;
    result = (char *)calloc(result_length + 1, sizeof(char));

    if (result != imit_NULL) {
      imit_strncpy(result, src + start_pos, result_length);
      result[result_length] = '\0';
    }
  }

  return result;
}