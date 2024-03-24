#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sscanf_test_p_1) {
  char* test_str = "0xFFFF 0xAAAA 0x7123";
  char* test_format = "%p %p %p";

  int *libdata1 = 0, *libdata2 = 0, *libdata3 = 0;
  int *imitdata1 = 0, *imitdata2 = 0, *imitdata3 = 0;

  int16_t res = sscanf(test_str, test_format, &libdata1, &libdata2, &libdata3);
  int16_t imitres =
      imit_sscanf(test_str, test_format, &imitdata1, &imitdata2, &imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_ptr_eq(libdata1, imitdata1);
  ck_assert_ptr_eq(libdata2, imitdata2);
  ck_assert_ptr_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_p_2) {
  char* test_str = "0xFFFF 123 0";
  char* test_format = "%p %p %p";

  int *libdata1 = 0, *libdata2 = 0, *libdata3 = 0;
  int *imitdata1 = 0, *imitdata2 = 0, *imitdata3 = 0;

  int16_t res = sscanf(test_str, test_format, &libdata1, &libdata2, &libdata3);
  int16_t imitres =
      imit_sscanf(test_str, test_format, &imitdata1, &imitdata2, &imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_ptr_eq(libdata1, imitdata1);
  ck_assert_ptr_eq(libdata2, imitdata2);
  ck_assert_ptr_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_p_3) {
  char* test_str = "0xFFFF sss 0";
  char* test_format = "%p %p %p";

  int *libdata1 = 0, *libdata2 = 0, *libdata3 = 0;
  int *imitdata1 = 0, *imitdata2 = 0, *imitdata3 = 0;

  int16_t res = sscanf(test_str, test_format, &libdata1, &libdata2, &libdata3);
  int16_t imitres =
      imit_sscanf(test_str, test_format, &imitdata1, &imitdata2, &imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_ptr_eq(libdata1, imitdata1);
  ck_assert_ptr_eq(libdata2, imitdata2);
  ck_assert_ptr_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_p_4) {
  char* test_str = "\t  \n0xFFFF sss 0";
  char* test_format = "%p %p %p";

  int *libdata1 = 0, *libdata2 = 0, *libdata3 = 0;
  int *imitdata1 = 0, *imitdata2 = 0, *imitdata3 = 0;

  int16_t res = sscanf(test_str, test_format, &libdata1, &libdata2, &libdata3);
  int16_t imitres =
      imit_sscanf(test_str, test_format, &imitdata1, &imitdata2, &imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_ptr_eq(libdata1, imitdata1);
  ck_assert_ptr_eq(libdata2, imitdata2);
  ck_assert_ptr_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_p_5) {
  char* test_str = "0xFFFF 123 0";
  char* test_format = "%*p %p %p";

  int *libdata1 = 0, *libdata2 = 0, *libdata3 = 0;
  int *imitdata1 = 0, *imitdata2 = 0, *imitdata3 = 0;

  int16_t res = sscanf(test_str, test_format, &libdata1, &libdata2, &libdata3);
  int16_t imitres =
      imit_sscanf(test_str, test_format, &imitdata1, &imitdata2, &imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_ptr_eq(libdata1, imitdata1);
  ck_assert_ptr_eq(libdata2, imitdata2);
  ck_assert_ptr_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_p_6) {
  char* test_str = "0xFFFF 123 0";
  char* test_format = "%*p %*p %*p";

  int *libdata1 = 0, *libdata2 = 0, *libdata3 = 0;
  int *imitdata1 = 0, *imitdata2 = 0, *imitdata3 = 0;

  int16_t res = sscanf(test_str, test_format, &libdata1, &libdata2, &libdata3);
  int16_t imitres =
      imit_sscanf(test_str, test_format, &imitdata1, &imitdata2, &imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_ptr_eq(libdata1, imitdata1);
  ck_assert_ptr_eq(libdata2, imitdata2);
  ck_assert_ptr_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_p_more_format) {
  char* test_str = "0xFFFF 123";
  char* test_format = "%p %p %p";

  int *libdata1 = 0, *libdata2 = 0, *libdata3 = 0;
  int *imitdata1 = 0, *imitdata2 = 0, *imitdata3 = 0;

  int16_t res = sscanf(test_str, test_format, &libdata1, &libdata2, &libdata3);
  int16_t imitres =
      imit_sscanf(test_str, test_format, &imitdata1, &imitdata2, &imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_ptr_eq(libdata1, imitdata1);
  ck_assert_ptr_eq(libdata2, imitdata2);
  ck_assert_ptr_eq(libdata3, imitdata3);
}
END_TEST

Suite* test_imit_sscanf_p_suite() {
  Suite* suite = suite_create("imit_sscanf_p");
  TCase* t_case = tcase_create("imit_sscanf_p");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_sscanf_test_p_1);
  tcase_add_test(t_case, imit_sscanf_test_p_2);
  tcase_add_test(t_case, imit_sscanf_test_p_3);
  tcase_add_test(t_case, imit_sscanf_test_p_4);
  tcase_add_test(t_case, imit_sscanf_test_p_5);
  tcase_add_test(t_case, imit_sscanf_test_p_6);
  tcase_add_test(t_case, imit_sscanf_test_p_more_format);

  return suite;
}
