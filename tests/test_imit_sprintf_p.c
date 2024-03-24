#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sprintf_p1_test) {
  char imit_result[100];
  char result[100];
  char *format = "%p";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, &dec);
  int result_int = sprintf(result, format, &dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_p2_test) {
  char str1[100];
  char str2[100];

  char *format = "%p";
  ck_assert_int_eq(imit_sprintf(str1, format, format),
                   sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(imit_sprintf_p3_test) {
  char str1[100];
  char str2[100];

  char *format = "%p";
  char *ptr = ((void *)0);
  ck_assert_int_eq(imit_sprintf(str1, format, ptr), sprintf(str2, format, ptr));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_imit_sprintf_p_suite() {
  Suite *suite = suite_create("imit_sprintf_p");
  TCase *t_case = tcase_create("imit_sprintf_p");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_sprintf_p1_test);
  tcase_add_test(t_case, imit_sprintf_p2_test);
  tcase_add_test(t_case, imit_sprintf_p3_test);

  return suite;
}