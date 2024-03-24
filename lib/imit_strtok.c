#include <stdio.h>

#include "../imit_string.h"

int charIsDelimiter(const char *ch, const char *delim) {
  char *del = (char *)delim;
  int isDelimiter = 0;
  while ((*del != '\0') && (isDelimiter == 0)) {
    if (*del == *ch) {
      isDelimiter = 1;
    }
    del++;
  }
  return isDelimiter;
}

char *findDelimiter(char *str, const char *delim, int inv) {
  int found = 0;
  char *p = str;
  if (str != imit_NULL) {
    while ((*p != '\0') && (found == 0)) {
      found = charIsDelimiter(p, delim);
      if (inv) {
        found = found == 0 ? 1 : 0;
      }

      if (found == 0) {
        p++;
      }
    }
    if (*p == '\0') {
      p = imit_NULL;
    }
  }
  return p;
}

char *imit_strtok(char *str, const char *delim) {
  static char *string = imit_NULL;

  if (str != imit_NULL) {
    string = findDelimiter(str, delim, 1);
  } else {
    string = findDelimiter(string, delim, 1);
  }
  const char *p = string;

  char *delimiter = findDelimiter(string, delim, 0);
  if (delimiter != imit_NULL) {
    *delimiter = '\0';
    delimiter++;
    string = delimiter;
  } else {
    string = imit_NULL;
  }

  return (char *)p;
}