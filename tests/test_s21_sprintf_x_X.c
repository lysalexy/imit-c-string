#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sprintf_x1_test) {
  char imit_result[100];
  char result[100];
  char *format = "%x";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_x2_test) {
  char imit_result[100];
  char result[100];
  char *format = "%x";
  // char *format2 = "%d";
  int dec = 99;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_x_whitespace_test) {
  char imit_result[100];
  char result[100];
  char *format = "% x";
  // char *format2 = "%d";
  int dec = 99;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_x_precision1_test) {
  char imit_result[100];
  char result[100];
  char *format = "%.9x";
  // char *format2 = "%d";
  int dec = 47;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_x_precision2_test) {
  char imit_result[100];
  char result[100];
  char *format = "%.2x";
  // char *format2 = "%d";
  int dec = 47;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_x_precision3_test) {
  char imit_result[100];
  char result[100];
  char *format = "%.12x";
  // char *format2 = "%d";
  int dec = 47;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_x_precision4_test) {
  char imit_result[100];
  char result[100];
  char *format = "%.-2x";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_X1_test) {
  char imit_result[100];
  char result[100];
  char *format = "%X";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_X2_test) {
  char imit_result[100];
  char result[100];
  char *format = "%X";
  // char *format2 = "%d";
  int dec = 99;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_X_whitespace_test) {
  char imit_result[100];
  char result[100];
  char *format = "% X";
  // char *format2 = "%d";
  int dec = 99;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_X_precision1_test) {
  char imit_result[100];
  char result[100];
  char *format = "%.9X";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_X_precision2_test) {
  char imit_result[100];
  char result[100];
  char *format = "%.2X";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_X_precision3_test) {
  char imit_result[100];
  char result[100];
  char *format = "%.16X";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_X_precision4_test) {
  char imit_result[100];
  char result[100];
  char *format = "%.-16X";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

Suite *test_imit_sprintf_x_X_suite() {
  Suite *suite = suite_create("imit_sprintf_x_X");
  TCase *t_case = tcase_create("imit_sprintf_x_X");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_sprintf_x1_test);
  tcase_add_test(t_case, imit_sprintf_x2_test);
  tcase_add_test(t_case, imit_sprintf_x_whitespace_test);
  tcase_add_test(t_case, imit_sprintf_x_precision1_test);
  tcase_add_test(t_case, imit_sprintf_x_precision2_test);
  tcase_add_test(t_case, imit_sprintf_x_precision3_test);
  tcase_add_test(t_case, imit_sprintf_x_precision4_test);

  tcase_add_test(t_case, imit_sprintf_X1_test);
  tcase_add_test(t_case, imit_sprintf_X2_test);
  tcase_add_test(t_case, imit_sprintf_X_whitespace_test);
  tcase_add_test(t_case, imit_sprintf_X_precision1_test);
  tcase_add_test(t_case, imit_sprintf_X_precision2_test);
  tcase_add_test(t_case, imit_sprintf_X_precision3_test);
  tcase_add_test(t_case, imit_sprintf_X_precision4_test);

  return suite;
}