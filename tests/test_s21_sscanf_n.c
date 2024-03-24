#include "imit_test.h"

START_TEST(imit_sscanf_test_26_hard_option) {
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
  int32_t n1 = 0, n2 = 0;

  const char str[] = "123123SkipMePlease!!!!123";
  const char fstr[] = "%d %d %n";

  int16_t res1 = imit_sscanf(str, fstr, &a1, &a3, &n1);
  int16_t res2 = sscanf(str, fstr, &a2, &a4, &n2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(a3, a4);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(imit_sscanf_test_27_hard_option) {
  int32_t a1, a2;
  int32_t b1 = 0, b2 = 0;
  const char str[] = "12keppa12";
  const char fstr[] = "%d %d";
  int32_t res1 = imit_sscanf(str, fstr, &a1, &b1);
  int32_t res2 = sscanf(str, fstr, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(imit_sscanf_test_23_n_option) {
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int n1 = 0;
  int n2 = 0;
  int result1 = imit_sscanf("10     20", "%d %n%d", &a, &n1, &b);
  int result2 = sscanf("10     20", "%d %n%d", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = imit_sscanf("10     20", "%d%n%d", &a, &n1, &b);
  result2 = sscanf("10     20", "%d%n%d", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = imit_sscanf("10     20", "%n%d%d", &a, &n1, &b);
  result2 = sscanf("10     20", "%n%d%d", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = imit_sscanf("  10     20", "%n%d%d", &a, &n1, &b);
  result2 = sscanf("  10     20", "%n%d%d", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = imit_sscanf("10     20  ", "%d%d%n", &a, &n1, &b);
  result2 = sscanf("10     20  ", "%d%d%n", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  a = 0;
  b = 0;
  c = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  result1 = imit_sscanf("10     20  ", "%d%d %n", &a, &n1, &b);
  result2 = sscanf("10     20  ", "%d%d %n", &c, &n2, &d);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);

  short a1 = 0;
  b = 0;
  short c1 = 0;
  d = 0;
  n1 = 0;
  n2 = 0;
  n1 = 0;
  n2 = 0;
  result1 = imit_sscanf("10     20  ", "%hn%d%d", &a1, &n1, &b);
  result1 = sscanf("10     20  ", "%hn%d%d", &c1, &n2, &d);
  ck_assert_int_eq(a1, c1);
  ck_assert_int_eq(b, d);
  ck_assert_int_eq(result1, result2);
}
END_TEST

Suite *suite_sscanf_n(void) {
  Suite *s = suite_create("imit_sscanf_n");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, imit_sscanf_test_26_hard_option);
  tcase_add_test(tc, imit_sscanf_test_27_hard_option);
  tcase_add_test(tc, imit_sscanf_test_23_n_option);

  suite_add_tcase(s, tc);
  return s;
}
