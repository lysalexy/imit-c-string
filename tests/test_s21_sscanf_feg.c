#include "imit_test.h"

START_TEST(floats1) {
  long double a1 = 1, a2 = 0, b1 = 1, b2 = 0, c1 = 1, c2 = 0, d1 = 1, d2 = 0;

  const char str[] = "53.1 -4.1135 41.3333 +2.0001";
  const char fstr[] = "%Lf %Lf %Lf %Lf";

  int16_t res1 = imit_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats2) {
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = "0.00001 -4123123 4. .";
  const char fstr[] = "%lf %lf %lf %lf";

  int16_t res1 = imit_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats2_more_format) {
  double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0, f1 = 0,
         f2 = 0;

  char str[] = "0.00001 -4123123 4. .";
  const char fstr[] = "%lf %lf %lf %lf %lf";

  int16_t res1 = imit_sscanf(str, fstr, &a1, &b1, &c1, &d1, &f1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2, &f2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
  ck_assert_double_eq(f1, f2);
}
END_TEST

START_TEST(floats3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  char str[] = ". . . .";
  const char fstr[] = "%f %f %f %f";

  int16_t res1 = imit_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats4) {
  long double a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "513.41 -4.14135 414.3333 +112.0001";
  const char fstr[] = "%Lf %Lf %Lf %Lf";

  int16_t res1 = imit_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats5) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

  const char str[] = "53.1 -4.1135 411231.333 +2.0001";
  const char fstr[] = "%*f %f %f %f";

  int16_t res1 = imit_sscanf(str, fstr, &a1, &b1, &c1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_eq(a1, a2);
  ck_assert_float_eq(b1, b2);
  ck_assert_float_eq(c1, c2);
}
END_TEST

START_TEST(floats_sci1) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "1.4441 1.31e+4 -3.31e-4 0.444e-5";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = imit_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_double_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats_sci2) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "inf 1.31e+4 NaN 0.444e-5";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = imit_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  // Unfortunately, assertions for inf do not work correctly in libcheck
  // ck_assert_ldouble_infinite(a1);
  // ck_assert_ldouble_infinite(a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_float_nan(c1);
  ck_assert_float_nan(c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats_sci3) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "inF InF inF INF";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = imit_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_ldouble_eq(a1, a2);
  ck_assert_double_eq(b1, b2);
  ck_assert_double_eq(c1, c2);
  ck_assert_double_eq(d1, d2);
}
END_TEST

START_TEST(floats_sci4) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] = "Nan NAN 0.0000 0";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = imit_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_float_nan(b1);
  ck_assert_float_nan(b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

START_TEST(floats_sci5) {
  float a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0, d1 = 0, d2 = 0;

  const char str[] =
      "nAN           INF                   -0.1111         1e-10";
  const char fstr[] = "%G %G %G %G";

  int16_t res1 = imit_sscanf(str, fstr, &a1, &b1, &c1, &d1);
  int16_t res2 = sscanf(str, fstr, &a2, &b2, &c2, &d2);

  ck_assert_int_eq(res1, res2);
  ck_assert_float_nan(a1);
  ck_assert_float_nan(a2);
  ck_assert_ldouble_eq(b1, b2);
  ck_assert_ldouble_eq(c1, c2);
  ck_assert_ldouble_eq(d1, d2);
}
END_TEST

START_TEST(imit_sscanf_test_21_f_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = imit_sscanf("0.1234 123", "%f %f", &a, &b);
  int result_origin = sscanf("0.1234 123", "%f %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 123.123456789", "%f %f", &a, &b);
  result_origin = sscanf(".1234 123.123456789", "%f %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 -123.123456789", "%f %f", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%f %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 -123.123456789", "%f %6f", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%f %6f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("3.402823466E+38", "%f", &a);
  result_origin = sscanf("3.402823466E+38", "%f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("10.402823466E+38", "%f", &a);
  result_origin = sscanf("10.402823466E+38", "%f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("1.175494351E–38", "%f", &a);
  result_origin = sscanf("1.175494351E–38", "%f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("10.175494351E–38", "%f", &a);
  result_origin = sscanf("10.175494351E–38", "%f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = imit_sscanf("3.4E-4932", "%Lf", &al);
  result_origin = sscanf("3.4E-4932", "%Lf", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("30.4E-4932", "%Lf", &al);
  result_origin = sscanf("30.4E-4932", "%Lf", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("3.4E+4932", "%Lf", &al);
  result_origin = sscanf("3.4E+4932", "%Lf", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("30.4E+4932", "%Lf", &al);
  result_origin = sscanf("30.4E+4932", "%Lf", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(imit_sscanf_test_21_g_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = imit_sscanf("0.12 123", "%g %g", &a, &b);
  int result_origin = sscanf("0.12 123", "%g %g", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 123.123456789", "%g %g", &a, &b);
  result_origin = sscanf(".1234 123.123456789", "%g %g", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 -123.123456789", "%g %6g", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%g %6g", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 -123.12E+2", "%g %g", &a, &b);
  result_origin = sscanf(".1234 -123.12E+2", "%g %g", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("1.175494351E–38", "%g", &a);
  result_origin = sscanf("1.175494351E–38", "%g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("10.175494351E–38", "%g", &a);
  result_origin = sscanf("10.175494351E–38", "%g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("3.402823466E+38", "%g", &a);
  result_origin = sscanf("3.402823466E+38", "%g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("30.402823466E+38", "%g", &a);
  result_origin = sscanf("30.402823466E+38", "%g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = imit_sscanf("3.4E-4932", "%Lg", &al);
  result_origin = sscanf("3.4E-4932", "%Lg", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("30.4E-4932", "%Lg", &al);
  result_origin = sscanf("30.4E-4932", "%Lg", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("3.4E+4932", "%Lg", &al);
  result_origin = sscanf("3.4E+4932", "%Lg", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("30.4E+4932", "%Lg", &al);
  result_origin = sscanf("30.4E+4932", "%Lg", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(imit_sscanf_test_21_G_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = imit_sscanf("0.12 123", "%G %G", &a, &b);
  int result_origin = sscanf("0.12 123", "%G %G", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 123.123456789", "%G %G", &a, &b);
  result_origin = sscanf(".1234 123.123456789", "%G %G", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 -123.123456789", "%G %6G", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%G %6G", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 -123.12E+2", "%G %G", &a, &b);
  result_origin = sscanf(".1234 -123.12E+2", "%G %G", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("1.175494351E–38", "%G", &a);
  result_origin = sscanf("1.175494351E–38", "%G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("10.175494351E–38", "%G", &a);
  result_origin = sscanf("10.175494351E–38", "%G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("3.402823466E+38", "%G", &a);
  result_origin = sscanf("3.402823466E+38", "%G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("30.402823466E+38", "%G", &a);
  result_origin = sscanf("30.402823466E+38", "%G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = imit_sscanf("3.4E-4932", "%LG", &al);
  result_origin = sscanf("3.4E-4932", "%LG", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("30.4E-4932", "%LG", &al);
  result_origin = sscanf("30.4E-4932", "%LG", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("3.4E+4932", "%LG", &al);
  result_origin = sscanf("3.4E+4932", "%LG", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("30.4E+4932", "%LG", &al);
  result_origin = sscanf("30.4E+4932", "%LG", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(imit_sscanf_test_21_e_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = imit_sscanf("0.12 123", "%e %e", &a, &b);
  int result_origin = sscanf("0.12 123", "%e %e", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 -123.123456789", "%e %6e", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%e %6e", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 123.123456789e+5", "%e %e", &a, &b);
  result_origin = sscanf(".1234 123.123456789e+5", "%e %e", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 -123.12E+2", "%e %e", &a, &b);
  result_origin = sscanf(".1234 -123.12E+2", "%e %e", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("1.175494351E–38", "%e", &a);
  result_origin = sscanf("1.175494351E–38", "%e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("10.175494351E–38", "%e", &a);
  result_origin = sscanf("10.175494351E–38", "%e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("3.402823466E+38", "%e", &a);
  result_origin = sscanf("3.402823466E+38", "%e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("30.402823466E+38", "%e", &a);
  result_origin = sscanf("30.402823466E+38", "%e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = imit_sscanf("3.4E-4932", "%Le", &al);
  result_origin = sscanf("3.4E-4932", "%Le", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("30.4E-4932", "%Le", &al);
  result_origin = sscanf("30.4E-4932", "%Le", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("3.4E+4932", "%Le", &al);
  result_origin = sscanf("3.4E+4932", "%Le", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("30.4E+4932", "%Le", &al);
  result_origin = sscanf("30.4E+4932", "%Le", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(imit_sscanf_test_21_E_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = imit_sscanf("0.12 123", "%E %E", &a, &b);
  int result_origin = sscanf("0.12 123", "%E %E", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 -123.123456789", "%E %6E", &a, &b);
  result_origin = sscanf(".1234 -123.123456789", "%E %6E", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 123.123456789E+5", "%E %E", &a, &b);
  result_origin = sscanf(".1234 123.123456789E+5", "%E %E", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf(".1234 -123.12E+2", "%E %E", &a, &b);
  result_origin = sscanf(".1234 -123.12E+2", "%E %E", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("1.175494351E–38", "%E", &a);
  result_origin = sscanf("1.175494351E–38", "%E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("10.175494351E–38", "%E", &a);
  result_origin = sscanf("10.175494351E–38", "%E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("3.402823466E+38", "%E", &a);
  result_origin = sscanf("3.402823466E+38", "%E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("30.402823466E+38", "%E", &a);
  result_origin = sscanf("30.402823466E+38", "%E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  long double al = 0;
  long double cl = 0;

  result = imit_sscanf("3.4E-4932", "%LE", &al);
  result_origin = sscanf("3.4E-4932", "%LE", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("30.4E-4932", "%LE", &al);
  result_origin = sscanf("30.4E-4932", "%LE", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("3.4E+4932", "%LE", &al);
  result_origin = sscanf("3.4E+4932", "%LE", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);

  al = 0;
  cl = 0;

  result = imit_sscanf("30.4E+4932", "%LE", &al);
  result_origin = sscanf("30.4E+4932", "%LE", &cl);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(al, cl);
}

END_TEST

START_TEST(imit_sscanf_test_21_percent_option) {
  float a = 0;
  float b = 0;
  float c = 0;
  float d = 0;

  int result = imit_sscanf("1.55 % 2", "%f %% %f", &a, &b);
  int result_origin = sscanf("1.55 % 2", "%f %% %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("1.55 2", "%f %% %f", &a, &b);
  result_origin = sscanf("1.55 2", "%f %% %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("% 1.55 2", "%f %% %f", &a, &b);
  result_origin = sscanf("% 1.55 2", "%f %% %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);

  a = 0;
  b = 0;
  c = 0;
  d = 0;

  result = imit_sscanf("% 1.55 2", "%%%f %f", &a, &b);
  result_origin = sscanf("% 1.55 2", "%%%f %f", &c, &d);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
  ck_assert_float_eq(b, d);
}

END_TEST

START_TEST(imit_sscanf_test_21_star_option) {
  float a = 0;
  float c = 0;

  int result = imit_sscanf(".1234 123.123456789e-5", "%*E %E", &a);
  int result_origin = sscanf(".1234 123.123456789e-5", "%*E %E", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  c = 0;

  result = imit_sscanf(".1234 123.123456789E-5", "%*e %e", &a);
  result_origin = sscanf(".1234 123.123456789E-5", "%*e %e", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  c = 0;

  result = imit_sscanf(".1234 123.123456789", "%*G %G", &a);
  result_origin = sscanf(".1234 123.123456789", "%*G %G", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  c = 0;

  result = imit_sscanf(".1234 123.123456789", "%*g %g", &a);
  result_origin = sscanf(".1234 123.123456789", "%*g %g", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);

  a = 0;
  c = 0;

  result = imit_sscanf(".1234 123.123456789", "%*f %f", &a);
  result_origin = sscanf(".1234 123.123456789", "%*f %f", &c);
  ck_assert_int_eq(result, result_origin);
  ck_assert_float_eq(a, c);
}
END_TEST

Suite *test_imit_sscanf_feg_suite(void) {
  Suite *s = suite_create("imit_sscanf_feg");
  TCase *tc = tcase_create("sscanf_tc");

  tcase_add_test(tc, floats1);
  tcase_add_test(tc, floats2);
  tcase_add_test(tc, floats2_more_format);
  tcase_add_test(tc, floats3);
  tcase_add_test(tc, floats4);
  tcase_add_test(tc, floats5);

  tcase_add_test(tc, floats_sci1);
  tcase_add_test(tc, floats_sci2);
  tcase_add_test(tc, floats_sci3);
  tcase_add_test(tc, floats_sci4);
  tcase_add_test(tc, floats_sci5);

  tcase_add_test(tc, imit_sscanf_test_21_f_option);
  tcase_add_test(tc, imit_sscanf_test_21_g_option);
  tcase_add_test(tc, imit_sscanf_test_21_G_option);
  tcase_add_test(tc, imit_sscanf_test_21_e_option);
  tcase_add_test(tc, imit_sscanf_test_21_E_option);
  tcase_add_test(tc, imit_sscanf_test_21_percent_option);
  tcase_add_test(tc, imit_sscanf_test_21_star_option);

  suite_add_tcase(s, tc);
  return s;
}