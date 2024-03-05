#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  s21_size_t j, i = 0;
  char *result = S21_NULL;
  if (needle[0] == '\0') {
    result = (char *)haystack;
  }
  while (haystack[i] != '\0') {
    j = 0;
    while (haystack[i + j] != '\0' && haystack[i + j] == needle[j]) {
      if (needle[j + 1] == '\0') {
        result = (char *)(haystack + i);
      }
      ++j;
    }
    ++i;
  }
  return result;
}
