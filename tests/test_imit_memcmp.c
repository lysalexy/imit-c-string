#include "imit_test.h"

START_TEST(imit_memcmp_test) {
  ck_assert_uint_eq(imit_memcmp("Hello", "Hello", 5),
                    memcmp("Hello", "Hello", 5));
  ck_assert_uint_eq(imit_memcmp("Hllo", "Hello", 5), memcmp("Hllo", "Hello", 5));
  ck_assert_uint_eq(imit_memcmp("Hello", "Hllo", 5), memcmp("Hello", "Hllo", 5));
  ck_assert_uint_eq(imit_memcmp("Hello", "Hllo", 0), memcmp("Hello", "Hllo", 0));
  ck_assert_uint_eq(imit_memcmp("Hello", "Hello", 10),
                    memcmp("Hello", "Hello", 10));
  ck_assert_uint_eq(imit_memcmp("s", "s", 1), memcmp("s", "s", 1));
}
END_TEST

Suite *test_imit_memcmp_suite() {
  Suite *suite = suite_create("imit_memcmp");
  TCase *t_case = tcase_create("imit_memcmp");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_memcmp_test);

  return suite;
}