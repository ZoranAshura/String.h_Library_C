#include "s21_string_test.h"

START_TEST(s21_sscanf_test) {
  // %s specifier
  char a[100] = {0};
  char a1[100] = {0};
  char b[100] = {0};
  char b1[100] = {0};

  int result = 0;
  int s21_result = 0;

  s21_result = s21_sscanf("hello", "%s", a);
  result = sscanf("hello", "%s", a1);
  ck_assert_str_eq(a, a1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("  hello", "%s", a);
  result = sscanf("  hello", "%s", a1);
  ck_assert_str_eq(a, a1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("  hello  ", "%s", a);
  result = sscanf("  hello  ", "%s", a1);
  ck_assert_str_eq(a, a1);
  ck_assert_int_eq(result, s21_result);

  char y[100] = {0};
  char y1[100] = {0};
  s21_result = s21_sscanf("", "%s", y);
  result = sscanf("", "%s", y1);
  ck_assert_str_eq(y, y1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("   a", "%s", y);
  result = sscanf("   a", "%s", y1);
  ck_assert_str_eq(y, y1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("hello world", "%s %s", a, b);
  result = sscanf("hello world", "%s %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("    hello world", "%s %s", a, b);
  result = sscanf("   hello world", "%s %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("    hello world", "%4s %s", a, b);
  result = sscanf("   hello world", "%4s %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, s21_result);

  int n = 3;
  int n1 = 0;

  s21_result = s21_sscanf("    hello world", "%s %s", a, b);
  result = sscanf("   hello world", "%s %s", a1, b1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(result, s21_result);

  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("    hello world", "%s %s %n", a, b, &n);
  result = sscanf("    hello world", "%s %s %n", a1, b1, &n1);
  ck_assert_str_eq(a, a1);
  ck_assert_str_eq(b, b1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  // %d specifier

  int i = 1;
  int j = 1;
  s21_result = s21_sscanf("+184", "%d", &i);
  result = sscanf("+184", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  i = 1;
  j = 1;
  s21_result = s21_sscanf("-184", "%d", &i);
  result = sscanf("-184", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("184t", "%d", &i);
  result = sscanf("184t", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  i = 0;
  j = 0;
  s21_result = s21_sscanf("", "%d", &i);
  result = sscanf("", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("184h86", "%d", &i);
  result = sscanf("184h86", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("184   86", "%d", &i);
  result = sscanf("184   86", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("-184", "%d", &i);
  result = sscanf("-184", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf(" 56", "%d", &i);
  result = sscanf(" 56", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf(" -56 ", "%d", &i);
  result = sscanf(" -56 ", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("197856365839", "%d", &i);
  result = sscanf("197856365839", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("-197856365839", "%d", &i);
  result = sscanf("-197856365839", "%d", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("184h86", "%d %i", &i, &n);
  result = sscanf("184h86", "%d %i", &j, &n1);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  int i1 = 0;
  int j1 = 0;
  s21_result = s21_sscanf("3245 1322", "%d %d", &i, &j);
  result = sscanf("3245 1322", "%d %d", &i1, &j1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("3245;1322", "%d;%d", &i, &j);
  result = sscanf("3245;1322", "%d;%d", &i1, &j1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(result, s21_result);

  double ff = 0;
  double ff1 = 0;
  s21_result = s21_sscanf("3245;1322.33", "%d;%lf", &i, &ff);
  result = sscanf("3245;1322.33", "%d;%lf", &i1, &ff1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(ff, ff1);
  ck_assert_int_eq(result, s21_result);

  char x = ' ';
  char x1 = ' ';
  s21_result = s21_sscanf("r", "%% %c", &x);
  result = sscanf("r", "%% %c", &x1);
  ck_assert_int_eq(x, x1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("r", "%c %%", &x);
  result = sscanf("r", "%c %%", &x1);
  ck_assert_int_eq(x, x1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("3245 1322", "%2d %d", &i, &j);
  result = sscanf("3245 1322", "%2d %d", &i1, &j1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(result, s21_result);

  short int q = 0;
  short int w = 0;
  short int q1 = 0;
  short int w1 = 0;
  s21_result = s21_sscanf("3245 1322", "%hd %hd", &q, &w);
  result = sscanf("3245 1322", "%hd %hd", &q1, &w1);
  ck_assert_int_eq(q, q1);
  ck_assert_int_eq(w, w1);
  ck_assert_int_eq(result, s21_result);

  long int e = 0;
  long int r = 0;
  long int e1 = 0;
  long int r1 = 0;
  s21_result = s21_sscanf("3245 1322", "%ld %ld", &e, &r);
  result = sscanf("3245 1322", "%ld %ld", &e1, &r1);
  ck_assert_int_eq(e, e1);
  ck_assert_int_eq(r, r1);
  ck_assert_int_eq(result, s21_result);

  // %i specifier

  int d = 0;
  int d1 = 0;
  s21_result = s21_sscanf("3245", "%i", &d);
  result = sscanf("3245", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("075", "%i", &d);
  result = sscanf("075", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("075", "%i", &d);
  result = sscanf("61", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0x342", "%i", &d);
  result = sscanf("834", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("834", "%i", &d);
  result = sscanf("834", "%i", &d1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  i = 0;
  j = 0;
  s21_result = s21_sscanf("", "%i", &i);
  result = sscanf("", "%i", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf(" ", "%i", &i);
  result = sscanf(" ", "%i", &j);
  ck_assert_int_eq(i, j);
  ck_assert_int_eq(result, s21_result);

  int t = 0;
  int t1 = 0;

  s21_result = s21_sscanf("834 0x45", "%i %i", &d, &t);
  result = sscanf("834 0x45", "%i %i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(t, t1);
  ck_assert_int_eq(result, s21_result);

  t = 0;
  t1 = 0;
  s21_result = s21_sscanf("834 0x45", "%i %i", &d, &t);
  result = sscanf("834 0x45", "%i %i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(t, t1);
  ck_assert_int_eq(result, s21_result);

  d = 0;
  d1 = 0;
  t = 0;
  t1 = 0;
  s21_result = s21_sscanf("d834 0x45", "%i %i", &d, &t);
  result = sscanf("d834 0x45", "%i %i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(t, t1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("234 0x837", "%i %2i", &d, &t);
  result = sscanf("234 0x837", "%i %2i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("234 0x837", "%1i %2i", &d, &t);
  result = sscanf("234 0x837", "%1i %2i", &d1, &t1);
  ck_assert_int_eq(d, d1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("3245 1322", "%hi %hi", &q, &w);
  result = sscanf("3245 1322", "%hi %hi", &q1, &w1);
  ck_assert_int_eq(q, q1);
  ck_assert_int_eq(w, w1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("035 1322", "%hi %hi", &q, &w);
  result = sscanf("035 1322", "%hi %hi", &q1, &w1);
  ck_assert_int_eq(q, q1);
  ck_assert_int_eq(w, w1);
  ck_assert_int_eq(result, s21_result);

  r = 0;
  r1 = 0;
  s21_result = s21_sscanf("035 132264782398", "%li %li", &e, &r);
  result = sscanf("035 132264782398", "%li %li", &e1, &r1);
  ck_assert_int_eq(e, e1);
  ck_assert_int_eq(r, r1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("035 1322", "%li %hi", &e, &q);
  result = sscanf("035 1322", "%li %hi", &e1, &q1);
  ck_assert_int_eq(e, e1);
  ck_assert_int_eq(q, q1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("035 0x2846", "%i %i %n", &i, &j, &n);
  result = sscanf("035 0x2846", "%i %i %n", &i1, &j1, &n1);
  ck_assert_int_eq(i, i1);
  ck_assert_int_eq(j, j1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  // %c specifier

  char c = 0;
  char c1 = 0;
  s21_result = s21_sscanf("h", "%c", &c);
  result = sscanf("h", "%c", &c1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("gh", "%c", &c);
  result = sscanf("gh", "%c", &c1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("  gh", "%c", &c);
  result = sscanf("  gh", "%c", &c1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("g h", "%c", &c);
  result = sscanf("g h", "%c", &c1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(result, s21_result);

  char c2;
  char c3;
  s21_result = s21_sscanf("a h   ", "%c %c %n", &c, &c2, &n);
  result = sscanf("a h   ", "%c %c %n", &c1, &c3, &n1);
  // n = 5;
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(c2, c3);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  c2 = 0;
  c3 = 0;
  s21_result = s21_sscanf("g h", "%c%c %n", &c, &c2, &n);
  result = sscanf("g h", "%c%c %n", &c1, &c3, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(c2, c3);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  c2 = 0;
  c3 = 0;
  s21_result = s21_sscanf("g  h", "%c %c %n", &c, &c2, &n);
  result = sscanf("g  h", "%c %c %n", &c1, &c3, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(c2, c3);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  wchar_t m = 0;
  wchar_t m1 = 0;
  s21_result = s21_sscanf("h", "%lc", &m);
  result = sscanf("h", "%lc", &m1);
  ck_assert_int_eq(m, m1);
  ck_assert_int_eq(result, s21_result);

  char k = 0;
  char k1 = 0;
  s21_result = s21_sscanf("g h", "%c %c %n", &c, &k, &n);
  result = sscanf("g h", "%c %c %n", &c1, &k1, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(k, k1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("..", "%c %c %n", &c, &k, &n);
  result = sscanf("..", "%c %c %n", &c1, &k1, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(k, k1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("h 6", "%c %*c %n", &c, &n);
  result = sscanf("h 6", "%c %*c %n", &c1, &n1);
  ck_assert_int_eq(c, c1);
  ck_assert_int_eq(n, n1);
  ck_assert_int_eq(result, s21_result);

  // %% specifier
  c = 0;
  c1 = 0;
  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("h 6", "%% %n", &n);
  result = sscanf("h 6", "%% %n", &n1);
  ck_assert_int_eq(result, s21_result);

  // %p specifier
  int val = 123;
  char buf[100] = {0};
  sprintf(buf, "%p", (void *)&val);
  void *ptr = 0;
  void *ptr2 = 0;
  sscanf(buf, "%p", &ptr);
  s21_sscanf(buf, "%p", &ptr2);
  // ck_assert_ptr_eq(ptr, ptr2);

  // %e %E %f %g %G specifiers

  float f = 0;
  float dd = 0;
  float f1 = 0;
  float dd1 = 0;

  // scientific notation

  s21_result = s21_sscanf("127564.3846 1.275643846e3", "%e %e", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%e %e", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 1.275643846e3", "%E %E", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%E %E", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 1.275643846e3", "%f %f", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%f %f", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 1.275643846e3", "%g %g", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%g %g", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 1.275643846e3", "%G %G", &f, &dd);
  result = sscanf("127564.3846 1.275643846e3", "%G %G", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  // negative scientific notation

  s21_result = s21_sscanf("127564.3846 12756.43846e-3", "%e %e", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%e %e", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 12756.43846e-3", "%E %E", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%E %E", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 12756.43846e-3", "%f %f", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%f %f", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 12756.43846e-3", "%g %g", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%g %g", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("127564.3846 12756.43846e-3", "%G %G", &f, &dd);
  result = sscanf("127564.3846 12756.43846e-3", "%G %G", &f1, &dd1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);

  // basic
  s21_result = s21_sscanf("0.008726", "%e", &f);
  result = sscanf("0.008726", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%E", &f);
  result = sscanf("0.008726", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%f", &f);
  result = sscanf("0.008726", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("+0.008726", "%f", &f);
  result = sscanf("+0.008726", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("+5.5", "%f", &f);
  result = sscanf("+5.5", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%g", &f);
  result = sscanf("0.008726", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%G", &f);
  result = sscanf("0.008726", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  // negative numbers

  s21_result = s21_sscanf("-0.008726", "%e", &f);
  result = sscanf("-0.008726", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("-0.008726", "%E", &f);
  result = sscanf("-0.008726", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("-0.008726", "%f", &f);
  result = sscanf("-0.008726", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("-0.008726", "%g", &f);
  result = sscanf("-0.008726", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("-0.008726", "%G", &f);
  result = sscanf("-0.008726", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  // spaces at the beginning
  s21_result = s21_sscanf("   0.008726", "%e", &f);
  result = sscanf("   0.008726", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("   0.008726", "%E", &f);
  result = sscanf("   0.008726", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("  0.008726", "%f", &f);
  result = sscanf("   0.008726", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("   0.008726", "%g", &f);
  result = sscanf("   0.008726", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("   0.008726", "%G", &f);
  result = sscanf("   0.008726", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  // spaces
  f = 0;
  f1 = 0;
  s21_result = s21_sscanf("   ", "%e", &f);
  result = sscanf("   ", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  f = 0;
  f1 = 0;
  s21_result = s21_sscanf("   ", "%E", &f);
  result = sscanf("   ", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  f = 0;
  f1 = 0;
  s21_result = s21_sscanf("   ", "%f", &f);
  result = sscanf("   ", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  f = 0;
  f1 = 0;
  s21_result = s21_sscanf("   ", "%g", &f);
  result = sscanf("   ", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  f = 0;
  f1 = 0;
  s21_result = s21_sscanf("   ", "%G", &f);
  result = sscanf("   ", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  // empty lines
  s21_result = s21_sscanf("", "%e", &f);
  result = sscanf("", "%e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("", "%E", &f);
  result = sscanf("", "%E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("", "%f", &f);
  result = sscanf("", "%f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("", "%g", &f);
  result = sscanf("", "%g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("", "%G", &f);
  result = sscanf("", "%G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  // width
  s21_result = s21_sscanf("0.008726", "%6e", &f);
  result = sscanf("0.008726", "%6e", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%4E", &f);
  result = sscanf("0.008726", "%4E", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%4f", &f);
  result = sscanf("0.008726", "%4f", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%4g", &f);
  result = sscanf("0.008726", "%4g", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("0.008726", "%4G", &f);
  result = sscanf("0.008726", "%4G", &f1);
  ck_assert_float_eq(f, f1);
  ck_assert_int_eq(result, s21_result);

  // length L
  long double lf = 0;
  long double lf1 = 0;
  s21_result = s21_sscanf("9.9996587169235770324564357345", "%Le", &lf);
  result = sscanf("9.9996587169235770324564357345", "%Le", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%LE", &lf);
  result = sscanf("9.9996587169235770324564357345", "%LE", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%Lf", &lf);
  result = sscanf("9.9996587169235770324564357345", "%Lf", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%Lg", &lf);
  result = sscanf("9.9996587169235770324564357345", "%Lg", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%LG", &lf);
  result = sscanf("9.9996587169235770324564357345", "%LG", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  // length L + width
  s21_result = s21_sscanf("9.9996587169235770324564357345", "%4Le", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4Le", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%4LE", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4LE", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%4Lf", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4Lf", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%4Lg", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4Lg", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  s21_result = s21_sscanf("9.9996587169235770324564357345", "%4LG", &lf);
  result = sscanf("9.9996587169235770324564357345", "%4LG", &lf1);
  ck_assert_ldouble_eq(lf, lf1);
  ck_assert_int_eq(result, s21_result);

  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("1275.3846 0.2345", "%e %e %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%e %e %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);
  ck_assert_int_eq(n, n1);

  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("1275.3846 0.2345", "%E %E %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%E %E %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);
  ck_assert_int_eq(n, n1);

  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("1275.3846 0.2345", "%f %f %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%f %f %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);
  ck_assert_int_eq(n, n1);

  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("1275.3846 0.2345", "%g %g %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%g %g %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);
  ck_assert_int_eq(n, n1);

  n = 0;
  n1 = 0;
  s21_result = s21_sscanf("1275.3846 0.2345", "%G %G %n", &f, &dd, &n);
  result = sscanf("1275.3846 0.2345", "%G %G %n", &f1, &dd1, &n1);
  ck_assert_float_eq(f, f1);
  ck_assert_float_eq(dd, dd1);
  ck_assert_int_eq(result, s21_result);
  ck_assert_int_eq(n, n1);
}
END_TEST

START_TEST(s21_sscanf_u_test) {
  int res = 0;
  int s21_res = 0;
  int d = 0;
  unsigned int u = 0;
  unsigned short int hu = 0;
  unsigned long int lu = 0;
  int s21_d = 0;
  unsigned int s21_u = 0;
  unsigned short int s21_hu = 0;
  unsigned long int s21_lu = 0;

  s21_res = s21_sscanf("184", "%u", &s21_u);
  res = sscanf("184", "%u", &u);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-184", "%u", &s21_u);
  res = sscanf("-184", "%u", &u);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("184.01", "%u", &s21_u);
  res = sscanf("184.01", "%u", &u);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-184.01", "%u", &s21_u);
  res = sscanf("-184.01", "%u", &u);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("184", "%hu", &s21_hu);
  res = sscanf("184", "%hu", &hu);
  ck_assert_uint_eq(hu, s21_hu);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-184", "%hu", &s21_hu);
  res = sscanf("-184", "%hu", &hu);
  ck_assert_uint_eq(hu, s21_hu);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("184.01", "%hu", &s21_hu);
  res = sscanf("184.01", "%hu", &hu);
  ck_assert_uint_eq(hu, s21_hu);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-184.01", "%hu", &s21_hu);
  res = sscanf("-184.01", "%hu", &hu);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("184", "%u", &s21_d);
  res = sscanf("184", "%u", &d);
  ck_assert_int_eq(d, s21_d);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-184", "%u", &s21_d);
  res = sscanf("-184", "%u", &d);
  ck_assert_int_eq(d, s21_d);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("184.01", "%u", &s21_d);
  res = sscanf("184.01", "%u", &d);
  ck_assert_int_eq(d, s21_d);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-184.01", "%u", &s21_d);
  res = sscanf("-184.01", "%u", &d);
  ck_assert_int_eq(d, s21_d);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("  1   184", "%u", &s21_u);
  res = sscanf("  1   184", "%u", &u);
  ck_assert_uint_eq(d, s21_d);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("98975878579879184", "%lu", &s21_lu);
  res = sscanf("98975878579879184", "%lu", &lu);
  ck_assert_uint_eq(lu, s21_lu);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("184.01", "%lu", &s21_lu);
  res = sscanf("184.01", "%lu", &lu);
  ck_assert_uint_eq(lu, s21_lu);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-184.01", "%lu", &s21_lu);
  res = sscanf("-184.01", "%lu", &lu);
  ck_assert_uint_eq(lu, s21_lu);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("     184 1    ", "%lu", &s21_lu);
  res = sscanf("184", "%lu", &lu);
  ck_assert_uint_eq(lu, s21_lu);
  ck_assert_int_eq(res, s21_res);

  u = 0;
  s21_u = 0;

  s21_res = s21_sscanf("", "%u", &s21_u);
  res = sscanf("", "%u", &u);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_int_eq(res, s21_res);

  u = 0;
  s21_u = 0;

  s21_res = s21_sscanf("    ", "%u", &s21_u);
  res = sscanf("    ", "%u", &u);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_int_eq(res, s21_res);

  unsigned int u2 = 0;
  unsigned int s21_u2 = 0;
  unsigned int u3 = 0;
  unsigned int s21_u3 = 0;
  s21_res =
      s21_sscanf("184 184.99 -5637", "%u %u %u", &s21_u, &s21_u2, &s21_u3);
  res = sscanf("184 184.99 -5637", "%u %u %u", &u, &u2, &u3);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_uint_eq(u2, s21_u2);
  ck_assert_uint_eq(u3, s21_u3);
  ck_assert_int_eq(res, s21_res);

  int n = 0;
  int s21_n = 0;
  s21_res = s21_sscanf("184     -5637  0", "%u %u %u %n", &s21_u, &s21_u2,
                       &s21_u3, &s21_n);
  res = sscanf("184     -5637  0", "%u %u %u %n", &u, &u2, &u3, &n);
  ck_assert_uint_eq(u, s21_u);
  ck_assert_uint_eq(u2, s21_u2);
  ck_assert_uint_eq(u3, s21_u3);
  ck_assert_int_eq(n, s21_n);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_sscanf_o_test) {
  int res = 0;
  int s21_res = 0;

  unsigned int o = 0;
  unsigned short int ho = 0;
  unsigned long int lo = 0;

  unsigned int s21_o = 0;
  unsigned short int s21_ho = 0;
  unsigned long int s21_lo = 0;

  s21_res = s21_sscanf("0184", "%o", &s21_o);
  res = sscanf("0184", "%o", &o);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0184", "%o", &s21_o);
  res = sscanf("-0184", "%o", &o);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0184.345", "%o", &s21_o);
  res = sscanf("0184.345", "%o", &o);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0184.345", "%o", &s21_o);
  res = sscanf("-0184.345", "%o", &o);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("   0184", "%o", &s21_o);
  res = sscanf("   0184", "%o", &o);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("", "%o", &s21_o);
  res = sscanf("", "%o", &o);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_int_eq(res, s21_res);

  o = 0;
  s21_o = 0;
  s21_res = s21_sscanf("   ", "%o", &s21_o);
  res = sscanf("   ", "%o", &o);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0184", "%ho", &s21_ho);
  res = sscanf("0184", "%ho", &ho);
  ck_assert_uint_eq(ho, s21_ho);
  ck_assert_int_eq(res, s21_res);

  s21_ho = 0;
  ho = 0;
  s21_res = s21_sscanf("-0184", "%ho", &s21_ho);
  res = sscanf("-0184", "%ho", &ho);
  ck_assert_uint_eq(ho, s21_ho);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("   0184", "%ho", &s21_ho);
  res = sscanf("   0184", "%ho", &ho);
  ck_assert_uint_eq(ho, s21_ho);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0184.345", "%ho", &s21_ho);
  res = sscanf("0184.345", "%ho", &ho);
  ck_assert_uint_eq(ho, s21_ho);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("096787987989184456768768564767", "%lo", &s21_lo);
  res = sscanf("096787987989184456768768564767", "%lo", &lo);
  ck_assert_uint_eq(lo, s21_lo);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-096787987989184456768768564767", "%lo", &s21_lo);
  res = sscanf("-096787987989184456768768564767", "%lo", &lo);
  ck_assert_uint_eq(lo, s21_lo);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("   096787987989184456768768564767", "%lo", &s21_lo);
  res = sscanf("   096787987989184456768768564767", "%lo", &lo);
  ck_assert_uint_eq(lo, s21_lo);
  ck_assert_int_eq(res, s21_res);

  s21_res =
      s21_sscanf("   096787987989184456768768564767.34546", "%lo", &s21_lo);
  res = sscanf("   096787987989184456768768564767.34546", "%lo", &lo);
  ck_assert_uint_eq(lo, s21_lo);
  ck_assert_int_eq(res, s21_res);

  o = 0;
  unsigned int o2 = 0;
  unsigned int o3 = 0;
  s21_o = 0;
  unsigned int s21_o2 = 0;
  unsigned int s21_o3 = 0;
  int n = 0;
  int n2 = 0;

  // n == 0, n2 == 2
  o = 0;
  o2 = 0;
  o3 = 0;
  s21_o = 0;
  s21_o2 = 0;
  s21_o3 = 0;
  n = 0;
  n2 = 0;
  s21_res = s21_sscanf("0184 0234 06432", "%o %o %o %n", &s21_o, &s21_o2,
                       &s21_o3, &n2);
  res = sscanf("0184 0234 06432", "%o %o %o %n", &o, &o2, &o3, &n);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_uint_eq(o2, s21_o2);
  ck_assert_uint_eq(o3, s21_o3);
  ck_assert_int_eq(res, s21_res);
  // ck_assert_int_eq(n, n2);

  o = 0;
  o2 = 0;
  o3 = 0;
  s21_o = 0;
  s21_o2 = 0;
  s21_o3 = 0;
  n = 0;
  n2 = 0;
  s21_res = s21_sscanf("0184 0234 06432", "%o %*o %o %n", &s21_o, &s21_o2, &n2);
  res = sscanf("0184 0234 06432", "%o %*o %o %n", &o, &o2, &n);
  ck_assert_uint_eq(o, s21_o);
  ck_assert_uint_eq(o2, s21_o2);
  ck_assert_uint_eq(o3, s21_o3);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_sscanf_x_X_test) {
  int res = 0;
  int s21_res = 0;

  unsigned int x = 0;
  unsigned short int hx = 0;
  unsigned long int lx = 0;

  unsigned int s21_x = 0;
  unsigned short int s21_hx = 0;
  unsigned long int s21_lx = 0;

  s21_res = s21_sscanf("0x0x234", "%x", &s21_x);
  res = sscanf("0x0x234", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234", "%x", &s21_x);
  res = sscanf("0x234", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234", "%X", &s21_x);
  res = sscanf("0x234", "%X", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("3b856", "%x", &s21_x);
  res = sscanf("3b856", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("32856f", "%X", &s21_x);
  res = sscanf("32856f", "%X", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x23g4", "%x", &s21_x);
  res = sscanf("0x23g4", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x23g4", "%X", &s21_x);
  res = sscanf("0x23g4", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x2r3g4", "%x", &s21_x);
  res = sscanf("0x2r3g4", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x2r3g4", "%X", &s21_x);
  res = sscanf("0x2r3g4", "%X", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0x234", "%x", &s21_x);
  res = sscanf("-0x234", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0x234", "%X", &s21_x);
  res = sscanf("-0x234", "%X", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("   0x234", "%x", &s21_x);
  res = sscanf("   0x234", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("   0x234", "%X", &s21_x);
  res = sscanf("   0x234", "%X", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  x = 0;
  s21_x = 0;
  s21_res = s21_sscanf("   ", "%x", &s21_x);
  res = sscanf("   ", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  x = 0;
  s21_x = 0;
  s21_res = s21_sscanf("   ", "%X", &s21_x);
  res = sscanf("   ", "%X", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  x = 0;
  s21_x = 0;
  s21_res = s21_sscanf("", "%x", &s21_x);
  res = sscanf("", "%x", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  x = 0;
  s21_x = 0;
  s21_res = s21_sscanf("", "%X", &s21_x);
  res = sscanf("", "%X", &x);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234356768678", "%lx", &s21_lx);
  res = sscanf("0x234356768678", "%lx", &lx);
  ck_assert_uint_eq(lx, s21_lx);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234356768678", "%lX", &s21_lx);
  res = sscanf("0x234356768678", "%lX", &lx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0x234356768678", "%lx", &s21_lx);
  res = sscanf("-0x234356768678", "%lx", &lx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0x234356768678", "%lX", &s21_lx);
  res = sscanf("-0x234356768678", "%lX", &lx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("234356768678", "%lx", &s21_lx);
  res = sscanf("234356768678", "%lx", &lx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("234356768678", "%lX", &s21_lx);
  res = sscanf("234356768678", "%lX", &lx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234356768678", "%hx", &s21_hx);
  res = sscanf("0x234356768678", "%hx", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234356768678", "%hX", &s21_hx);
  res = sscanf("0x234356768678", "%hX", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234", "%hx", &s21_hx);
  res = sscanf("0x234", "%hx", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("0x234", "%hX", &s21_hx);
  res = sscanf("0x234", "%hX", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0x234", "%hx", &s21_hx);
  res = sscanf("-0x234", "%hx", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("-0x234", "%hX", &s21_hx);
  res = sscanf("-0x234", "%hX", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("234", "%hx", &s21_hx);
  res = sscanf("234", "%hx", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  s21_res = s21_sscanf("234", "%hX", &s21_hx);
  res = sscanf("234", "%hX", &hx);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_int_eq(res, s21_res);

  x = 0;
  unsigned int x2 = 0;
  unsigned int x3 = 0;
  s21_x = 0;
  unsigned int s21_x2 = 0;
  unsigned int s21_x3 = 0;

  s21_res = s21_sscanf("234 0x3543 3D", "%x %x %x", &s21_x, &s21_x2, &s21_x3);
  res = sscanf("234 0x3543 3D", "%x %x %x", &x, &x2, &x3);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_uint_eq(x2, s21_x2);
  ck_assert_uint_eq(x3, s21_x3);
  ck_assert_int_eq(res, s21_res);

  x = 0;
  x2 = 0;
  x3 = 0;
  s21_x = 0;
  s21_x2 = 0;
  s21_x3 = 0;

  s21_res = s21_sscanf("234 0x3543 3D", "%x %x %x", &s21_x, &s21_x2, &s21_x3);
  res = sscanf("234 0x3543 3D", "%x %x %x", &x, &x2, &x3);
  ck_assert_uint_eq(x, s21_x);
  ck_assert_uint_eq(x2, s21_x2);
  ck_assert_uint_eq(x3, s21_x3);
  ck_assert_int_eq(res, s21_res);
}
END_TEST

Suite *test_sscanf(void) {
  Suite *s = suite_create("s21_sscanf");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, s21_sscanf_test);
  tcase_add_test(tc, s21_sscanf_u_test);
  tcase_add_test(tc, s21_sscanf_o_test);
  tcase_add_test(tc, s21_sscanf_x_X_test);

  suite_add_tcase(s, tc);
  return s;
}