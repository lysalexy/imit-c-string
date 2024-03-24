#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sprintf_n1_test) {
  char imit_result[100];
  char result[100];
  char *format = "How many chars written before %n";
  // int dec = 36;
  int ret = 0;
  int imit_result_int = imit_sprintf(imit_result, format, &ret);
  int result_int = sprintf(result, format, &ret);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_n2_test) {
  char imit_result[100];
  char result[100];
  int n1;
  int n2;
  int imit_result_int = imit_sprintf(imit_result, "%d%n", 12345, &n1);
  int result_int = sprintf(result, "%d%n", 12345, &n2);

  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_n3_test) {
  char imit_result[100];
  char result[100];
  int n1;
  int n2;
  int imit_result_int = imit_sprintf(imit_result, "%d%n", 1234567, &n1);
  int result_int = sprintf(result, "%d%n", 1234567, &n2);

  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_n4_test) {
  char str1[100];
  char str2[100];
  int ret = 0;
  char *format = "Hello, privet %n";
  ck_assert_int_eq(imit_sprintf(str1, format, &ret),
                   sprintf(str2, format, &ret));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_imit_sprintf_n_suite() {
  Suite *suite = suite_create("imit_sprintf_n");
  TCase *t_case = tcase_create("imit_sprintf_n");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_sprintf_n1_test);
  tcase_add_test(t_case, imit_sprintf_n2_test);
  tcase_add_test(t_case, imit_sprintf_n3_test);
  tcase_add_test(t_case, imit_sprintf_n4_test);

  return suite;
}
