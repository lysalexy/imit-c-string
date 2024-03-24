#include "imit_test.h"

START_TEST(imit_strncmp_test_found) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  ck_assert_int_eq(strncmp(str1, str2, 6), imit_strncmp(str1, str2, 6));
}
END_TEST

START_TEST(imit_strncmp_test_with_null) {
  ck_assert(imit_strncmp(imit_NULL, imit_NULL, 0) == 0);
}
END_TEST

START_TEST(imit_strncmp_test_empty) {
  char *str1 = "  ";
  char *str2 = "  ";
  ck_assert_int_eq(imit_strncmp(str1, str2, 3), strncmp(str1, str2, 3));
}
END_TEST

START_TEST(floppa_) {
  char str1[] = "floppa";
  char str2[] = "";
  imit_size_t n_byte = 0;

  int got = imit_strncmp(str1, str2, n_byte);
  int expected = strncmp(str1, str2, n_byte);

  if (got > 1) got = 1;
  if (expected > 1) expected = 1;

  if (got < -1) got = -1;
  if (expected < -1) expected = -1;

  ck_assert_int_eq(got, expected);
}
END_TEST

Suite *test_imit_strncmp_suite() {
  Suite *suite = suite_create("imit_strncmp");
  TCase *t_case = tcase_create("imit_strncmp");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_strncmp_test_found);
  tcase_add_test(t_case, imit_strncmp_test_with_null);
  tcase_add_test(t_case, imit_strncmp_test_empty);
  tcase_add_test(t_case, floppa_);

  return suite;
}
