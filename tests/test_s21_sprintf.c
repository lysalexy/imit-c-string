#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sprintf_c_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %c";
  int imit_result_int = imit_sprintf(imit_result, format, '!');
  int result_int = sprintf(result, format, '!');

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_c_test_several) {
  char imit_result[50];
  char result[50];
  char format[50] = "%c Hello %c world %c";
  char a = 'a';
  char b = ',';
  char c = '!';
  int imit_result_int = imit_sprintf(imit_result, format, a, b, c);
  int result_int = sprintf(result, format, a, b, c);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_c_test_without_space) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world%c";
  int imit_result_int = imit_sprintf(imit_result, format, "!");
  int result_int = sprintf(result, format, "!");

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_c_test_end) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello%c";
  int imit_result_int = imit_sprintf(imit_result, format, "\0");
  int result_int = sprintf(result, format, "\0");

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_c_test_null) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello%c";
  int imit_result_int = imit_sprintf(imit_result, format, imit_NULL);
  int result_int = sprintf(result, format, imit_NULL);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_d_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "%d";
  int n = 21;
  int imit_result_int = imit_sprintf(imit_result, format, n);
  int result_int = sprintf(result, format, n);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_d_test_minus) {
  char imit_result[50];
  char result[50];
  char format[50] = "%d";
  int n = -21;
  int imit_result_int = imit_sprintf(imit_result, format, n);
  int result_int = sprintf(result, format, n);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_d_test_null) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello%d";
  int imit_result_int = imit_sprintf(imit_result, format, imit_NULL);
  int result_int = sprintf(result, format, imit_NULL);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_d_test_without_space) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, school%d";
  int n = 21;
  int imit_result_int = imit_sprintf(imit_result, format, n);
  int result_int = sprintf(result, format, n);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_d_test_several) {
  char imit_result[50];
  char result[50];
  char format[50] = "%d Hello school %d";
  int a = 0;
  int c = 21;
  int imit_result_int = imit_sprintf(imit_result, format, a, c);
  int result_int = sprintf(result, format, a, c);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_i_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "%i";
  int n = 21;
  int imit_result_int = imit_sprintf(imit_result, format, n);
  int result_int = sprintf(result, format, n);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_i_test_minus) {
  char imit_result[50];
  char result[50];
  char format[50] = "%i";
  int n = -21;
  int imit_result_int = imit_sprintf(imit_result, format, n);
  int result_int = sprintf(result, format, n);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_i_test_end) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello%i";
  int imit_result_int = imit_sprintf(imit_result, format, "\0");
  int result_int = sprintf(result, format, "\0");

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_i_test_without_space) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, school%i";
  int n = 21;
  int imit_result_int = imit_sprintf(imit_result, format, n);
  int result_int = sprintf(result, format, n);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_i_test_several) {
  char imit_result[50];
  char result[50];
  char format[50] = "%i Hello school %i";
  int a = 0;
  int c = 21;
  int imit_result_int = imit_sprintf(imit_result, format, a, c);
  int result_int = sprintf(result, format, a, c);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_u_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, school %u";
  unsigned int a = 021;
  int imit_result_int = imit_sprintf(imit_result, format, a);
  int result_int = sprintf(result, format, a);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_u_test_without_space) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world%u";
  unsigned int a = 021;
  int imit_result_int = imit_sprintf(imit_result, format, a);
  int result_int = sprintf(result, format, a);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_u_test_null) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello%u";
  int imit_result_int = imit_sprintf(imit_result, format, imit_NULL);
  int result_int = sprintf(result, format, imit_NULL);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_u_test_several) {
  char imit_result[50];
  char result[50];
  char format[50] = "%u Hello school %u";
  unsigned a = 021;
  unsigned c = 042;
  int imit_result_int = imit_sprintf(imit_result, format, a, c);
  int result_int = sprintf(result, format, a, c);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_precent_test) {
  char str1[100];
  char str2[100];

  ck_assert_int_eq(imit_sprintf(str1, "%%"), sprintf(str2, "%%"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(imit_sprintf_precent2_test) {
  char str1[100];
  char str2[100];

  ck_assert_int_eq(imit_sprintf(str1, "%%%%%%%%"), sprintf(str2, "%%%%%%%%"));
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *test_imit_sprintf_suite() {
  Suite *suite = suite_create("imit_sprintf");
  TCase *t_case = tcase_create("imit_sprintf");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_sprintf_c_test);
  tcase_add_test(t_case, imit_sprintf_c_test_null);
  tcase_add_test(t_case, imit_sprintf_c_test_without_space);
  tcase_add_test(t_case, imit_sprintf_c_test_several);
  tcase_add_test(t_case, imit_sprintf_c_test_end);

  tcase_add_test(t_case, imit_sprintf_d_test);
  tcase_add_test(t_case, imit_sprintf_d_test_null);
  tcase_add_test(t_case, imit_sprintf_d_test_without_space);
  tcase_add_test(t_case, imit_sprintf_d_test_several);
  tcase_add_test(t_case, imit_sprintf_d_test_minus);

  tcase_add_test(t_case, imit_sprintf_i_test);
  tcase_add_test(t_case, imit_sprintf_i_test_without_space);
  tcase_add_test(t_case, imit_sprintf_i_test_several);
  tcase_add_test(t_case, imit_sprintf_i_test_end);
  tcase_add_test(t_case, imit_sprintf_i_test_minus);

  tcase_add_test(t_case, imit_sprintf_u_test);
  tcase_add_test(t_case, imit_sprintf_u_test_null);
  tcase_add_test(t_case, imit_sprintf_u_test_without_space);
  tcase_add_test(t_case, imit_sprintf_u_test_several);

  tcase_add_test(t_case, imit_sprintf_precent_test);
  tcase_add_test(t_case, imit_sprintf_precent2_test);

  return suite;
}
