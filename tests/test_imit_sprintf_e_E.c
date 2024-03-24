#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sprintf_e_test_complex) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %e";
  int imit_result_int = imit_sprintf(imit_result, format, 123456.654321f);
  int result_int = sprintf(result, format, 123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_test_overflow_2) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %e";
  int imit_result_int = imit_sprintf(imit_result, format, 9.999999f);
  int result_int = sprintf(result, format, 9.999999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_test_zero_whole_part) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %e";
  int imit_result_int = imit_sprintf(imit_result, format, 0.001f);
  int result_int = sprintf(result, format, 0.001f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_test_zero) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %e";
  int imit_result_int = imit_sprintf(imit_result, format, 0.0f);
  int result_int = sprintf(result, format, 0.0f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_test_no_overflow) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %e";
  int imit_result_int = imit_sprintf(imit_result, format, 1000.0);
  int result_int = sprintf(result, format, 1000.0);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_test_negative) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %e";
  int imit_result_int = imit_sprintf(imit_result, format, -1000.0);
  int result_int = sprintf(result, format, -1000.0);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_test_int) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %e";
  int imit_result_int = imit_sprintf(imit_result, format, 1.90f);
  int result_int = sprintf(result, format, 1.90f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_test_int_overflow) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %e";
  int imit_result_int = imit_sprintf(imit_result, format, 10000000000000000.90);
  int result_int = sprintf(result, format, 10000000000000000.90);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_test_int_overflow_3) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %e";
  int imit_result_int = imit_sprintf(imit_result, format, 1.9999999f);
  int result_int = sprintf(result, format, 1.9999999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_E_test_complex) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %E";
  int imit_result_int = imit_sprintf(imit_result, format, 123456.654321f);
  int result_int = sprintf(result, format, 123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_E_test_overflow_2) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %E";
  int imit_result_int = imit_sprintf(imit_result, format, 9.999999f);
  int result_int = sprintf(result, format, 9.999999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_E_test_zero_whole_part) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %E";
  int imit_result_int = imit_sprintf(imit_result, format, 0.001f);
  int result_int = sprintf(result, format, 0.001f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_E_test_zero) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %E";
  int imit_result_int = imit_sprintf(imit_result, format, 0.0f);
  int result_int = sprintf(result, format, 0.0f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_E_test_no_overflow) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %E";
  int imit_result_int = imit_sprintf(imit_result, format, 1000.0);
  int result_int = sprintf(result, format, 1000.0);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_E_test_negative) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %E";
  int imit_result_int = imit_sprintf(imit_result, format, -1000.0);
  int result_int = sprintf(result, format, -1000.0);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_E_test_int) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %E";
  int imit_result_int = imit_sprintf(imit_result, format, 1.90f);
  int result_int = sprintf(result, format, 1.90f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_E_test_int_overflow) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %E";
  int imit_result_int = imit_sprintf(imit_result, format, 10000000000000000.90);
  int result_int = sprintf(result, format, 10000000000000000.90);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_E_test_int_overflow_3) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %E";
  int imit_result_int = imit_sprintf(imit_result, format, 1.9999999f);
  int result_int = sprintf(result, format, 1.9999999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

Suite *test_imit_sprintf_e_E_suite() {
  Suite *suite = suite_create("imit_sprintf_e");
  TCase *t_case = tcase_create("imit_sprintf_e");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_sprintf_e_test_no_overflow);
  tcase_add_test(t_case, imit_sprintf_e_test_negative);
  tcase_add_test(t_case, imit_sprintf_e_test_complex);
  tcase_add_test(t_case, imit_sprintf_e_test_zero_whole_part);
  tcase_add_test(t_case, imit_sprintf_e_test_zero);
  tcase_add_test(t_case, imit_sprintf_e_test_int_overflow);
  tcase_add_test(t_case, imit_sprintf_e_test_int);
  tcase_add_test(t_case, imit_sprintf_e_test_overflow_2);
  tcase_add_test(t_case, imit_sprintf_e_test_int_overflow_3);

  tcase_add_test(t_case, imit_sprintf_E_test_no_overflow);
  tcase_add_test(t_case, imit_sprintf_E_test_negative);
  tcase_add_test(t_case, imit_sprintf_E_test_complex);
  tcase_add_test(t_case, imit_sprintf_E_test_zero_whole_part);
  tcase_add_test(t_case, imit_sprintf_E_test_zero);
  tcase_add_test(t_case, imit_sprintf_E_test_int_overflow);
  tcase_add_test(t_case, imit_sprintf_E_test_int);
  tcase_add_test(t_case, imit_sprintf_E_test_overflow_2);
  tcase_add_test(t_case, imit_sprintf_E_test_int_overflow_3);

  return suite;
}