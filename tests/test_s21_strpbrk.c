#include "imit_test.h"

START_TEST(imit_strpbrk_test) {
  ck_assert_pstr_eq(imit_strpbrk("0123456789", "369"),
                    strpbrk("0123456789", "369"));
  ck_assert_pstr_eq(imit_strpbrk("0123456789", "5"), strpbrk("0123456789", "5"));
  ck_assert_pstr_eq(imit_strpbrk("0", "0"), strpbrk("0", "0"));
  ck_assert_pstr_eq(imit_strpbrk("Privet", "e"), strpbrk("Privet", "e"));
  ck_assert_pstr_eq(imit_strpbrk("Lucky", "ky"), strpbrk("Lucky", "ky"));
}
END_TEST

START_TEST(imit_strpbrk_test_not_found) {
  ck_assert_pstr_eq(imit_strpbrk("0000007", "fhh"), strpbrk("0000007", "fhh"));
}
END_TEST

Suite *test_imit_strpbrk_suite() {
  Suite *suite = suite_create("imit_strpbrk");
  TCase *t_case = tcase_create("imit_strpbrk");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_strpbrk_test);
  tcase_add_test(t_case, imit_strpbrk_test_not_found);

  return suite;
}