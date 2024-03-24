#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sprintf_c_precision_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.5c";
  int imit_result_int = imit_sprintf(imit_result, format, 'c');
  int result_int = sprintf(result, format, 'c');

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_c_precision_variable_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.*c";
  int imit_result_int = imit_sprintf(imit_result, format, 5, 'c');
  int result_int = sprintf(result, format, 5, 'c');

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_c_invalid_precision_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1-5c ";
  int imit_result_int = imit_sprintf(imit_result, format, 's');
  int result_int = sprintf(result, format, 's');

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_c_invalid_precision_number_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.*c ";
  int imit_result_int = imit_sprintf(imit_result, format, -5, 's');
  int result_int = sprintf(result, format, -5, 's');

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_c_invalid_precision_test_1) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.--5c ";
  int imit_result_int = imit_sprintf(imit_result, format, 's');
  int result_int = sprintf(result, format, 's');

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_i_precision_add_zeros_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.9i";
  int imit_result_int = imit_sprintf(imit_result, format, 9);
  int result_int = sprintf(result, format, 9);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_i_invalid_precision_number_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.-9i";
  int imit_result_int = imit_sprintf(imit_result, format, 9);
  int result_int = sprintf(result, format, 9);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_i_precision_number_add_zeros_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.*i";
  int imit_result_int = imit_sprintf(imit_result, format, 9, 9);
  int result_int = sprintf(result, format, 9, 9);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

// START_TEST(imit_sprintf_i_invalid_precision_add_zeros_test) {
//   char imit_result[50];
//   char result[50];
//   char format[50] = "Hello, world %.j9i";
//   int imit_result_int = imit_sprintf(imit_result, format, 9);
//   int result_int = sprintf(result, format, 9);

//   ck_assert_str_eq(imit_result, result);
//   ck_assert_int_eq(imit_result_int, result_int);
// }

// END_TEST

START_TEST(imit_sprintf_i_precision_no_truncation_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1i";
  int imit_result_int = imit_sprintf(imit_result, format, 900);
  int result_int = sprintf(result, format, 900);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_i_precision_number_no_truncation_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.*i";
  int imit_result_int = imit_sprintf(imit_result, format, 1, 900);
  int result_int = sprintf(result, format, 1, 900);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_i_precision_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1i";
  int imit_result_int = imit_sprintf(imit_result, format, 9);
  int result_int = sprintf(result, format, 9);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_i_zero_precision_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.i";
  int imit_result_int = imit_sprintf(imit_result, format, 9);
  int result_int = sprintf(result, format, 9);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_d_precision_add_zeros_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.9d";
  int imit_result_int = imit_sprintf(imit_result, format, 9);
  int result_int = sprintf(result, format, 9);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_d_invalid_precision_number_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.-9d";
  int imit_result_int = imit_sprintf(imit_result, format, 9);
  int result_int = sprintf(result, format, 9);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_d_precision_no_truncation_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1d";
  int imit_result_int = imit_sprintf(imit_result, format, 900);
  int result_int = sprintf(result, format, 900);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_d_precision_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1d";
  int imit_result_int = imit_sprintf(imit_result, format, 9);
  int result_int = sprintf(result, format, 9);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_u_precision_add_zeros_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.9u";
  int imit_result_int = imit_sprintf(imit_result, format, 9);
  int result_int = sprintf(result, format, 9);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_u_precision_no_truncation_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1u";
  int imit_result_int = imit_sprintf(imit_result, format, 900);
  int result_int = sprintf(result, format, 900);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_u_precision_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1u";
  int imit_result_int = imit_sprintf(imit_result, format, 9);
  int result_int = sprintf(result, format, 9);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_precision_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.3f";
  int imit_result_int = imit_sprintf(imit_result, format, 9.999f);
  int result_int = sprintf(result, format, 9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_invalid_precision_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.-3f";
  int imit_result_int = imit_sprintf(imit_result, format, 9.999f);
  int result_int = sprintf(result, format, 9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_precision_number_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.*f";
  int imit_result_int = imit_sprintf(imit_result, format, 3, 9.999f);
  int result_int = sprintf(result, format, 3, 9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_invalid_precision_number_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.*f";
  int imit_result_int = imit_sprintf(imit_result, format, -3, 9.999f);
  int result_int = sprintf(result, format, -3, 9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_precision_zero_precision_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.0f";
  int imit_result_int = imit_sprintf(imit_result, format, 9.999f);
  int result_int = sprintf(result, format, 9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_precision_rounding_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1f";
  int imit_result_int = imit_sprintf(imit_result, format, 9.89f);
  int result_int = sprintf(result, format, 9.89f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_precision_rounding_overflow_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1f";
  int imit_result_int = imit_sprintf(imit_result, format, 9.999f);
  int result_int = sprintf(result, format, 9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_precision_negative_value_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.3f";
  int imit_result_int = imit_sprintf(imit_result, format, -9.999f);
  int result_int = sprintf(result, format, -9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_precision_negative_value_zero_precision_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.0f";
  int imit_result_int = imit_sprintf(imit_result, format, -9.999f);
  int result_int = sprintf(result, format, -9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_precision_negative_value_rounding_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1f";
  int imit_result_int = imit_sprintf(imit_result, format, -9.89f);
  int result_int = sprintf(result, format, -9.89f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_precision_negative_value_rounding_overflow_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1f";
  int imit_result_int = imit_sprintf(imit_result, format, -9.999f);
  int result_int = sprintf(result, format, -9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_precision_zero_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.3f";
  int imit_result_int = imit_sprintf(imit_result, format, 0.00f);
  int result_int = sprintf(result, format, 0.000f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_precision_zero_zero_precision_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.0f";
  int imit_result_int = imit_sprintf(imit_result, format, 0.000f);
  int result_int = sprintf(result, format, 0.000f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_precision_zero_rounding_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1f";
  int imit_result_int = imit_sprintf(imit_result, format, 0.05f);
  int result_int = sprintf(result, format, 0.05f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_f_precision_zero_rounding_overflow_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1f";
  int imit_result_int = imit_sprintf(imit_result, format, 0.99f);
  int result_int = sprintf(result, format, 0.99f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_precision_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.3e";
  int imit_result_int = imit_sprintf(imit_result, format, 9.999f);
  int result_int = sprintf(result, format, 9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_invalid_precision_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.-3e";
  int imit_result_int = imit_sprintf(imit_result, format, 9.999f);
  int result_int = sprintf(result, format, 9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_precision_number_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.*e";
  int imit_result_int = imit_sprintf(imit_result, format, 3, 9.999f);
  int result_int = sprintf(result, format, 3, 9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_invalid_precision_number_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.*e";
  int imit_result_int = imit_sprintf(imit_result, format, -3, 9.999f);
  int result_int = sprintf(result, format, -3, 9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_precision_zero_precision_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.0e";
  int imit_result_int = imit_sprintf(imit_result, format, 9.999f);
  int result_int = sprintf(result, format, 9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_precision_rounding_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1e";
  int imit_result_int = imit_sprintf(imit_result, format, 9.89f);
  int result_int = sprintf(result, format, 9.89f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_precision_rounding_overflow_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1e";
  int imit_result_int = imit_sprintf(imit_result, format, 9.999f);
  int result_int = sprintf(result, format, 9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_precision_negative_value_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.3e";
  int imit_result_int = imit_sprintf(imit_result, format, -9.999f);
  int result_int = sprintf(result, format, -9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_precision_negative_value_zero_precision_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.0e";
  int imit_result_int = imit_sprintf(imit_result, format, -9.999f);
  int result_int = sprintf(result, format, -9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_precision_negative_value_rounding_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1e";
  int imit_result_int = imit_sprintf(imit_result, format, -9.89f);
  int result_int = sprintf(result, format, -9.89f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_precision_negative_value_rounding_overflow_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1e";
  int imit_result_int = imit_sprintf(imit_result, format, -9.999f);
  int result_int = sprintf(result, format, -9.999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_precision_zero_base_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.3e";
  int imit_result_int = imit_sprintf(imit_result, format, 0.000f);
  int result_int = sprintf(result, format, 0.000f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_precision_zero_zero_precision_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.0e";
  int imit_result_int = imit_sprintf(imit_result, format, 0.000f);
  int result_int = sprintf(result, format, 0.000f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_precision_zero_rounding_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1e";
  int imit_result_int = imit_sprintf(imit_result, format, 0.05f);
  int result_int = sprintf(result, format, 0.05f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_e_precision_zero_rounding_overflow_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.1e";
  int imit_result_int = imit_sprintf(imit_result, format, 0.99f);
  int result_int = sprintf(result, format, 0.99f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_s_truncation_test) {
  char *string = "hello";
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.3s";
  int imit_result_int = imit_sprintf(imit_result, format, string);
  int result_int = sprintf(result, format, string);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_s_number_truncation_test) {
  char *string = "hello";
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.*s";
  int imit_result_int = imit_sprintf(imit_result, format, 3, string);
  int result_int = sprintf(result, format, 3, string);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_s_invalid_precision_test) {
  char *string = "hello";
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.-3s";
  int imit_result_int = imit_sprintf(imit_result, format, string);
  int result_int = sprintf(result, format, string);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_s_excess_test) {
  char *string = "hello";
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.5s";
  int imit_result_int = imit_sprintf(imit_result, format, string);
  int result_int = sprintf(result, format, string);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_g_precision) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.5g";
  int imit_result_int = imit_sprintf(imit_result, format, 123456.654321f);
  int result_int = sprintf(result, format, 123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_g_invalid_precision) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.*g";
  int imit_result_int = imit_sprintf(imit_result, format, -5, 123456.654321f);
  int result_int = sprintf(result, format, -5, 123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_g_invalid_precision_2) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %.-5g";
  int imit_result_int = imit_sprintf(imit_result, format, 123456.654321f);
  int result_int = sprintf(result, format, 123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

Suite *test_imit_sprintf_precision_suite() {
  Suite *suite = suite_create("imit_sprintf_precision");
  TCase *t_case = tcase_create("imit_sprintf_precision");

  suite_add_tcase(suite, t_case);

  tcase_add_test(t_case, imit_sprintf_c_precision_test);
  tcase_add_test(t_case, imit_sprintf_c_invalid_precision_test);
  tcase_add_test(t_case, imit_sprintf_c_invalid_precision_test_1);

  tcase_add_test(t_case, imit_sprintf_c_precision_variable_test);
  tcase_add_test(t_case, imit_sprintf_c_invalid_precision_number_test);

  ////tcase_add_test(t_case, imit_sprintf_i_invalid_precision_add_zeros_test);
  tcase_add_test(t_case, imit_sprintf_i_precision_add_zeros_test);
  tcase_add_test(t_case, imit_sprintf_i_invalid_precision_number_test);
  tcase_add_test(t_case, imit_sprintf_i_precision_no_truncation_test);
  tcase_add_test(t_case, imit_sprintf_i_precision_base_test);
  tcase_add_test(t_case, imit_sprintf_i_zero_precision_test);

  tcase_add_test(t_case, imit_sprintf_i_precision_number_add_zeros_test);
  tcase_add_test(t_case, imit_sprintf_i_precision_number_no_truncation_test);

  tcase_add_test(t_case, imit_sprintf_d_precision_add_zeros_test);
  tcase_add_test(t_case, imit_sprintf_d_invalid_precision_number_test);
  tcase_add_test(t_case, imit_sprintf_d_precision_no_truncation_test);
  tcase_add_test(t_case, imit_sprintf_d_precision_base_test);

  tcase_add_test(t_case, imit_sprintf_u_precision_add_zeros_test);
  tcase_add_test(t_case, imit_sprintf_u_precision_no_truncation_test);
  tcase_add_test(t_case, imit_sprintf_u_precision_base_test);

  tcase_add_test(t_case, imit_sprintf_f_precision_base_test);
  tcase_add_test(t_case, imit_sprintf_f_invalid_precision_base_test);
  tcase_add_test(t_case, imit_sprintf_f_precision_zero_precision_test);
  tcase_add_test(t_case, imit_sprintf_f_precision_rounding_test);
  tcase_add_test(t_case, imit_sprintf_f_precision_rounding_overflow_test);

  tcase_add_test(t_case, imit_sprintf_f_precision_number_base_test);
  tcase_add_test(t_case, imit_sprintf_f_invalid_precision_number_base_test);

  tcase_add_test(t_case, imit_sprintf_f_precision_negative_value_base_test);
  tcase_add_test(t_case,
                 imit_sprintf_f_precision_negative_value_zero_precision_test);
  tcase_add_test(t_case, imit_sprintf_f_precision_negative_value_rounding_test);
  tcase_add_test(t_case,
                 imit_sprintf_f_precision_negative_value_rounding_overflow_test);

  tcase_add_test(t_case, imit_sprintf_f_precision_zero_base_test);
  tcase_add_test(t_case, imit_sprintf_f_precision_zero_zero_precision_test);
  tcase_add_test(t_case, imit_sprintf_f_precision_zero_rounding_test);
  tcase_add_test(t_case, imit_sprintf_f_precision_zero_rounding_overflow_test);

  tcase_add_test(t_case, imit_sprintf_e_precision_base_test);
  tcase_add_test(t_case, imit_sprintf_e_invalid_precision_base_test);
  tcase_add_test(t_case, imit_sprintf_e_precision_zero_precision_test);
  tcase_add_test(t_case, imit_sprintf_e_precision_rounding_test);
  tcase_add_test(t_case, imit_sprintf_e_precision_rounding_overflow_test);

  tcase_add_test(t_case, imit_sprintf_e_precision_number_base_test);
  tcase_add_test(t_case, imit_sprintf_e_invalid_precision_number_base_test);

  tcase_add_test(t_case, imit_sprintf_e_precision_negative_value_base_test);
  tcase_add_test(t_case,
                 imit_sprintf_e_precision_negative_value_zero_precision_test);
  tcase_add_test(t_case, imit_sprintf_e_precision_negative_value_rounding_test);
  tcase_add_test(t_case,
                 imit_sprintf_e_precision_negative_value_rounding_overflow_test);

  tcase_add_test(t_case, imit_sprintf_e_precision_zero_base_test);
  tcase_add_test(t_case, imit_sprintf_e_precision_zero_zero_precision_test);
  tcase_add_test(t_case, imit_sprintf_e_precision_zero_rounding_test);
  tcase_add_test(t_case, imit_sprintf_e_precision_zero_rounding_overflow_test);

  tcase_add_test(t_case, imit_sprintf_s_truncation_test);
  tcase_add_test(t_case, imit_sprintf_s_excess_test);

  tcase_add_test(t_case, imit_sprintf_s_invalid_precision_test);
  tcase_add_test(t_case, imit_sprintf_s_number_truncation_test);

  tcase_add_test(t_case, imit_sprintf_g_precision);
  tcase_add_test(t_case, imit_sprintf_g_invalid_precision);
  tcase_add_test(t_case, imit_sprintf_g_invalid_precision_2);

  return suite;
}