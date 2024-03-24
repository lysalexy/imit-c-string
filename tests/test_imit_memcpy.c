#include "imit_test.h"

START_TEST(imit_memcpy_test_str_eq) {
  char src[20] = "Hello world";

  char dst1[20] = "";
  char dst2[20] = "";

  ck_assert_str_eq(imit_memcpy(dst1, src, 0), memcpy(dst2, src, 0));
  ck_assert_str_eq(imit_memcpy(dst1, src, 1), memcpy(dst2, src, 1));
  ck_assert_str_eq(imit_memcpy(dst1, src, 5), memcpy(dst2, src, 5));
  ck_assert_str_eq(imit_memcpy(dst1, src, 11), memcpy(dst2, src, 11));
  ck_assert_str_eq(imit_memcpy(dst1, src, 20), memcpy(dst2, src, 20));
  ck_assert_str_eq(imit_memcpy(dst1, src, 0), memcpy(dst2, src, 20));
  ck_assert_str_eq(imit_memcpy(dst1, src, 3), memcpy(dst2, src, 3));
  ck_assert_str_eq(imit_memcpy(dst1, src, 11), memcpy(dst2, src, 5));
}
END_TEST

START_TEST(imit_memcpy_test_mem_eq) {
  char src[20] = "Hello world";

  char dst1[20] = "";
  char dst2[20] = "";

  imit_memcpy(dst1, src, 0);
  memcpy(dst2, src, 0);
  ck_assert_mem_eq(dst1, dst2, 0);

  imit_memcpy(dst1, src, 5);
  memcpy(dst2, src, 5);
  ck_assert_mem_eq(dst1, dst2, 5);

  imit_memcpy(dst1, src, 11);
  memcpy(dst2, src, 11);
  ck_assert_mem_eq(dst1, dst2, 11);

  imit_memcpy(dst1, src, 20);
  memcpy(dst2, src, 20);
  ck_assert_mem_eq(dst1, dst2, 20);
}
END_TEST

START_TEST(imit_memcpy_test_str_empty) {
  char src[20] = "";

  char dst1[20] = "";
  char dst2[20] = "";

  ck_assert_str_eq(imit_memcpy(dst1, src, 1), memcpy(dst2, src, 1));
}
END_TEST

START_TEST(imit_memcpy_test_dst_not_empty) {
  char src[20] = "hello";

  char dst1[20] = "test ";
  char dst2[20] = "test ";

  ck_assert_str_eq(imit_memcpy(dst1, src, 5), memcpy(dst2, src, 5));
}
END_TEST

START_TEST(imit_memcpy_test_str_with_zero) {
  char src[20] = "hello \0world";

  char dst1[20] = "test ";
  char dst2[20] = "test ";

  ck_assert_str_eq(imit_memcpy(dst1, src, 20), memcpy(dst2, src, 20));
}
END_TEST

Suite *test_imit_memcpy_suite() {
  Suite *suite = suite_create("imit_memcpy");
  TCase *t_case = tcase_create("imit_memcpy");

  suite_add_tcase(suite, t_case);

  tcase_add_test(t_case, imit_memcpy_test_str_eq);
  tcase_add_test(t_case, imit_memcpy_test_mem_eq);
  tcase_add_test(t_case, imit_memcpy_test_str_empty);
  tcase_add_test(t_case, imit_memcpy_test_dst_not_empty);
  tcase_add_test(t_case, imit_memcpy_test_str_with_zero);

  return suite;
}