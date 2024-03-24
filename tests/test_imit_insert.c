#include "imit_test.h"

START_TEST(imit_insert_test_found) {
  char *result = imit_insert("Hello", "Nem", 0);
  ck_assert_str_eq(result, "NemHello");
  free(result);

  char *result_2 = imit_insert("Hello", "Nemo", 5);
  ck_assert_str_eq(result_2, "HelloNemo");
  free(result_2);

  char *result_3 = imit_insert("Hello", "Nemo", 4);
  ck_assert_str_eq(result_3, "HellNemoo");
  free(result_3);

  char *result_4 = imit_insert("Hello", "Neml", 4);
  ck_assert_str_eq(result_4, "HellNemlo");
  free(result_4);

  char *result_5 = imit_insert("Hello", "Nem", 1);
  ck_assert_str_eq(result_5, "HNemello");
  free(result_5);
}
END_TEST

START_TEST(imit_insert_test_not_found) {
  void *result = imit_insert(imit_NULL, imit_NULL, 1);
  ck_assert_ptr_eq(result, imit_NULL);

  void *result_2 = imit_insert("Hello", imit_NULL, 1);
  ck_assert_ptr_eq(result_2, imit_NULL);

  void *result_3 = imit_insert(imit_NULL, "Nemo", 1);
  ck_assert_ptr_eq(result_3, imit_NULL);

  void *result_4 = imit_insert("Hello", "nemo", 6);
  ck_assert_ptr_eq(result_4, imit_NULL);
}
END_TEST

Suite *test_imit_insert_suite() {
  Suite *suite = suite_create("imit_insert");
  TCase *t_case = tcase_create("imit_insert");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_insert_test_found);
  tcase_add_test(t_case, imit_insert_test_not_found);

  return suite;
}