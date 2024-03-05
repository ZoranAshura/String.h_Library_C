#include "s21_string.h"

void *s21_to_lower(const char *str) {
  if (str == NULL) return NULL;
  s21_size_t size_str = s21_strlen(str);
  char *str_lower = (char *)malloc((size_str + 1) * sizeof(char));
  if (str_lower) {
    char ch_lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                       'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                       's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    char ch_upper[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
                       'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                       'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    s21_size_t i = 0;
    for (; i < size_str; ++i) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        for (int j = 0; j < 26; ++j) {
          if (str[i] == ch_upper[j]) {
            str_lower[i] = ch_lower[j];
          }
        }
      } else {
        str_lower[i] = str[i];
      }
    }
    str_lower[i] = '\0';
  }
  return (void *)str_lower;
}
