#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sprintf_o1_test) {
  char imit_result[100];
  char result[100];
  char *format = "%o";
  int dec = 36;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_o2_test) {
  char imit_result[100];
  char result[100];
  char *format = "%o %o %o %o";
  int imit_result_int = imit_sprintf(imit_result, format, 100, 50, 100, 9);
  int result_int = sprintf(result, format, 100, 50, 100, 9);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_o3_test) {
  char imit_result[100];
  char result[100];
  char *format = "%o";
  for (int i = 0; i < 200; i++) {
    int imit_result_int = imit_sprintf(imit_result, format, i);
    int result_int = sprintf(result, format, i);
    ck_assert_str_eq(imit_result, result);
    ck_assert_int_eq(imit_result_int, result_int);
  }
}
END_TEST

START_TEST(imit_sprintf_o_precision1_test) {
  char imit_result[100];
  char result[100];
  char *format = "%.3o";
  int dec = 36379;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_o_precision2_test) {
  char imit_result[100];
  char result[100];
  char *format = "%.2o %.4o %.3o %.12o";
  int imit_result_int =
      imit_sprintf(imit_result, format, 1000003, 50467788, 1002233788, 95675757);
  int result_int =
      sprintf(result, format, 1000003, 50467788, 1002233788, 95675757);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_o_whitespace1_test) {
  char imit_result[100];
  char result[100];
  char *format = "% o";
  int dec = 36;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_o_whitespace2_test) {
  char imit_result[100];
  char result[100];
  char *format = "% o % o % o % o";
  int imit_result_int = imit_sprintf(imit_result, format, 100, 50, 100, 9);
  int result_int = sprintf(result, format, 100, 50, 100, 9);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

Suite *test_imit_sprintf_o_suite() {
  Suite *suite = suite_create("imit_sprintf_o");
  TCase *t_case = tcase_create("imit_sprintf_o");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_sprintf_o1_test);
  tcase_add_test(t_case, imit_sprintf_o2_test);
  tcase_add_test(t_case, imit_sprintf_o3_test);
  tcase_add_test(t_case, imit_sprintf_o_precision1_test);
  tcase_add_test(t_case, imit_sprintf_o_precision2_test);
  tcase_add_test(t_case, imit_sprintf_o_whitespace1_test);
  tcase_add_test(t_case, imit_sprintf_o_whitespace2_test);

  return suite;
}