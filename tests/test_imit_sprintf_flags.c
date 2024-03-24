#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sprintf_flag_minus_test_d) {
  char imit_result[20];
  char result[20];
  imit_sprintf(imit_result, "Count: %-d", 69);
  sprintf(result, "Count: %-d", 69);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_minus_test_i) {
  char imit_result[20];
  char result[20];
  imit_sprintf(imit_result, "Count: %-i", 21);
  sprintf(result, "Count: %-i", 21);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_plus_test_d_1) {
  char imit_result[20];
  char result[20];
  imit_sprintf(imit_result, "Count: %+d", 21);
  sprintf(result, "Count: %+d", 21);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_plus_test_d_2) {
  char imit_result[20];
  char result[20];
  imit_sprintf(imit_result, "Count: %+d", -21);
  sprintf(result, "Count: %+d", -21);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_plus_test_i_1) {
  char imit_result[20];
  char result[20];
  imit_sprintf(imit_result, "Count: %+i", 21);
  sprintf(result, "Count: %+i", 21);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_plus_test_i_2) {
  char imit_result[20];
  char result[20];
  imit_sprintf(imit_result, "Count: %+i", -21);
  sprintf(result, "Count: %+i", -21);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_plus_test_f_1) {
  char imit_result[20];
  char result[20];
  imit_sprintf(imit_result, "Count: %+f", 21.0f);
  sprintf(result, "Count: %+f", 21.f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_plus_test_f_2) {
  char imit_result[20];
  char result[20];
  imit_sprintf(imit_result, "Count: %+f", 21.0f);
  sprintf(result, "Count: %+f", 21.0f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_plus_test_e_1) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: %+e", 21.0f);
  sprintf(result, "Count: %+e", 21.f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_plus_test_e_2) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: %+e", 21.0f);
  sprintf(result, "Count: %+e", 21.0f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_plus_test_g_1) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: %+g", 21.0f);
  sprintf(result, "Count: %+g", 21.f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_plus_test_g_2) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: %+g", 21.0f);
  sprintf(result, "Count: %+g", 21.0f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_space_test_d_1) {
  char imit_result[20];
  char result[20];
  int d = 1;
  imit_sprintf(imit_result, "Count: % d abc", d);
  sprintf(result, "Count: % d abc", d);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_space_test_d_2) {
  char imit_result[40];
  char result[40];
  int d = 2147483647;
  imit_sprintf(imit_result, "Count: % d abc", d);
  sprintf(result, "Count: % d abc", d);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_space_test_i_1) {
  char imit_result[20];
  char result[20];
  int d = 1;
  imit_sprintf(imit_result, "Count: % i abc", d);
  sprintf(result, "Count: % i abc", d);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_space_test_i_2) {
  char imit_result[40];
  char result[40];
  int d = 2147483647;
  imit_sprintf(imit_result, "Count: % i abc", d);
  sprintf(result, "Count: % i abc", d);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_space_test_f_1) {
  char imit_result[20];
  char result[20];
  imit_sprintf(imit_result, "Count: % f", 21.0f);
  sprintf(result, "Count: % f", 21.f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_space_test_f_2) {
  char imit_result[20];
  char result[20];
  imit_sprintf(imit_result, "Count: % f", 21.0f);
  sprintf(result, "Count: % f", 21.0f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_space_test_e_1) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: % e", 21.0f);
  sprintf(result, "Count: % e", 21.f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_space_test_e_2) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: % e", 21.0f);
  sprintf(result, "Count: % e", 21.0f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_space_test_g_1) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: % g", 21.0f);
  sprintf(result, "Count: % g", 21.f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_space_test_g_2) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: % g", 21.0f);
  sprintf(result, "Count: % g", 21.0f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_plus_space_test_g) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: %+ g", 21.0f);
#pragma GCC diagnostic ignored "-Wformat"
  sprintf(result, "Count: %+ g", 21.0f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_minus_test_f_1) {
  char imit_result[20];
  char result[20];
  imit_sprintf(imit_result, "Count: %-f", 21.0f);
  sprintf(result, "Count: %-f", 21.f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_minus_test_f_2) {
  char imit_result[20];
  char result[20];
  imit_sprintf(imit_result, "Count: %-f", 21.0f);
  sprintf(result, "Count: %-f", 21.0f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_minus_test_e_1) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: %-e", 21.0f);
  sprintf(result, "Count: %-e", 21.f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_minus_test_e_2) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: %-e", 21.0f);
  sprintf(result, "Count: %-e", 21.0f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_minus_test_g_1) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: %-g", 21.0f);
  sprintf(result, "Count: %-g", 21.f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_minus_test_g_2) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: %-g", 21.0f);
  sprintf(result, "Count: %-g", 21.0f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_minus_width_test_f_2) {
  char imit_result[20];
  char result[20];
  imit_sprintf(imit_result, "Count: %-10f", 21.0f);
  sprintf(result, "Count: %-10f", 21.0f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_minus_width_test_e_1) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: %-10e", 21.0f);
  sprintf(result, "Count: %-10e", 21.f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_minus_width_test_e_2) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: %-15e", 21.0f);
  sprintf(result, "Count: %-15e", 21.0f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_minus_width_test_g_1) {
  char imit_result[50];
  char result[50];
  imit_sprintf(imit_result, "Count: %-15g", 21.0f);
  sprintf(result, "Count: %-15g", 21.f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

START_TEST(imit_sprintf_flag_minus_width_test_g_2) {
  char imit_result[100];
  char result[100];
  imit_sprintf(imit_result, "Count: %-15g", 21.0f);
  sprintf(result, "Count: %-15g", 21.0f);
  ck_assert_str_eq(imit_result, result);
}
END_TEST

Suite *test_imit_sprintf_flags_suite() {
  Suite *suite = suite_create("imit_sprintf_flags");
  TCase *t_case = tcase_create("imit_sprintf_flags");

  suite_add_tcase(suite, t_case);

  tcase_add_test(t_case, imit_sprintf_flag_plus_test_d_2);
  tcase_add_test(t_case, imit_sprintf_flag_plus_test_d_1);
  tcase_add_test(t_case, imit_sprintf_flag_plus_test_i_1);
  tcase_add_test(t_case, imit_sprintf_flag_plus_test_i_2);
  tcase_add_test(t_case, imit_sprintf_flag_plus_test_f_1);
  tcase_add_test(t_case, imit_sprintf_flag_plus_test_f_2);
  tcase_add_test(t_case, imit_sprintf_flag_plus_test_g_1);
  tcase_add_test(t_case, imit_sprintf_flag_plus_test_g_2);
  tcase_add_test(t_case, imit_sprintf_flag_plus_test_e_1);
  tcase_add_test(t_case, imit_sprintf_flag_plus_test_e_2);

  tcase_add_test(t_case, imit_sprintf_flag_space_test_f_1);
  tcase_add_test(t_case, imit_sprintf_flag_space_test_f_2);
  tcase_add_test(t_case, imit_sprintf_flag_space_test_g_1);
  tcase_add_test(t_case, imit_sprintf_flag_space_test_g_2);
  tcase_add_test(t_case, imit_sprintf_flag_space_test_e_1);
  tcase_add_test(t_case, imit_sprintf_flag_space_test_e_2);

  tcase_add_test(t_case, imit_sprintf_flag_plus_space_test_g);

  tcase_add_test(t_case, imit_sprintf_flag_minus_test_d);
  tcase_add_test(t_case, imit_sprintf_flag_minus_test_i);
  tcase_add_test(t_case, imit_sprintf_flag_minus_test_f_1);
  tcase_add_test(t_case, imit_sprintf_flag_minus_test_f_2);
  tcase_add_test(t_case, imit_sprintf_flag_minus_test_g_1);
  tcase_add_test(t_case, imit_sprintf_flag_minus_test_g_2);
  tcase_add_test(t_case, imit_sprintf_flag_minus_test_e_1);
  tcase_add_test(t_case, imit_sprintf_flag_minus_test_e_2);

  tcase_add_test(t_case, imit_sprintf_flag_minus_width_test_f_2);
  tcase_add_test(t_case, imit_sprintf_flag_minus_width_test_g_1);
  tcase_add_test(t_case, imit_sprintf_flag_minus_width_test_g_2);
  tcase_add_test(t_case, imit_sprintf_flag_minus_width_test_e_1);
  tcase_add_test(t_case, imit_sprintf_flag_minus_width_test_e_2);

  tcase_add_test(t_case, imit_sprintf_flag_space_test_d_1);
  tcase_add_test(t_case, imit_sprintf_flag_space_test_d_2);
  tcase_add_test(t_case, imit_sprintf_flag_space_test_i_1);
  tcase_add_test(t_case, imit_sprintf_flag_space_test_i_2);

  return suite;
}