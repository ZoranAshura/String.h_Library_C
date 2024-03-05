#include "s21_string.h"

int left_index(const char *src, const char *to_trim, int first) {
  int res = 0;
  for (int i = 0; i < (int)s21_strlen(to_trim); i++) {
    if (src[first] == to_trim[i]) res = 1;
  }
  return res;
}

int right_index(const char *src, const char *to_trim, int last) {
  int res = 0;
  for (int i = 0; i < (int)s21_strlen(to_trim); i++) {
    if (src[last] == to_trim[i]) res = 1;
  }
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = S21_NULL;
  if (src) {
    if (trim_chars && trim_chars[0]) {
      res = calloc(s21_strlen(src) + 1, sizeof(char));
      if (res) {
        int first = 0, last = s21_strlen(src);
        while (left_index(src, trim_chars, first)) {
          first++;
        }
        if (first != last) {
          while (right_index(src, trim_chars, last - 1)) {
            last--;
          }
          int k = 0;
          for (int i = first; i < last; i++) {
            res[k] = src[i];
            k++;
          }
        } else {
          res[0] = '\0';
        }
      }
    } else {
      res = s21_trim(src, "\t\n");
    }
  }
  return res;
}
