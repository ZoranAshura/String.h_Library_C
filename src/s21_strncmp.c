#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int diff = 0;
  int flag = 0;
  if (str1 && str2 && n > 0) {
    for (s21_size_t i = 0; i < n && flag == 0; i++) {
      if (str1[i] != str2[i] || str1[i] == '\0' || str2[i] == '\0') {
        diff = str1[i] - str2[i];
        flag = 1;
      }
    }
  }
  return diff;
}
