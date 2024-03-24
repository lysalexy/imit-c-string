#include "imit_test.h"

START_TEST(imit_to_lower_test_found) {
  char *result = imit_to_lower("Hello");
  ck_assert_str_eq(result, "hello");
  free(result);

  char *result_2 = imit_to_lower("Hello1");
  ck_assert_str_eq(result_2, "hello1");
  free(result_2);

  char *result_3 = imit_to_lower("HELLO");
  ck_assert_str_eq(result_3, "hello");
  free(result_3);
}
END_TEST

START_TEST(imit_to_lower_test_not_found) {
  ck_assert_ptr_eq(imit_to_lower(imit_NULL), imit_NULL);
}
END_TEST

Suite *test_imit_to_lower_suite() {
  Suite *suite = suite_create("imit_to_lower");
  TCase *t_case = tcase_create("imit_to_lower");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_to_lower_test_found);
  tcase_add_test(t_case, imit_to_lower_test_not_found);

  return suite;
}