#include "imit_test.h"

START_TEST(imit_memset_test_dst_empty) {
  char dst1[5] = "";
  char dst2[5] = "";

  ck_assert_str_eq(imit_memset(dst1, 's', 1), memset(dst2, 's', 1));
  ck_assert_str_eq(imit_memset(dst1, 's', 3), memset(dst2, 's', 3));
  ck_assert_str_eq(imit_memset(dst1, 's', 4), memset(dst2, 's', 4));
  ck_assert_str_eq(imit_memset(dst1, 0, 4), memset(dst2, 0, 4));
  ck_assert_str_eq(imit_memset(dst1, '1', 4), memset(dst2, '1', 4));
}
END_TEST

START_TEST(imit_memset_test_dst_not_empty) {
  char dst1[20] = "Hello, world";
  char dst2[20] = "Hello, world";

  ck_assert_str_eq(imit_memset(dst1, 's', 1), memset(dst2, 's', 1));
  ck_assert_str_eq(imit_memset(dst1, 's', 5), memset(dst2, 's', 5));
  ck_assert_str_eq(imit_memset(dst1, 's', 13), memset(dst2, 's', 13));
}
END_TEST

START_TEST(imit_memset_test_dst_with_zero) {
  char dst1[12] = "Hello\0 world";
  char dst2[12] = "Hello\0 world";

  ck_assert_str_eq(imit_memset(dst1, 's', 1), memset(dst2, 's', 1));
  ck_assert_str_eq(imit_memset(dst1, 's', 5), memset(dst2, 's', 5));
}
END_TEST

Suite *test_imit_memset_suite() {
  Suite *suite = suite_create("imit_memset");
  TCase *t_case = tcase_create("imit_memset");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_memset_test_dst_empty);
  tcase_add_test(t_case, imit_memset_test_dst_not_empty);
  tcase_add_test(t_case, imit_memset_test_dst_with_zero);

  return suite;
}