#include "imit_test.h"

START_TEST(imit_strrchr_test_found) {
  ck_assert_ptr_eq(imit_strrchr("Hello", 'H'), strrchr("Hello", 'H'));
  ck_assert_ptr_eq(imit_strrchr("Hello", 'e'), strrchr("Hello", 'e'));
  ck_assert_ptr_eq(imit_strrchr("Hello", 'l'), strrchr("Hello", 'l'));
  ck_assert_ptr_eq(imit_strrchr("Hello", '\0'), strrchr("Hello", '\0'));
}
END_TEST

START_TEST(imit_strrchr_test_not_found) {
  ck_assert_ptr_eq(imit_strrchr("Hello", 'r'), strrchr("Hello", 'r'));
}
END_TEST

Suite *test_imit_strrchr_suite() {
  Suite *suite = suite_create("imit_strrchr");
  TCase *t_case = tcase_create("imit_strrchr");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_strrchr_test_found);
  tcase_add_test(t_case, imit_strrchr_test_not_found);

  return suite;
}