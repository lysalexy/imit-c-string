#include <stdio.h>

#include "imit_test.h"

START_TEST(EOF1) {
  char fstr[] = "%d ";
  char str[] = "  ";
  int16_t a1 = 0, a2 = 0;

  int16_t res1 = imit_sscanf(str, fstr, &a1);
  int16_t res2 = sscanf(str, fstr, &a2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(imit_sscanf_test_empty_string) {
  int libdata, imitdata;

  int res = sscanf("", "%d", &libdata);
  int imitres = imit_sscanf("", "%d", &imitdata);

  ck_assert_int_eq(res, imitres);
}
END_TEST

START_TEST(imit_sscanf_test_s_1) {
  char* test_str = "Hello";
  char* test_format = "%s";

  char libdata[100], imitdata[100];

  int res = sscanf(test_str, test_format, libdata);
  int imitres = imit_sscanf(test_str, test_format, imitdata);

  ck_assert_int_eq(res, imitres);
  ck_assert_str_eq(libdata, imitdata);
}
END_TEST

START_TEST(imit_sscanf_test_s_3_1) {
  char* test_str = "Hello imit school";
  char* test_format = "%s %s %s";

  char libdata1[100], libdata2[100], libdata3[100];
  char imitdata1[100], imitdata2[100], imitdata3[100];

  int res = sscanf(test_str, test_format, libdata1, libdata2, libdata3);
  int imitres = imit_sscanf(test_str, test_format, imitdata1, imitdata2, imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_str_eq(libdata1, imitdata1);
  ck_assert_str_eq(libdata2, imitdata2);
  ck_assert_str_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_s_3_2) {
  char* test_str = "Hello imit school";
  char* test_format = "%s%s%s";

  char libdata1[100], libdata2[100], libdata3[100];
  char imitdata1[100], imitdata2[100], imitdata3[100];

  int res = sscanf(test_str, test_format, libdata1, libdata2, libdata3);
  int imitres = imit_sscanf(test_str, test_format, imitdata1, imitdata2, imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_str_eq(libdata1, imitdata1);
  ck_assert_str_eq(libdata2, imitdata2);
  ck_assert_str_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_s_3_3) {
  char* test_str = "Hello imit school";
  char* test_format = "\t%s  %s  %s\n";

  char libdata1[100], libdata2[100], libdata3[100];
  char imitdata1[100], imitdata2[100], imitdata3[100];

  int res = sscanf(test_str, test_format, libdata1, libdata2, libdata3);
  int imitres = imit_sscanf(test_str, test_format, imitdata1, imitdata2, imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_str_eq(libdata1, imitdata1);
  ck_assert_str_eq(libdata2, imitdata2);
  ck_assert_str_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_s_assignment_1) {
  char* test_str = "Hello imit school";
  char* test_format = "%*s%s%s";

  char libdata1[100] = "", libdata2[100] = "", libdata3[100] = "";
  char imitdata1[100] = "", imitdata2[100] = "", imitdata3[100] = "";

  int res = sscanf(test_str, test_format, libdata1, libdata2, libdata3);
  int imitres = imit_sscanf(test_str, test_format, imitdata1, imitdata2, imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_str_eq(libdata1, imitdata1);
  ck_assert_str_eq(libdata2, imitdata2);
  ck_assert_str_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_s_assignment_2) {
  char* test_str = "Hello imit school";
  char* test_format = "%*s%*s%s";

  char libdata1[100] = "", libdata2[100] = "", libdata3[100] = "";
  char imitdata1[100] = "", imitdata2[100] = "", imitdata3[100] = "";

  int res = sscanf(test_str, test_format, libdata1, libdata2, libdata3);
  int imitres = imit_sscanf(test_str, test_format, imitdata1, imitdata2, imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_str_eq(libdata1, imitdata1);
  ck_assert_str_eq(libdata2, imitdata2);
  ck_assert_str_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_s_assignment_3) {
  char* test_str = "Hello imit school";
  char* test_format = "%*s%*s%*s";

  char libdata1[100] = "", libdata2[100] = "", libdata3[100] = "";
  char imitdata1[100] = "", imitdata2[100] = "", imitdata3[100] = "";

  int res = sscanf(test_str, test_format, libdata1, libdata2, libdata3);
  int imitres = imit_sscanf(test_str, test_format, imitdata1, imitdata2, imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_str_eq(libdata1, imitdata1);
  ck_assert_str_eq(libdata2, imitdata2);
  ck_assert_str_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_s_width) {
  char* test_str = "Hello imit school";
  char* test_format = "%1s %2s %20s";

  char libdata1[100] = "", libdata2[100] = "", libdata3[100] = "";
  char imitdata1[100] = "", imitdata2[100] = "", imitdata3[100] = "";

  int res = sscanf(test_str, test_format, libdata1, libdata2, libdata3);
  int imitres = imit_sscanf(test_str, test_format, imitdata1, imitdata2, imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_str_eq(libdata1, imitdata1);
  ck_assert_str_eq(libdata2, imitdata2);
  ck_assert_str_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_s_l) {
  char* test_str = "Hello asdadadqweqweasdasdasdasdad Hello";
  char* test_format = "%ls %ls %s";

  char libdata1[100] = "", libdata2[100] = "", libdata3[100] = "";
  char imitdata1[100] = "", imitdata2[100] = "", imitdata3[100] = "";

  int res = sscanf(test_str, test_format, libdata1, libdata2, libdata3);
  int imitres = imit_sscanf(test_str, test_format, imitdata1, imitdata2, imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_str_eq(libdata1, imitdata1);
  ck_assert_str_eq(libdata2, imitdata2);
  ck_assert_str_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_more_format) {
  char* test_str = "Hello imit school";
  char* test_format = "%s%s%s%s";

  char libdata1[100], libdata2[100], libdata3[100], libdata4[100];
  char imitdata1[100], imitdata2[100], imitdata3[100], imitdata4[100];

  int res =
      sscanf(test_str, test_format, libdata1, libdata2, libdata3, libdata4);
  int imitres =
      imit_sscanf(test_str, test_format, imitdata1, imitdata2, imitdata3, imitdata4);

  ck_assert_int_eq(res, imitres);
  ck_assert_str_eq(libdata1, imitdata1);
  ck_assert_str_eq(libdata2, imitdata2);
  ck_assert_str_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_more_format_with_space) {
  char* test_str = "Hello imit school   \n";
  char* test_format = "%s%s%s%s";

  char libdata1[100], libdata2[100], libdata3[100], libdata4[100];
  char imitdata1[100], imitdata2[100], imitdata3[100], imitdata4[100];

  int res =
      sscanf(test_str, test_format, libdata1, libdata2, libdata3, libdata4);
  int imitres =
      imit_sscanf(test_str, test_format, imitdata1, imitdata2, imitdata3, imitdata4);

  ck_assert_int_eq(res, imitres);
  ck_assert_str_eq(libdata1, imitdata1);
  ck_assert_str_eq(libdata2, imitdata2);
  ck_assert_str_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_s_ll) {
  char* test_str = "Hello imit school";
  char* test_format = "%lls %s %s";

  char libdata1[100] = "", libdata2[100] = "", libdata3[100] = "";
  char imitdata1[100] = "", imitdata2[100] = "", imitdata3[100] = "";

  int res = sscanf(test_str, test_format, libdata1, libdata2, libdata3);
  int imitres = imit_sscanf(test_str, test_format, imitdata1, imitdata2, imitdata3);

  ck_assert_int_eq(res, imitres);
  ck_assert_str_eq(libdata1, imitdata1);
  ck_assert_str_eq(libdata2, imitdata2);
  ck_assert_str_eq(libdata3, imitdata3);
}
END_TEST

START_TEST(imit_sscanf_test_20_s_option) {
  char array[256] = {0};
  char array_origin[256] = {0};

  int result = imit_sscanf("12345 36", "%s", array);
  int result_origin = sscanf("12345 36", "%s", array_origin);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(array, array_origin);

  char array1[256] = {0};
  char array_origin1[256] = {0};

  result = imit_sscanf("Hello Dotan", "%s", array1);
  result_origin = sscanf("Hello Dotan", "%s", array_origin1);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(array1, array_origin1);

  char array2[256] = {0};
  char array_origin2[256] = {0};

  result = imit_sscanf("", "%s", array2);
  result_origin = sscanf("", "%s", array_origin2);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(array2, array_origin2);

  char array3[256] = {0};
  char array_origin3[256] = {0};

  result = imit_sscanf("", "%s", array3);
  result_origin = sscanf("", "%s", array_origin3);
  ck_assert_int_eq(result, result_origin);
  ck_assert_str_eq(array3, array_origin3);

  wchar_t array_t_1[999] = {0};
  wchar_t array_t_2[999] = {0};
  wchar_t array_t_3[999] = {0};
  wchar_t array_t_4[999] = {0};

  result = imit_sscanf("qwerty", "%4ls%ls", array_t_1, array_t_3);
  result_origin = sscanf("qwerty", "%4ls%ls", array_t_2, array_t_4);
  ck_assert_str_eq((char*)array_t_1, (char*)array_t_2);
  ck_assert_str_eq((char*)array_t_3, (char*)array_t_4);
  ck_assert_int_eq(result, result_origin);
}

END_TEST

Suite* test_imit_sscanf_s_suite() {
  Suite* suite = suite_create("imit_sscanf_s");
  TCase* t_case = tcase_create("imit_sscanf_s");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, EOF1);
  tcase_add_test(t_case, imit_sscanf_test_empty_string);
  tcase_add_test(t_case, imit_sscanf_test_s_1);
  tcase_add_test(t_case, imit_sscanf_test_s_3_1);
  tcase_add_test(t_case, imit_sscanf_test_s_3_2);
  tcase_add_test(t_case, imit_sscanf_test_s_3_3);
  tcase_add_test(t_case, imit_sscanf_test_s_assignment_1);
  tcase_add_test(t_case, imit_sscanf_test_s_assignment_2);
  tcase_add_test(t_case, imit_sscanf_test_s_assignment_3);
  tcase_add_test(t_case, imit_sscanf_test_s_width);
  tcase_add_test(t_case, imit_sscanf_test_s_l);
  tcase_add_test(t_case, imit_sscanf_test_more_format);
  tcase_add_test(t_case, imit_sscanf_test_more_format_with_space);
  tcase_add_test(t_case, imit_sscanf_test_s_ll);
  tcase_add_test(t_case, imit_sscanf_test_20_s_option);

  return suite;
}
