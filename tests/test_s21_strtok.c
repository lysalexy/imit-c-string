#include "imit_test.h"

START_TEST(imit_strtok_test_2_tokens_slash_delim) {
  char imit_string_slash_2[] = "Hello/friend";
  char string_slash_2[] = "Hello/friend";

  ck_assert_str_eq(imit_strtok(imit_string_slash_2, "/"),
                   strtok(string_slash_2, "/"));
  ck_assert_str_eq(imit_strtok(imit_NULL, "/"), strtok(imit_NULL, "/"));

  char imit_string_slash[] = "Hello/friend/";
  char string_slash[] = "Hello/friend/";

  ck_assert_str_eq(imit_strtok(imit_string_slash, "/"),
                   strtok(string_slash, "/"));
  ck_assert_str_eq(imit_strtok(imit_NULL, "/"), strtok(imit_NULL, "/"));
}
END_TEST

START_TEST(imit_strtok_test_2_tokens_space_delim) {
  char imit_string_space[] = "Hello friend";
  char string_space[] = "Hello friend";
  ck_assert_str_eq(imit_strtok(imit_string_space, " "),
                   strtok(string_space, " "));
  ck_assert_str_eq(imit_strtok(imit_NULL, " "), strtok(imit_NULL, " "));
}
END_TEST

START_TEST(imit_strtok_test_2_tokens_several_delims) {
  char imit_string_space_slash[] = "Hello /friend";
  char string_space_slash[] = "Hello /friend";
  ck_assert_str_eq(imit_strtok(imit_string_space_slash, " /"),
                   strtok(string_space_slash, " /"));
  ck_assert_str_eq(imit_strtok(imit_NULL, " /"), strtok(imit_NULL, " /"));
}
END_TEST

START_TEST(imit_strtok_test_not_found) {
  ck_assert_ptr_eq(imit_strtok("Hello", "/"), strtok("Hello", "/"));
  ck_assert_ptr_eq(imit_strtok(imit_NULL, "/"), strtok(imit_NULL, "/"));
  ck_assert_ptr_eq(imit_strtok(imit_NULL, "/"), strtok(imit_NULL, "/"));
}
END_TEST

Suite *test_imit_strtok_suite() {
  Suite *suite = suite_create("imit_strtok");
  TCase *t_case = tcase_create("imit_strtok");

  suite_add_tcase(suite, t_case);
  tcase_add_test(t_case, imit_strtok_test_2_tokens_slash_delim);
  tcase_add_test(t_case, imit_strtok_test_2_tokens_space_delim);
  tcase_add_test(t_case, imit_strtok_test_2_tokens_several_delims);
  tcase_add_test(t_case, imit_strtok_test_not_found);

  return suite;
}