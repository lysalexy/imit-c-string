#include "imit_test.h"

START_TEST(imit_strchr_test_found) {
  const char str[] = "Hello World!";
  int c = 'o';
  char *res = imit_strchr(str, c);
  ck_assert_ptr_ne(res, NULL);
  ck_assert_int_eq(res - str, strchr(str, c) - str);
}
END_TEST

START_TEST(imit_strchr_test_not_found) {
  const char str[] = "Hello World!";
  int c = 'y';
  char *res = imit_strchr(str, c);
  ck_assert_ptr_eq(res, strchr(str, c));
}
END_TEST

Suite *test_imit_strchr_suite() {
  Suite *suite = suite_create("imit_strchr");
  TCase *t_case = tcase_create("imit_strchr");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_strchr_test_found);
  tcase_add_test(t_case, imit_strchr_test_not_found);

  return suite;
}
