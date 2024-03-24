#include "imit_test.h"

START_TEST(imit_memchr_test_found) {
  ck_assert_ptr_eq(imit_memchr("Hello", 'l', 5), memchr("Hello", 'l', 5));
  ck_assert_ptr_eq(imit_memchr("Hello", 'l', 3), memchr("Hello", 'l', 3));
  ck_assert_ptr_eq(imit_memchr("Hello", 'l', 10), memchr("Hello", 'l', 10));
  ck_assert_ptr_eq(imit_memchr("Hello", 'H', 5), memchr("Hello", 'H', 5));
  ck_assert_ptr_eq(imit_memchr("Hello", 'o', 5), memchr("Hello", 'o', 5));
  ck_assert_ptr_eq(imit_memchr("Hello", '\0', 5), memchr("Hello", '\0', 5));
  ck_assert_ptr_eq(imit_memchr("", '\0', 5), memchr("", '\0', 5));
}
END_TEST

START_TEST(imit_memchr_test_not_found) {
  ck_assert_ptr_eq(imit_memchr("Hello", 'w', 5), memchr("Hello", 'w', 5));
  ck_assert_ptr_eq(imit_memchr("Hello", 'l', 2), memchr("Hello", 'l', 2));
  ck_assert_ptr_eq(imit_memchr("Hello", '\0', 2), memchr("Hello", '\0', 2));
}
END_TEST

Suite *test_imit_memchr_suite() {
  Suite *suite = suite_create("imit_memchr");
  TCase *t_case = tcase_create("imit_memchr");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_memchr_test_found);
  tcase_add_test(t_case, imit_memchr_test_not_found);

  return suite;
}