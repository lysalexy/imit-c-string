#include "imit_test.h"

START_TEST(imit_strlen_test) {
  ck_assert_int_eq(imit_strlen("0123456789"), strlen("0123456789"));
  ck_assert_int_eq(imit_strlen("Hello"), strlen("Hello"));
  ck_assert_int_eq(imit_strlen("PrivetPrivetPokaPoka"),
                   strlen("PrivetPrivetPokaPoka"));
  ck_assert_int_eq(imit_strlen("095"), strlen("095"));
  ck_assert_int_eq(imit_strlen("boba"), strlen("boba"));
}
END_TEST

START_TEST(imit_strlen_test_not_found) {
  ck_assert_int_eq(imit_strlen(""), strlen(""));
}
END_TEST

Suite *test_imit_strlen_suite() {
  Suite *suite = suite_create("imit_strlen");
  TCase *t_case = tcase_create("imit_strlen");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_strlen_test);
  tcase_add_test(t_case, imit_strlen_test_not_found);

  return suite;
}
