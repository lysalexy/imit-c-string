#include "imit_test.h"

START_TEST(imit_strncat_test_found) {
  char src1[10] = "123";
  char dest1[10] = "456";
  char src2[10] = "123";
  char dest2[10] = "456";
  size_t n = 2;
  ck_assert_str_eq(strncat(dest1, src1, n), imit_strncat(dest2, src2, n));
}
END_TEST

Suite *test_imit_strncat_suite() {
  Suite *suite = suite_create("imit_strncat");
  TCase *t_case = tcase_create("imit_strncat");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_strncat_test_found);

  return suite;
}
