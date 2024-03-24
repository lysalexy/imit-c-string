#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sprintf_width_number_c_test) {
  char imit_result[50];
  char result[50];
  char character = 'A';
  char *format = "%10c";
  int imit_result_int = imit_sprintf(imit_result, format, character);
  int result_int = sprintf(result, format, character);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_c_neg_test) {
  char imit_result[50];
  char result[50];
  char character = 'A';
  char *format = "%-12c";
  int imit_result_int = imit_sprintf(imit_result, format, character);
  int result_int = sprintf(result, format, character);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_c_star_test) {
  char imit_result[50];
  char result[50];
  char character = 'A';
  char *format = "%*c";
  char res = 10;
  int imit_result_int = imit_sprintf(imit_result, format, res, character);
  int result_int = sprintf(result, format, res, character);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_c_precision_test) {
  char imit_result[50];
  char result[50];
  char character = 'A';
  char *format = "%10.7c";
  int imit_result_int = imit_sprintf(imit_result, format, character);
  int result_int = sprintf(result, format, character);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_d_test) {
  char imit_result[50];
  char result[50];
  int num = 42;
  char *format = "%10d";
  int imit_result_int = imit_sprintf(imit_result, format, num);
  int result_int = sprintf(result, format, num);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_d_neg_test) {
  char imit_result[50];
  char result[50];
  int num = 42;
  char *format = "%-10d";
  int imit_result_int = imit_sprintf(imit_result, format, num);
  int result_int = sprintf(result, format, num);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_d_star_test) {
  char imit_result[50];
  char result[50];
  int num = 42;
  int res = 10;
  char *format = "%*d";
  int imit_result_int = imit_sprintf(imit_result, format, res, num);
  int result_int = sprintf(result, format, res, num);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_d_precision5_test) {
  char imit_result[50];
  char result[50];
  int num = 42;
  char *format = "%10.5d";  // >5 тест падает
  int imit_result_int = imit_sprintf(imit_result, format, num);
  int result_int = sprintf(result, format, num);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_d_precision2_test) {
  char imit_result[50];
  char result[50];
  int num = 42;
  char *format = "%10.2d";  // >5 тест падает
  int imit_result_int = imit_sprintf(imit_result, format, num);
  int result_int = sprintf(result, format, num);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_i_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "%12i";
  int n = 21;
  int imit_result_int = imit_sprintf(imit_result, format, n);
  int result_int = sprintf(result, format, n);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_i_neg_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "%-12i";
  int n = 21;
  int imit_result_int = imit_sprintf(imit_result, format, n);
  int result_int = sprintf(result, format, n);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_i_star_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "%*i";
  int res = 12;
  int n = 21;
  int imit_result_int = imit_sprintf(imit_result, format, res, n);
  int result_int = sprintf(result, format, res, n);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_i_precision5_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "%10.5i";
  int res = 12;
  int n = 21;
  int imit_result_int = imit_sprintf(imit_result, format, res, n);
  int result_int = sprintf(result, format, res, n);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_i_precision2_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "%10.2i";
  int res = 12;
  int n = 21;
  int imit_result_int = imit_sprintf(imit_result, format, res, n);
  int result_int = sprintf(result, format, res, n);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_e_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %10e";
  int imit_result_int = imit_sprintf(imit_result, format, 123456.654321f);
  int result_int = sprintf(result, format, 123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_e_neg_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %-15e";
  int imit_result_int = imit_sprintf(imit_result, format, 123456.654321f);
  int result_int = sprintf(result, format, 123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_e_star_test) {
  char imit_result[50];
  char result[50];
  int res = 12;
  char format[50] = "Hello, world %*e";
  int imit_result_int = imit_sprintf(imit_result, format, res, 123456.654321f);
  int result_int = sprintf(result, format, res, 123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_e_precision_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %10.5e";
  int imit_result_int = imit_sprintf(imit_result, format, 123456.654321f);
  int result_int = sprintf(result, format, 123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_E_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %12E";
  int imit_result_int = imit_sprintf(imit_result, format, 1.9999999f);
  int result_int = sprintf(result, format, 1.9999999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_E_neg_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %-5E";
  int imit_result_int = imit_sprintf(imit_result, format, 1.9999999f);
  int result_int = sprintf(result, format, 1.9999999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_E_star_test) {
  char imit_result[50];
  char result[50];
  int res = 5;
  char format[50] = "Hello, world %*E";
  int imit_result_int = imit_sprintf(imit_result, format, res, 1.9999999f);
  int result_int = sprintf(result, format, res, 1.9999999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_E_precision_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %12.6E";
  int imit_result_int = imit_sprintf(imit_result, format, 1.9999999f);
  int result_int = sprintf(result, format, 1.9999999f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_f_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %10f";
  int imit_result_int = imit_sprintf(imit_result, format, 123456.654321f);
  int result_int = sprintf(result, format, 123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_f_neg_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %-5f";
  int imit_result_int = imit_sprintf(imit_result, format, 123456.654321f);
  int result_int = sprintf(result, format, 123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_f_star_test) {
  char imit_result[50];
  char result[50];
  int res = 15;
  char format[50] = "Hello, world %*f";
  int imit_result_int = imit_sprintf(imit_result, format, res, 123456.654321f);
  int result_int = sprintf(result, format, res, 123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_f_precision_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %10.7f";
  int imit_result_int = imit_sprintf(imit_result, format, 123456.654321f);
  int result_int = sprintf(result, format, 123456.654321f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_g_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %10g";
  int imit_result_int = imit_sprintf(imit_result, format, 0.0f);
  int result_int = sprintf(result, format, 0.0f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_g_neg_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %-16g";
  int imit_result_int = imit_sprintf(imit_result, format, 0.0f);
  int result_int = sprintf(result, format, 0.0f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_g_star_test) {
  char imit_result[50];
  char result[50];
  int res = 14;
  char format[50] = "Hello, world %*g";
  int imit_result_int = imit_sprintf(imit_result, format, res, 0.0f);
  int result_int = sprintf(result, format, res, 0.0f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_g_precision_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %5.6g";
  int imit_result_int = imit_sprintf(imit_result, format, 0.0f);
  int result_int = sprintf(result, format, 0.0f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_G_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %10G";
  int imit_result_int = imit_sprintf(imit_result, format, 0.0f);
  int result_int = sprintf(result, format, 0.0f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_G_neg_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %-10G";
  int imit_result_int = imit_sprintf(imit_result, format, 0.0f);
  int result_int = sprintf(result, format, 0.0f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_G_star_test) {
  char imit_result[50];
  char result[50];
  int res = 15;
  char format[50] = "Hello, world %*G";
  int imit_result_int = imit_sprintf(imit_result, format, res, 0.0f);
  int result_int = sprintf(result, format, res, 0.0f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_G_precision_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %10.5G";
  int imit_result_int = imit_sprintf(imit_result, format, 0.0f);
  int result_int = sprintf(result, format, 0.0f);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_o_test) {
  char imit_result[100];
  char result[100];
  char *format = "%10o";
  int dec = 36;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_o_max_test) {
  char imit_result[120];
  char result[120];
  char *format = "%101o";
  int dec = 36;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_o_neg_test) {
  char imit_result[100];
  char result[100];
  char *format = "%-5o";
  int dec = 36;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_o_star_test) {
  char imit_result[100];
  char result[100];
  int res = 10;
  char *format = "%*o";
  int dec = 36;
  int imit_result_int = imit_sprintf(imit_result, format, res, dec);
  int result_int = sprintf(result, format, res, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_o_precision5_test) {
  char imit_result[100];
  char result[100];
  char *format = "%5.5o";
  int dec = 36;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_o_precision2_test) {
  char imit_result[100];
  char result[100];
  char *format = "%5.2o";
  int dec = 36;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_s_test) {
  char *string = "hello";

  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %10s";
  int imit_result_int = imit_sprintf(imit_result, format, string);
  int result_int = sprintf(result, format, string);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_s_neg_test) {
  char *string = "hello";
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %-12s";
  int imit_result_int = imit_sprintf(imit_result, format, string);
  int result_int = sprintf(result, format, string);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_s_star_test) {
  char *string = "hello";
  char imit_result[50];
  char result[50];
  int res = 10;
  char format[50] = "Hello, world %*s";
  int imit_result_int = imit_sprintf(imit_result, format, res, string);
  int result_int = sprintf(result, format, res, string);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_s_precision_test) {
  char *string = "hello";
  char imit_result[50];
  char result[50];
  char format[50] = "Hello, world %-12.5s";
  int imit_result_int = imit_sprintf(imit_result, format, string);
  int result_int = sprintf(result, format, string);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_1_test) {
  char *string = "hello";
  char imit_result[50];
  char result[50];
  char format[50] = "%12s Hello, world";
  int imit_result_int = imit_sprintf(imit_result, format, string);
  int result_int = sprintf(result, format, string);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_2_test) {
  char *string = "hello";
  char imit_result[50];
  char result[50];
  char format[50] = "%12s Hello, world %12s";
  int imit_result_int = imit_sprintf(imit_result, format, string);
  int result_int = sprintf(result, format, string);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_u_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello%10u";
  int imit_result_int = imit_sprintf(imit_result, format, imit_NULL);
  int result_int = sprintf(result, format, imit_NULL);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_u_neg_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello%-5u";
  int imit_result_int = imit_sprintf(imit_result, format, imit_NULL);
  int result_int = sprintf(result, format, imit_NULL);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_u_star_test) {
  char imit_result[50];
  char result[50];
  int res = 4;
  char format[50] = "Hello%*u";
  int imit_result_int = imit_sprintf(imit_result, format, res, imit_NULL);
  int result_int = sprintf(result, format, res, imit_NULL);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_u_precision5_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello%10.5u";
  int imit_result_int = imit_sprintf(imit_result, format, imit_NULL);
  int result_int = sprintf(result, format, imit_NULL);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_u_precision2_test) {
  char imit_result[50];
  char result[50];
  char format[50] = "Hello%10.2u";
  int imit_result_int = imit_sprintf(imit_result, format, imit_NULL);
  int result_int = sprintf(result, format, imit_NULL);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_x_test) {
  char imit_result[100];
  char result[100];
  char *format = "%10x";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_x_max_test) {
  char imit_result[120];
  char result[120];
  char *format = "%102x";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_x_neg_test) {
  char imit_result[100];
  char result[100];
  char *format = "%-15x";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_x_star_test) {
  char imit_result[100];
  char result[100];
  int res = 12;
  char *format = "%*x";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, res, dec);
  int result_int = sprintf(result, format, res, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_x_precision5_test) {
  char imit_result[100];
  char result[100];
  char *format = "%5.5x";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_x_precision2_test) {
  char imit_result[100];
  char result[100];
  char *format = "%5.2x";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_X_test) {
  char imit_result[100];
  char result[100];
  char *format = "%9X";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST
START_TEST(imit_sprintf_width_number_X_max_test) {
  char imit_result[150];
  char result[150];
  char *format = "%103X";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_X_neg_test) {
  char imit_result[100];
  char result[100];
  char *format = "%-5X";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_X_star_test) {
  char imit_result[100];
  char result[100];
  int res = 4;
  char *format = "%*X";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, res, dec);
  int result_int = sprintf(result, format, res, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_X_precision5_test) {
  char imit_result[100];
  char result[100];
  char *format = "%10.5X";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_X_precision2_test) {
  char imit_result[100];
  char result[100];
  char *format = "%10.2X";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, dec);
  int result_int = sprintf(result, format, dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_p_test) {
  char imit_result[100];
  char result[100];
  char *format = "%20p";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, &dec);
  int result_int = sprintf(result, format, &dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_p_neg_test) {
  char imit_result[100];
  char result[100];
  char *format = "%-21p";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, &dec);
  int result_int = sprintf(result, format, &dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_p_star_test) {
  char imit_result[100];
  char result[100];
  int res = 4;
  char *format = "%*p";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, res, &dec);
  int result_int = sprintf(result, format, res, &dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

START_TEST(imit_sprintf_width_number_p_precision_test) {
  char imit_result[100];
  char result[100];
  char *format = "%10.8p";
  // char *format2 = "%d";
  int dec = 30;
  // int dec2 = 100;
  int imit_result_int = imit_sprintf(imit_result, format, &dec);
  int result_int = sprintf(result, format, &dec);

  ck_assert_str_eq(imit_result, result);
  ck_assert_int_eq(imit_result_int, result_int);
}
END_TEST

Suite *test_imit_sprintf_width_number_suite() {
  Suite *suite = suite_create("imit_sprintf_width_number");
  TCase *t_case = tcase_create("imit_sprintf_width_number");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_sprintf_width_number_c_test);
  tcase_add_test(t_case, imit_sprintf_width_number_c_neg_test);
  tcase_add_test(t_case, imit_sprintf_width_number_c_star_test);
  tcase_add_test(t_case, imit_sprintf_width_number_c_precision_test);

  tcase_add_test(t_case, imit_sprintf_width_number_d_test);
  tcase_add_test(t_case, imit_sprintf_width_number_d_neg_test);
  tcase_add_test(t_case, imit_sprintf_width_number_d_star_test);
  tcase_add_test(t_case, imit_sprintf_width_number_d_precision5_test);
  tcase_add_test(t_case, imit_sprintf_width_number_d_precision2_test);

  tcase_add_test(t_case, imit_sprintf_width_number_i_test);
  tcase_add_test(t_case, imit_sprintf_width_number_i_neg_test);
  tcase_add_test(t_case, imit_sprintf_width_number_i_star_test);
  tcase_add_test(t_case, imit_sprintf_width_number_i_precision5_test);
  tcase_add_test(t_case, imit_sprintf_width_number_i_precision2_test);

  tcase_add_test(t_case, imit_sprintf_width_number_e_test);
  tcase_add_test(t_case, imit_sprintf_width_number_e_neg_test);
  tcase_add_test(t_case, imit_sprintf_width_number_e_star_test);
  tcase_add_test(t_case, imit_sprintf_width_number_e_precision_test);

  tcase_add_test(t_case, imit_sprintf_width_number_E_test);
  tcase_add_test(t_case, imit_sprintf_width_number_E_neg_test);
  tcase_add_test(t_case, imit_sprintf_width_number_E_star_test);
  tcase_add_test(t_case, imit_sprintf_width_number_E_precision_test);

  tcase_add_test(t_case, imit_sprintf_width_number_f_test);
  tcase_add_test(t_case, imit_sprintf_width_number_f_neg_test);
  tcase_add_test(t_case, imit_sprintf_width_number_f_star_test);
  tcase_add_test(t_case, imit_sprintf_width_number_f_precision_test);

  tcase_add_test(t_case, imit_sprintf_width_number_g_test);
  tcase_add_test(t_case, imit_sprintf_width_number_g_neg_test);
  tcase_add_test(t_case, imit_sprintf_width_number_g_star_test);
  tcase_add_test(t_case, imit_sprintf_width_number_g_precision_test);

  tcase_add_test(t_case, imit_sprintf_width_number_G_test);
  tcase_add_test(t_case, imit_sprintf_width_number_G_neg_test);
  tcase_add_test(t_case, imit_sprintf_width_number_G_star_test);
  tcase_add_test(t_case, imit_sprintf_width_number_G_precision_test);

  tcase_add_test(t_case, imit_sprintf_width_number_o_test);
  tcase_add_test(t_case, imit_sprintf_width_number_o_max_test);
  tcase_add_test(t_case, imit_sprintf_width_number_o_neg_test);
  tcase_add_test(t_case, imit_sprintf_width_number_o_star_test);
  tcase_add_test(t_case, imit_sprintf_width_number_o_precision5_test);
  tcase_add_test(t_case, imit_sprintf_width_number_o_precision2_test);

  tcase_add_test(t_case, imit_sprintf_width_number_s_test);
  tcase_add_test(t_case, imit_sprintf_width_number_s_neg_test);
  tcase_add_test(t_case, imit_sprintf_width_number_s_star_test);
  tcase_add_test(t_case, imit_sprintf_width_number_s_precision_test);
  tcase_add_test(t_case, imit_sprintf_width_number_1_test);
  tcase_add_test(t_case, imit_sprintf_width_number_2_test);

  tcase_add_test(t_case, imit_sprintf_width_number_u_test);
  tcase_add_test(t_case, imit_sprintf_width_number_u_neg_test);
  tcase_add_test(t_case, imit_sprintf_width_number_u_star_test);
  tcase_add_test(t_case, imit_sprintf_width_number_u_precision5_test);
  tcase_add_test(t_case, imit_sprintf_width_number_u_precision2_test);

  tcase_add_test(t_case, imit_sprintf_width_number_x_test);
  tcase_add_test(t_case, imit_sprintf_width_number_x_max_test);
  tcase_add_test(t_case, imit_sprintf_width_number_x_neg_test);
  tcase_add_test(t_case, imit_sprintf_width_number_x_star_test);
  tcase_add_test(t_case, imit_sprintf_width_number_x_precision5_test);
  tcase_add_test(t_case, imit_sprintf_width_number_x_precision2_test);

  tcase_add_test(t_case, imit_sprintf_width_number_X_test);
  tcase_add_test(t_case, imit_sprintf_width_number_X_max_test);
  tcase_add_test(t_case, imit_sprintf_width_number_X_neg_test);
  tcase_add_test(t_case, imit_sprintf_width_number_X_star_test);
  tcase_add_test(t_case, imit_sprintf_width_number_X_precision5_test);
  tcase_add_test(t_case, imit_sprintf_width_number_X_precision2_test);

  tcase_add_test(t_case, imit_sprintf_width_number_p_test);
  tcase_add_test(t_case, imit_sprintf_width_number_p_neg_test);
  tcase_add_test(t_case, imit_sprintf_width_number_p_star_test);
  tcase_add_test(t_case, imit_sprintf_width_number_p_precision_test);

  return suite;
}
