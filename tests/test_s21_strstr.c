#include "imit_test.h"

START_TEST(imit_strstr_test_found) {
  ck_assert_ptr_eq(imit_strstr("Hello", "Hell"), strstr("Hello", "Hell"));
  ck_assert_ptr_eq(imit_strstr("Hello", "elo"), strstr("Hello", "elo"));
  ck_assert_ptr_eq(imit_strstr("Hello", "l"), strstr("Hello", "l"));
  ck_assert_ptr_eq(imit_strstr("Hello", ""), strstr("Hello", ""));
}
END_TEST

START_TEST(imit_strstr_test_not_found) {
  ck_assert_ptr_eq(imit_strstr("Hello", "r"), strstr("Hello", "r"));
  ck_assert_ptr_eq(imit_strstr("Hello", "Hello1"), strstr("Hello", "Hello1"));
}
END_TEST

Suite *test_imit_strstr_suite() {
  Suite *suite = suite_create("imit_strstr");
  TCase *t_case = tcase_create("imit_strstr");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_strstr_test_found);
  tcase_add_test(t_case, imit_strstr_test_not_found);

  return suite;
}