#include <stdio.h>

#include "imit_test.h"

START_TEST(imit_sscanf_test_c_base) {
  char* test_str = "abc";
  char* test_format = "%c%c%c";

  int lib1 = 0, lib2 = 0, lib3 = 0;
  int sc1 = 0, sc2 = 0, sc3 = 0;

  int res = sscanf(test_str, test_format, &lib1, &lib2, &lib3);
  int imitres = imit_sscanf(test_str, test_format, &sc1, &sc2, &sc3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(lib1, sc1);
  ck_assert_int_eq(lib2, sc2);
  ck_assert_int_eq(lib3, sc3);
}
END_TEST

START_TEST(imit_sscanf_test_c_with_space_symbols) {
  char* test_str = "   a   b    c";
  char* test_format = "%c%c%c";

  int lib1 = 0, lib2 = 0, lib3 = 0;
  int sc1 = 0, sc2 = 0, sc3 = 0;

  int res = sscanf(test_str, test_format, &lib1, &lib2, &lib3);
  int imitres = imit_sscanf(test_str, test_format, &sc1, &sc2, &sc3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(lib1, sc1);
  ck_assert_int_eq(lib2, sc2);
  ck_assert_int_eq(lib3, sc3);
}
END_TEST

START_TEST(imit_sscanf_test_c_with_space_symbols_in_format) {
  char* test_str = "   a   b    c";
  char* test_format = "%c %c %c";

  int lib1 = 0, lib2 = 0, lib3 = 0;
  int sc1 = 0, sc2 = 0, sc3 = 0;

  int res = sscanf(test_str, test_format, &lib1, &lib2, &lib3);
  int imitres = imit_sscanf(test_str, test_format, &sc1, &sc2, &sc3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(lib1, sc1);
  ck_assert_int_eq(lib2, sc2);
  ck_assert_int_eq(lib3, sc3);
}
END_TEST

START_TEST(imit_sscanf_test_c_with_space_symbols_in_format_2) {
  char* test_str = "   a   b \t   c  ";
  char* test_format = "     %c     %c     %c    ";

  int lib1 = 0, lib2 = 0, lib3 = 0;
  int sc1 = 0, sc2 = 0, sc3 = 0;

  int res = sscanf(test_str, test_format, &lib1, &lib2, &lib3);
  int imitres = imit_sscanf(test_str, test_format, &sc1, &sc2, &sc3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(lib1, sc1);
  ck_assert_int_eq(lib2, sc2);
  ck_assert_int_eq(lib3, sc3);
}
END_TEST

START_TEST(imit_sscanf_test_c_with_other_space_symbols) {
  char* test_str = "\t   a\n   b \f   c";
  char* test_format = "%c%c%c";

  int lib1 = 0, lib2 = 0, lib3 = 0;
  int sc1 = 0, sc2 = 0, sc3 = 0;

  int res = sscanf(test_str, test_format, &lib1, &lib2, &lib3);
  int imitres = imit_sscanf(test_str, test_format, &sc1, &sc2, &sc3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(lib1, sc1);
  ck_assert_int_eq(lib2, sc2);
  ck_assert_int_eq(lib3, sc3);
}
END_TEST

START_TEST(imit_sscanf_test_c_str_only_space) {
  char* test_str = "\t\n\n\t\f";
  char* test_format = "%c%c%c";

  int lib1 = 0, lib2 = 0, lib3 = 0;
  int sc1 = 0, sc2 = 0, sc3 = 0;

  int res = sscanf(test_str, test_format, &lib1, &lib2, &lib3);
  int imitres = imit_sscanf(test_str, test_format, &sc1, &sc2, &sc3);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(lib1, sc1);
  ck_assert_int_eq(lib2, sc2);
  ck_assert_int_eq(lib3, sc3);
}
END_TEST

START_TEST(imit_sscanf_test_c_base_more_format) {
  char* test_str = "abc";
  char* test_format = "%c%c%c%c";

  int lib1 = 0, lib2 = 0, lib3 = 0, lib4 = 0;
  int sc1 = 0, sc2 = 0, sc3 = 0, sc4 = 0;

  int res = sscanf(test_str, test_format, &lib1, &lib2, &lib3, &lib4);
  int imitres = imit_sscanf(test_str, test_format, &sc1, &sc2, &sc3, &sc4);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(lib1, sc1);
  ck_assert_int_eq(lib2, sc2);
  ck_assert_int_eq(lib3, sc3);
  ck_assert_int_eq(lib4, sc4);
}
END_TEST

START_TEST(imit_sscanf_test_c_base_assignments) {
  char* test_str = "abc";
  char* test_format = "%c%*c%c";

  int lib1 = 0, lib2 = 0, lib3 = 0, lib4 = 0;
  int sc1 = 0, sc2 = 0, sc3 = 0, sc4 = 0;

  int res = sscanf(test_str, test_format, &lib1, &lib2, &lib3, &lib4);
  int imitres = imit_sscanf(test_str, test_format, &sc1, &sc2, &sc3, &sc4);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(lib1, sc1);
  ck_assert_int_eq(lib2, sc2);
  ck_assert_int_eq(lib3, sc3);
  ck_assert_int_eq(lib4, sc4);
}
END_TEST

START_TEST(imit_sscanf_test_c_base_assignments_2) {
  char* test_str = "abc";
  char* test_format = "%*c%*c%*c";

  int lib1 = 0, lib2 = 0, lib3 = 0, lib4 = 0;
  int sc1 = 0, sc2 = 0, sc3 = 0, sc4 = 0;

  int res = sscanf(test_str, test_format, &lib1, &lib2, &lib3, &lib4);
  int imitres = imit_sscanf(test_str, test_format, &sc1, &sc2, &sc3, &sc4);

  ck_assert_int_eq(res, imitres);
  ck_assert_int_eq(lib1, sc1);
  ck_assert_int_eq(lib2, sc2);
  ck_assert_int_eq(lib3, sc3);
  ck_assert_int_eq(lib4, sc4);
}
END_TEST

START_TEST(imit_sscanf_test_19_c_option) {
  char a = 0;
  char b = 0;
  char c = 0;
  char d = 0;

  int result1 = imit_sscanf("a  b", "%c %c", &a, &b);
  int result_origin1 = sscanf("a b", "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  result1 = imit_sscanf(" A B", "%c %c", &a, &b);
  result_origin1 = sscanf(" A B", "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  result1 = imit_sscanf("- -", "%c %c", &a, &b);
  result_origin1 = sscanf("- -", "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char* format_str1 = "123  150";

  result1 = imit_sscanf(format_str1, "%c %c", &a, &b);
  result_origin1 = sscanf(format_str1, "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char* format_str2 = "1 10";

  result1 = imit_sscanf(format_str2, "%c %c", &a, &b);
  result_origin1 = sscanf(format_str2, "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char* format_str3 = "0 0";

  result1 = imit_sscanf(format_str3, "%c %c", &a, &b);
  result_origin1 = sscanf(format_str3, "%c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char* format_str4 = "";

  result1 = imit_sscanf(format_str4, "%*c %c %c", &a, &b);
  result_origin1 = sscanf(format_str4, "%*c %c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  const char* format_str5 = "qwe 1";
  result1 = imit_sscanf(format_str5, "%Lc %c", &a, &b);

  const char* format_str6 = "qwerty";

  result1 = imit_sscanf(format_str6, "%1c %c", &a, &b);
  result_origin1 = sscanf(format_str6, "%1c %c", &c, &d);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a, c);
  ck_assert_int_eq(b, d);

  wchar_t a_w = 0;
  wchar_t b_w = 0;
  wchar_t c_w = 0;
  wchar_t d_w = 0;
  result1 = imit_sscanf("A B", "%lc %lc", &a_w, &b_w);
  result_origin1 = sscanf("A B", "%lc %lc", &c_w, &d_w);
  ck_assert_int_eq(result1, result_origin1);
  ck_assert_int_eq(a_w, c_w);
  ck_assert_int_eq(b_w, d_w);
}

END_TEST

Suite* test_imit_sscanf_c_suite() {
  Suite* suite = suite_create("imit_sscanf_c");
  TCase* t_case = tcase_create("imit_sscanf_c");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_sscanf_test_c_base);
  tcase_add_test(t_case, imit_sscanf_test_c_with_space_symbols);
  tcase_add_test(t_case, imit_sscanf_test_c_with_space_symbols_in_format);
  tcase_add_test(t_case, imit_sscanf_test_c_with_space_symbols_in_format_2);
  tcase_add_test(t_case, imit_sscanf_test_c_with_other_space_symbols);
  tcase_add_test(t_case, imit_sscanf_test_c_str_only_space);
  tcase_add_test(t_case, imit_sscanf_test_c_base_more_format);
  tcase_add_test(t_case, imit_sscanf_test_c_base_assignments);
  tcase_add_test(t_case, imit_sscanf_test_c_base_assignments_2);

  tcase_add_test(t_case, imit_sscanf_test_19_c_option);

  return suite;
}
