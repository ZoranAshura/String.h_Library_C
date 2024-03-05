#include "s21_string.h"

sscanf_struct def_sscanf_struct() {
  return (sscanf_struct){false, PARAM_NONE, false, false, LENGTH_DEFAULT};
}

void clear_sscanf_struct(sscanf_struct* parameters) {
  parameters->trigger = false;
  parameters->width = PARAM_NONE;
  parameters->length = LENGTH_DEFAULT;
  parameters->ignore = false;
}

void specifiers_s(sscanf_struct* parameters, char sign, const char** sptr,
                  const char** str, const char** nptr, va_list ap, int* count,
                  int* flag) {
  switch (sign) {
    case 'c':;
      char symbol = '\0';
      *sptr = read_char(*sptr, &symbol, parameters);
      if (!parameters->ignore) {
        *(va_arg(ap, char*)) = symbol;
        *count += 1;
      }
      break;
    case 's':
      if (parameters->width == 0) parameters->width = PARAM_NONE;
      char* str_box = NULL;
      if (!parameters->ignore) str_box = va_arg(ap, char*);
      *sptr = read_str(*sptr, str_box, parameters);
      if (!parameters->ignore && !parameters->err) *count += 1;
      break;
    case 'd':
    case 'i':
      if (parameters->width == 0 || parameters->width == PARAM_NONE)
        parameters->width = 1000;
      int form = FORMAT_DECIMAL;
      if (sign == 'i' && (*sptr)[0] == '0') {
        if ((*sptr)[1] == 'x' || (*sptr)[1] == 'X')
          form = FORMAT_HEX;
        else
          form = FORMAT_OCTAL;
      }
      long long number_box = 0;
      *sptr = read_int(*sptr, &number_box, form, parameters);
      if (!parameters->ignore) {
        if (parameters->length == LENGTH_SHORT) {
          short* ptr = va_arg(ap, short*);
          *ptr = (short)number_box;
        } else if (parameters->length == LENGTH_LONG) {
          long* ptr = va_arg(ap, long*);
          *ptr = (long)number_box;
        } else {
          int* ptr = va_arg(ap, int*);
          *ptr = (int)number_box;
        }
      }
      if (!parameters->ignore && !parameters->err) *count += 1;
      break;
    case 'u':
    case 'x':
    case 'X':
    case 'o':
    case 'p':;
      if (parameters->width == 0 || parameters->width == PARAM_NONE)
        parameters->width = 1000;
      int forma = FORMAT_DECIMAL;
      if (sign == 'x' || sign == 'X' || sign == 'p')
        forma = FORMAT_HEX;
      else if (sign == 'o')
        forma = FORMAT_OCTAL;
      long long unum_box = 0;
      *sptr = read_int(*sptr, &unum_box, forma, parameters);
      if (!parameters->ignore) {
        if (parameters->length == LENGTH_SHORT) {
          unsigned short* apptr = va_arg(ap, unsigned short*);
          *apptr = unum_box;
        } else if (parameters->length == LENGTH_LONG) {
          unsigned long* apptr = va_arg(ap, unsigned long*);
          *apptr = unum_box;
        } else {
          unsigned int* apptr = va_arg(ap, unsigned int*);
          *apptr = unum_box;
        }
      }
      if (!parameters->ignore && !parameters->err) *count += 1;
      break;
    case 'e':
    case 'E':
    case 'g':
    case 'G':
    case 'f':;
      if (parameters->width == 0) parameters->width = PARAM_NONE;
      long double f_box = 0.0L;
      *sptr = read_float(*sptr, &f_box, parameters);
      if (!parameters->ignore) {
        if (parameters->length == LENGTH_LONG_DOUBLE) {
          long double* apptr = va_arg(ap, long double*);
          *apptr = (long double)f_box;
        } else if (parameters->length == LENGTH_LONG) {
          double* apptr = va_arg(ap, double*);
          *apptr = (double)f_box;
        } else {
          float* apptr = va_arg(ap, float*);
          *apptr = (float)f_box;
        }
      }
      if (!parameters->ignore && !parameters->err) *count += 1;
      break;
    case 'n':;
      int* argptr = va_arg(ap, int*);
      *argptr = *nptr - *str;
      break;
    default:
      *flag = 1;
      break;
  }
}

int s21_sscanf(const char* str, const char* format, ...) {
  va_list ap;
  va_start(ap, format);
  int count = 0;
  sscanf_struct parameters = def_sscanf_struct();
  const char* sptr = str;
  const char* nptr = NULL;
  int flag = 0;
  for (const char* fptr = format; *fptr != '\0' && count >= 0 && flag == 0;
       ++fptr) {
    char sign = *fptr;
    if (sign == '%') {
      parameters.trigger = true;
      nptr = sptr;
    } else if (parameters.trigger) {
      if (sign == 'h') {
        parameters.length = LENGTH_SHORT;
      } else if (sign == 'l') {
        parameters.length = LENGTH_LONG;
      } else if (sign == 'L') {
        parameters.length = LENGTH_LONG_DOUBLE;
      } else if (isdigit(sign)) {
        parameters.width = convert_int(&fptr);
      } else if (sign == PARAM_ARG) {
        parameters.ignore = true;
      } else {
        int flag_spec = 0;
        if (*sptr == '\0' && sign != 'n') {
          count = -1;
          flag_spec = 1;
        }
        if (!flag_spec) {
          specifiers_s(&parameters, sign, &sptr, &str, &nptr, ap, &count,
                       &flag);
          if (parameters.err && *sptr == '\0') {
            count = -1;
          }
          clear_sscanf_struct(&parameters);
        }
      }
    } else if (isspace(sign) && isspace(*sptr)) {
      while (*sptr != '\0' && isspace(*sptr)) sptr += 1;
    } else if (sign == *sptr) {
      sptr += 1;
    }
  }
  va_end(ap);
  return count;
}

const char* get_rid_of_space(const char* string) {
  while (*string != '\0' && isspace(*string)) string += 1;
  return string;
}

bool is_format_digit(char symbol, int format) {
  bool result = false;
  if (format <= FORMAT_DECIMAL) {
    result = symbol >= '0' && symbol <= ('0' + format - 1);
  } else {
    result = (symbol >= '0' && symbol <= '9') ||
             (symbol >= 'a' && symbol <= 'f') ||
             (symbol >= 'A' && symbol <= 'F');
  }
  return result;
}

int format_digit(char symbol) {
  int number = 0;
  if (symbol >= '0' && symbol <= '9') {
    number = symbol - '0';
  } else if (symbol >= 'a' && symbol <= 'f') {
    number = symbol - 'a' + 10;
  } else if (symbol >= 'A' && symbol <= 'F') {
    number = symbol - 'A' + 10;
  }
  return number;
}

const char* read_char(const char* string, char* cptr,
                      sscanf_struct* parameters) {
  *cptr = *string++;
  parameters->width -= 1;
  for (int i = 0; i < parameters->width && string[i] != '\0'; ++i) string += 1;
  return string;
}

const char* read_str(const char* string, char* sptr,
                     sscanf_struct* parameters) {
  string = get_rid_of_space(string);
  for (char c = *string;
       !isspace(c) && c != '\0' &&
       (parameters->width == PARAM_NONE || parameters->width > 0);
       c = *++string) {
    if (!parameters->ignore) *sptr = c;
    sptr += 1;
    if (parameters->width != PARAM_NONE) parameters->width -= 1;
  }
  if (!parameters->ignore) *sptr = '\0';
  return string;
}

const char* read_int(const char* string, long long* nptr, int format,
                     sscanf_struct* parameters) {
  string = get_rid_of_space(string);
  int sign = SIGN_PLUS;
  if (*string == '-') {
    sign = SIGN_MINUS;
    string += 1;
    parameters->width -= 1;
  } else if (*string == '+') {
    sign = SIGN_PLUS;
    string += 1;
    parameters->width -= 1;
  }
  if (parameters->width == 0 || !is_format_digit(*string, format))
    parameters->err = true;
  if (!parameters->err) {
    if (format == FORMAT_HEX && string[0] == '0' && string[1] == 'x' &&
        is_format_digit(string[2], format)) {
      parameters->width -= 2;
      string += 2;
    }
    long long nummber = 0;
    while (*string == '0') {
      string += 1;
      parameters->width -= 1;
    }
    while (is_format_digit(*string, format) && parameters->width > 0) {
      nummber += format_digit(*string);
      parameters->width -= 1;
      string += 1;
      if (is_format_digit(*string, format) && parameters->width > 0) {
        nummber *= format;
      }
    }
    if (sign == SIGN_MINUS) nummber = -nummber;
    *nptr = nummber;
  }
  return string;
}

const char* read_float(const char* string, long double* fptr,
                       sscanf_struct* parameters) {
  string = get_rid_of_space(string);
  int sign = SIGN_PLUS;
  if (*string == '-') {
    sign = SIGN_MINUS;
    string += 1;
  } else if (*string == '+') {
    sign = SIGN_PLUS;
    string += 1;
  }
  if (!isdigit(*string)) parameters->err = true;
  if (!parameters->err) {
    long double num = 0.0L;
    int expo = 0;
    bool floating_side = false;
    bool exit = false;
    while (!exit && parameters->width != 0) {
      if (!floating_side && *string == '.') {
        floating_side = true;
        num *= 10.0L;
        if (parameters->width != PARAM_NONE) {
          expo += 1;
          parameters->width -= 1;
        }
        string += 1;
      } else if (isdigit(*string)) {
        num += *string - '0';

        if (floating_side) expo += 1;
        if (parameters->width != PARAM_NONE) parameters->width -= 1;
        string += 1;
        if (isdigit(*string)) {
          num *= 10.0L;
        }
      } else {
        exit = true;
      }
    }
    for (int i = 0; i < expo; i++) num /= 10.0L;
    if (string[0] == 'e' || string[0] == 'E') {
      string += 1;
      int expo_sign = SIGN_PLUS;
      if (string[0] == '-' || string[0] == '+') {
        expo_sign = *string++ == '-' ? SIGN_MINUS : SIGN_PLUS;
      }
      if (!isdigit(string[0])) parameters->err = true;
      expo = convert_int(&string);
      if (expo_sign == SIGN_MINUS) expo = -expo;
      if (expo > 0) {
        for (int i = 0; i < expo; i++) num *= 10.0L;
      } else {
        for (int i = expo; i < 0; i++) num /= 10.0L;
      }
    }
    if (sign == SIGN_MINUS) num = -num;
    *fptr = num;
  }
  return string;
}