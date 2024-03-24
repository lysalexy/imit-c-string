#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sprintf_g_f_is_shorter) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %g";
  int imit_result_int = imit_sprintf(imit_result, format, 0.0f);
  int result_int = sprintf(result, format, 0.0f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_g_not_rounding) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %g";
  int imit_result_int = imit_sprintf(imit_result, format, 1001.01f);
  int result_int = sprintf(result, format, 1001.01f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_g_not_rounding_neg) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %g";
  int imit_result_int = imit_sprintf(imit_result, format, -1001.01f);
  int result_int = sprintf(result, format, -1001.01f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_g_truncate) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %g";
  int imit_result_int = imit_sprintf(imit_result, format, 1001.011f);
  int result_int = sprintf(result, format, 1001.011f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_g_e_is_shorter) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %g";
  int imit_result_int = imit_sprintf(imit_result, format, 123456.654321f);
  int result_int = sprintf(result, format, 123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_g_e_is_shorter_neg) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %g";
  int imit_result_int = imit_sprintf(imit_result, format, -123456.654321f);
  int result_int = sprintf(result, format, -123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

Suite *test_imit_sprintf_g_G_suite() {
  Suite *suite = suite_create("imit_sprintf_g_G");
  TCase *t_case = tcase_create("imit_sprintf_g_G");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_sprintf_g_f_is_shorter);
  tcase_add_test(t_case, imit_sprintf_g_e_is_shorter);
  tcase_add_test(t_case, imit_sprintf_g_e_is_shorter_neg);

  tcase_add_test(t_case, imit_sprintf_g_not_rounding_neg);
  tcase_add_test(t_case, imit_sprintf_g_not_rounding);
  tcase_add_test(t_case, imit_sprintf_g_truncate);

  return suite;
}