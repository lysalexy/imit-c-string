#include "imit_test.h"

START_TEST(imit_strncpy_test_found) {
  char src[] = "12345";
  char dest1[] = "00000";
  char dest2[] = "00000";
  size_t n = 5;
  ck_assert_str_eq(strncpy(dest1, src, n), imit_strncpy(dest2, src, n));
}
END_TEST

START_TEST(imit_strncpy_test_found_end) {
  char src[] = "123\00045";
  char dest1[] = "00000";
  char dest2[] = "00000";
  size_t n = 5;
  ck_assert_str_eq(strncpy(dest1, src, n), imit_strncpy(dest2, src, n));
}
END_TEST

START_TEST(imit_strncpy_test_found_endstart) {
  char src[] = "\00012345";
  char dest1[] = "00000";
  char dest2[] = "00000";
  size_t n = 5;
  ck_assert_str_eq(strncpy(dest1, src, n), imit_strncpy(dest2, src, n));
}
END_TEST

Suite *test_imit_strncpy_suite() {
  Suite *suite = suite_create("imit_strncpy");
  TCase *t_case = tcase_create("imit_strncpy");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_strncpy_test_found);
  tcase_add_test(t_case, imit_strncpy_test_found_end);
  tcase_add_test(t_case, imit_strncpy_test_found_endstart);
  return suite;
}
