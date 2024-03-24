#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sscanf_d_base) {
  char* test_str = "12 255 9999999";
  char* test_format = "%d %d %d";

  int d1;
  int d2;
  int d3;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1;
  int imitd2;
  int imitd3;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_d_base_h) {
  char* test_str = "9999999 9999999 9999999";
  char* test_format = "%d %hd %hhd";

  int d1 = 0;
  int d2 = 0;
  int d3 = 0;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1 = 0;
  int imitd2 = 0;
  int imitd3 = 0;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_d_base_with_sign) {
  char* test_str = "-12 +255 -9999999";
  char* test_format = "%d %d %d";

  int d1;
  int d2;
  int d3;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1;
  int imitd2;
  int imitd3;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_i_base) {
  char* test_str = "017 0xf 0XF";
  char* test_format = "%i %i %i";

  int d1;
  int d2;
  int d3;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1;
  int imitd2;
  int imitd3;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_i_with_incorrect_arg) {
  char* test_str = "0x3E7 0xfs12 15";
  char* test_format = "%i %i %i";

  int d1;
  int d2;
  int d3;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1;
  int imitd2;
  int imitd3;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
}
END_TEST

START_TEST(imit_sscanf_i_d_togethere_in_str) {
  char* test_str = "0129 -22 +335";
  char* test_format = "%i %i %i";

  int d1;
  int d2;
  int d3;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1;
  int imitd2;
  int imitd3;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_i_with_space_characters) {
  char* test_str = "   0x3E7  \t  0xf  \n 15   ";
  char* test_format = "%i %i %i";

  int d1;
  int d2;
  int d3;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1;
  int imitd2;
  int imitd3;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_d_assignment) {
  char* test_str = "12 255 9999999";
  char* test_format = "%*d %d %d";

  int d1 = 0;
  int d2 = 0;
  int d3 = 0;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1 = 0;
  int imitd2 = 0;
  int imitd3 = 0;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_d_assignment_2) {
  char* test_str = "12 255 9999999";
  char* test_format = "%*d %*d %*d";

  int d1 = 0;
  int d2 = 0;
  int d3 = 0;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1 = 0;
  int imitd2 = 0;
  int imitd3 = 0;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_d_width) {
  char* test_str = "123 456 789";
  char* test_format = "%1d %2d %3d";

  int d1 = 0;
  int d2 = 0;
  int d3 = 0;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1 = 0;
  int imitd2 = 0;
  int imitd3 = 0;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_d_width_incorrect_format) {
  char* test_str = "12s3 456 789";
  char* test_format = "%1d %2d %3d";

  int d1 = 0;
  int d2 = 0;
  int d3 = 0;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1 = 0;
  int imitd2 = 0;
  int imitd3 = 0;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_d_length) {
  char* test_str = "99999999999999 99999999999999 999";
  char* test_format = "%hd %ld %d";

  int d1 = 0;
  int d2 = 0;
  int d3 = 0;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1 = 0;
  int imitd2 = 0;
  int imitd3 = 0;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_d_length_2) {
  char* test_str = "2147483647 2147483647 2147483647";
  char* test_format = "%hd %ld %d";

  int d1 = 0;
  int d2 = 0;
  int d3 = 0;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1 = 0;
  int imitd2 = 0;
  int imitd3 = 0;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_d_length_2_h) {
  char* test_str = "32767 32767 32767";
  char* test_format = "%d %hd %hhd";

  int d1 = 0;
  int d2 = 0;
  int d3 = 0;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1 = 0;
  int imitd2 = 0;
  int imitd3 = 0;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_d_length_3) {
  char* test_str =
      "9999999999999999999999999 9999999999999999999999999 "
      "9999999999999999999999999";
  char* test_format = "%hd %ld %d";

  int d1 = 0;
  int d2 = 0;
  int d3 = 0;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1 = 0;
  int imitd2 = 0;
  int imitd3 = 0;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_i_length) {
  char* test_str = "0x9999999999 0x9999999999 0x9999999999";
  char* test_format = "%hi %li %i";

  int d1 = 0;
  int d2 = 0;
  int d3 = 0;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1 = 0;
  int imitd2 = 0;
  int imitd3 = 0;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_i_length_2) {
  char* test_str = "09999999999 09999999999 09999999999";
  char* test_format = "%hi %li %i";

  int d1 = 0;
  int d2 = 0;
  int d3 = 0;

  int res = sscanf(test_str, test_format, &d1, &d2, &d3);

  int imitd1 = 0;
  int imitd2 = 0;
  int imitd3 = 0;

  int imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_i_length_2_ll) {
  char* test_str = "09999999999 09999999999 09999999999";
  char* test_format = "%i %li %lli";

  long int d1 = 0;
  long int d2 = 0;
  long int d3 = 0;
  long int res = 0;

  res = sscanf(test_str, test_format, &d1, &d2, &d3);

  long int imitd1 = 0;
  long int imitd2 = 0;
  long int imitd3 = 0;
  long int imitres = 0;

  imitres = imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
}
END_TEST

START_TEST(imit_sscanf_d_more_format) {
  char* test_str = "12 255 9999999";
  char* test_format = "%d %d %d %d";

  int d1 = 0, d2 = 0, d3 = 0, d4 = 0;
  int res = sscanf(test_str, test_format, &d1, &d2, &d3, &d4);

  int imitd1 = 0, imitd2 = 0, imitd3 = 0, imitd4 = 0;
  int imitres =
      imit_sscanf(test_str, test_format, &imitd1, &imitd2, &imitd3, &imitd4);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(d1, imitd1);
  ck_assert_int_eq(d2, imitd2);
  ck_assert_int_eq(d3, imitd3);
  ck_assert_int_eq(d4, imitd4);
}
END_TEST

START_TEST(line_skip_1) {
  char* test_str = "123 test 123";
  char* test_format = "%d test %d";

  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;

  int res1 = imit_sscanf(test_str, test_format, &a1, &b1);
  int res2 = sscanf(test_str, test_format, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(line_skip_2) {
  char* test_str = "123 test 123";
  char* test_format = "%dtest%d";

  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;

  int res1 = imit_sscanf(test_str, test_format, &a1, &b1);
  int res2 = sscanf(test_str, test_format, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(line_skip_3) {
  char* test_str = "123test123";
  char* test_format = "%dtest%d";

  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;

  int res1 = imit_sscanf(test_str, test_format, &a1, &b1);
  int res2 = sscanf(test_str, test_format, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

START_TEST(line_skip_4) {
  char* test_str = "123 test 123";
  char* test_format = "%d testS %d";

  int a1 = 0, a2 = 0, b1 = 0, b2 = 0;

  int res1 = imit_sscanf(test_str, test_format, &a1, &b1);
  int res2 = sscanf(test_str, test_format, &a2, &b2);

  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
}
END_TEST

Suite* test_imit_sscanf_d_i_suite() {
  Suite* suite = suite_create("imit_sscanf_d_i");
  TCase* t_case = tcase_create("imit_sscanf_d_i");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_sscanf_d_base);
  tcase_add_test(t_case, imit_sscanf_d_base_h);
  tcase_add_test(t_case, imit_sscanf_d_base_with_sign);
  tcase_add_test(t_case, imit_sscanf_i_base);
  tcase_add_test(t_case, imit_sscanf_i_with_incorrect_arg);
  tcase_add_test(t_case, imit_sscanf_i_d_togethere_in_str);
  tcase_add_test(t_case, imit_sscanf_i_with_space_characters);
  tcase_add_test(t_case, imit_sscanf_d_assignment);
  tcase_add_test(t_case, imit_sscanf_d_assignment_2);
  tcase_add_test(t_case, imit_sscanf_d_width);
  tcase_add_test(t_case, imit_sscanf_d_width_incorrect_format);
  tcase_add_test(t_case, imit_sscanf_d_length);
  tcase_add_test(t_case, imit_sscanf_d_length_2);
  tcase_add_test(t_case, imit_sscanf_d_length_2_h);
  tcase_add_test(t_case, imit_sscanf_d_length_3);
  tcase_add_test(t_case, imit_sscanf_i_length);
  tcase_add_test(t_case, imit_sscanf_i_length_2);
  tcase_add_test(t_case, imit_sscanf_i_length_2_ll);
  tcase_add_test(t_case, imit_sscanf_d_more_format);
  tcase_add_test(t_case, line_skip_1);
  tcase_add_test(t_case, line_skip_2);
  tcase_add_test(t_case, line_skip_3);
  tcase_add_test(t_case, line_skip_4);

  return suite;
}
