#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sprintf_c_test) {
  char *string = "hello";
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %s";
  int imit_result_int = imit_sprintf(imit_result, format, string);
  int result_int = sprintf(result, format, string);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_c_test_null) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %s";
  int imit_result_int = imit_sprintf(imit_result, format, imit_NULL);
  int result_int = sprintf(result, format, imit_NULL);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

Suite *test_imit_sprintf_s_suite() {
  Suite *suite = suite_create("imit_sprintf_s");
  TCase *t_case = tcase_create("imit_sprintf_s");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_sprintf_c_test);
  tcase_add_test(t_case, imit_sprintf_c_test_null);

  return suite;
}