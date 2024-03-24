#include "imit_test.h"

#if defined(__linux__)
START_TEST(imit_strerror_test) {
  for (int i = 0; i < 134; i++) {
    ck_assert_str_eq(imit_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(imit_strerror_test_not_found) {
  for (int i = 134; i < 200; i++) {
    ck_assert_str_eq(imit_strerror(i), strerror(i));
  }
  for (int e = -200; e < 0; e++) {
    ck_assert_str_eq(imit_strerror(e), strerror(e));
  }
}
END_TEST

#elif defined(__APPLE__)
START_TEST(imit_strerror_test) {
  for (int i = 0; i < 107; i++) {
    ck_assert_str_eq(imit_strerror(i), strerror(i));
  }
}
END_TEST

START_TEST(imit_strerror_test_not_found) {
  for (int i = 107; i < 200; i++) {
    ck_assert_str_eq(imit_strerror(i), strerror(i));
  }
  for (int e = -200; e < 0; e++) {
    ck_assert_str_eq(imit_strerror(e), strerror(e));
  }
}
END_TEST

#endif

Suite *test_imit_strerror_suite() {
  Suite *suite = suite_create("imit_strerror");
  TCase *t_case = tcase_create("imit_strerror");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_strerror_test);
  tcase_add_test(t_case, imit_strerror_test_not_found);

  return suite;
}