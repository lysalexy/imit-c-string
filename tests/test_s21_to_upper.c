#include "imit_test.h"

START_TEST(imit_to_upper_test_found) {
  char *result = imit_to_upper("Hello");
  ck_assert_str_eq(result, "HELLO");
  free(result);

  char *result_2 = imit_to_upper("Hello1");
  ck_assert_str_eq(result_2, "HELLO1");
  free(result_2);

  char *result_3 = imit_to_upper("HELLO");
  ck_assert_str_eq(result_3, "HELLO");
  free(result_3);
}
END_TEST

START_TEST(imit_to_upper_test_not_found) {
  ck_assert_ptr_eq(imit_to_upper(imit_NULL), imit_NULL);
}
END_TEST

Suite *test_imit_to_upper_suite() {
  Suite *suite = suite_create("imit_to_upper");
  TCase *t_case = tcase_create("imit_to_upper");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_to_upper_test_found);
  tcase_add_test(t_case, imit_to_upper_test_not_found);

  return suite;
}