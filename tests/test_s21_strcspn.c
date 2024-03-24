#include "imit_test.h"

START_TEST(imit_strcspn_test) {
  ck_assert_int_eq(imit_strcspn("0123456789", "9876"),
                   strcspn("0123456789", "9876"));
  ck_assert_int_eq(imit_strcspn("0123456789", "23"),
                   strcspn("0123456789", "23"));
  ck_assert_int_eq(imit_strcspn("0000007", "0"), strcspn("0000007", "0"));
  ck_assert_int_eq(imit_strcspn("Privet", "iv"), strcspn("Privet", "iv"));
  ck_assert_int_eq(imit_strcspn("Privet", "pvt"), strcspn("Privet", "pvt"));
}
END_TEST

START_TEST(imit_strcspn_test_not_found) {
  ck_assert_int_eq(imit_strcspn("0000007", "fhh"), strcspn("0000007", "fhh"));
}
END_TEST

Suite *test_imit_strcspn_suite() {
  Suite *suite = suite_create("imit_strcspn");
  TCase *t_case = tcase_create("imit_strcspn");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_strcspn_test);
  tcase_add_test(t_case, imit_strcspn_test_not_found);

  return suite;
}
