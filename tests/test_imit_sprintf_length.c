#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sprintf_length_test_lc) {
  char imit_result[20] = {'\0'};
  char result[20] = {'\0'};
  char c = 'z';
  imit_sprintf(imit_result, "Count: %lc", c);
  sprintf(result, "Count: %lc", c);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_ld) {
  char imit_result[40];
  char result[40];
  long int d = 2147483647;
  imit_sprintf(imit_result, "Count: %ld abc", d);
  sprintf(result, "Count: %ld abc", d);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_hd) {
  char imit_result[40];
  char result[40];
  short int d = 32767;
  imit_sprintf(imit_result, "Count: %hd abc", d);
  sprintf(result, "Count: %hd abc", d);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_li) {
  char imit_result[40];
  char result[40];
  long int i = -2147483647;
  imit_sprintf(imit_result, "Count: %li abc", i);
  sprintf(result, "Count: %li abc", i);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_hi) {
  char imit_result[40];
  char result[40];
  short int i = 32767;
  imit_sprintf(imit_result, "Count: %hi abc", i);
  sprintf(result, "Count: %hi abc", i);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_lu) {
  char imit_result[40];
  char result[40];
  long unsigned a = 3088675747373646;
  imit_sprintf(imit_result, "Count: %lu abc", a);
  sprintf(result, "Count: %lu abc", a);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_hu) {
  char imit_result[40];
  char result[40];
  unsigned short c = 22600;
  imit_sprintf(imit_result, "Count: %hu abc", c);
  sprintf(result, "Count: %hu abc", c);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_lo) {
  char imit_result[100];
  char result[100];
  long unsigned int a = 2147483647;
  imit_sprintf(imit_result, "Count: %lo abc", a);
  sprintf(result, "Count: %lo abc", a);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_ho) {
  char imit_result[40];
  char result[40];
  unsigned short c = 22600;
  imit_sprintf(imit_result, "Count: %ho abc", c);
  sprintf(result, "Count: %ho abc", c);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_lx) {
  char imit_result[40];
  char result[40];
  long unsigned int a = 0x30ff57;
  imit_sprintf(imit_result, "Count: %lx abc", a);
  sprintf(result, "Count: %lx abc", a);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_hx) {
  char imit_result[40];
  char result[40];
  unsigned short c = 0x2f;
  imit_sprintf(imit_result, "Count: %hx abc", c);
  sprintf(result, "Count: %hx abc", c);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_lX) {
  char imit_result[40];
  char result[40];
  long unsigned int a = 0X30ff57;
  imit_sprintf(imit_result, "Count: %lX abc", a);
  sprintf(result, "Count: %lX abc", a);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_hX) {
  char imit_result[40];
  char result[40];
  unsigned short c = 0X2f;
  imit_sprintf(imit_result, "Count: %hX abc", c);
  sprintf(result, "Count: %hX abc", c);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_lenght_test_o2) {
  char imit_result[100];
  char result[100];
  char *format = "%lo";
  int dec = 36;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_length_test_Lf) {
  char imit_result[40];
  char result[40];
  long double a = 8364.4366;
  imit_sprintf(imit_result, "Count: %Lf abc", a);
  sprintf(result, "Count: %Lf abc", a);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_Lg) {
  char imit_result[40];
  char result[40];
  long double c = 365289.3462865487;
  imit_sprintf(imit_result, "Count: %Lg abc", c);
  sprintf(result, "Count: %Lg abc", c);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_LG) {
  char imit_result[40];
  char result[40];
  long double c = 365289.3462865487;
  imit_sprintf(imit_result, "Count: %LG abc", c);
  sprintf(result, "Count: %LG abc", c);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_lg) {
  char imit_result[40];
  char result[40];
  double c = 365289.34628;
  imit_sprintf(imit_result, "Count: %lg abc", c);
  sprintf(result, "Count: %lg abc", c);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_lG) {
  char imit_result[40];
  char result[40];
  double c = 365289.34628;
  imit_sprintf(imit_result, "Count: %lG abc", c);
  sprintf(result, "Count: %lG abc", c);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_Le) {
  char imit_result[40];
  char result[40];
  long double c = -365289.34628654873789362746834;
  imit_sprintf(imit_result, "Count: %Le abc", c);
  sprintf(result, "Count: %Le abc", c);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_LE) {
  char imit_result[40];
  char result[40];
  long double c = -365289.34628654873789362746834;
  imit_sprintf(imit_result, "Count: %LE abc", c);
  sprintf(result, "Count: %LE abc", c);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_le) {
  char imit_result[40];
  char result[40];
  double c = -365289.3462865487378;
  imit_sprintf(imit_result, "Count: %le abc", c);
  sprintf(result, "Count: %le abc", c);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_length_test_lE) {
  char imit_result[40];
  char result[40];
  double c = -365289.3462865487378;
  imit_sprintf(imit_result, "Count: %lE abc", c);
  sprintf(result, "Count: %lE abc", c);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

Suite *test_imit_sprintf_length_suite() {
  Suite *suite = suite_create("imit_sprintf_length");
  TCase *t_case = tcase_create("imit_sprintf_length");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_sprintf_length_test_hi);
  tcase_add_test(t_case, imit_sprintf_length_test_li);
  tcase_add_test(t_case, imit_sprintf_length_test_hd);
  tcase_add_test(t_case, imit_sprintf_length_test_ld);
  tcase_add_test(t_case, imit_sprintf_length_test_lu);
  tcase_add_test(t_case, imit_sprintf_length_test_hu);
  tcase_add_test(t_case, imit_sprintf_length_test_lo);
  tcase_add_test(t_case, imit_sprintf_length_test_ho);
  tcase_add_test(t_case, imit_sprintf_length_test_lx);
  tcase_add_test(t_case, imit_sprintf_length_test_hx);
  tcase_add_test(t_case, imit_sprintf_length_test_lX);
  tcase_add_test(t_case, imit_sprintf_length_test_hX);
  tcase_add_test(t_case, imit_sprintf_lenght_test_o2);
  tcase_add_test(t_case, imit_sprintf_length_test_Lf);
  tcase_add_test(t_case, imit_sprintf_length_test_Lg);
  tcase_add_test(t_case, imit_sprintf_length_test_LG);
  tcase_add_test(t_case, imit_sprintf_length_test_lg);
  tcase_add_test(t_case, imit_sprintf_length_test_lG);
  tcase_add_test(t_case, imit_sprintf_length_test_Le);
  tcase_add_test(t_case, imit_sprintf_length_test_LE);
  tcase_add_test(t_case, imit_sprintf_length_test_lc);
  tcase_add_test(t_case, imit_sprintf_length_test_le);
  tcase_add_test(t_case, imit_sprintf_length_test_lE);

  return suite;
}