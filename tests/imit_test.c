
#include "imit_test.h"

int main() {
  run_tests();

  return 0;
}

void run_testcase(Suite *testcase, int counter_testcase) {
  if (counter_testcase > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_tests(void) {
  int counter_testcase = 0;

  Suite *list_cases[] = {test_imit_memchr_suite(),
                         test_imit_memcmp_suite(),
                         test_imit_memcpy_suite(),
                         test_imit_memset_suite(),
                         test_imit_strrchr_suite(),
                         test_imit_strstr_suite(),
                         test_imit_strtok_suite(),
                         test_imit_strcspn_suite(),
                         test_imit_strlen_suite(),
                         test_imit_strpbrk_suite(),
                         test_imit_strncat_suite(),
                         test_imit_strchr_suite(),
                         test_imit_strncmp_suite(),
                         test_imit_strncpy_suite(),
                         test_imit_sprintf_suite(),
                         test_imit_sprintf_f_suite(),
                         test_imit_to_upper_suite(),
                         test_imit_to_lower_suite(),
                         test_imit_insert_suite(),
                         suite_trim(),
                         test_imit_strerror_suite(),
                         test_imit_sscanf_s_suite(),
                         test_imit_sscanf_c_suite(),
                         test_imit_sscanf_d_i_suite(),
                         test_imit_sscanf_p_suite(),
                         test_imit_sscanf_feg_suite(),
                         test_imit_sscanf_u_o_x_suite(),
                         test_imit_sprintf_s_suite(),
                         test_imit_sprintf_precision_suite(),
                         test_imit_sprintf_width_number_suite(),
                         test_imit_sprintf_e_E_suite(),
                         test_imit_sprintf_g_G_suite(),
                         test_imit_sprintf_e_E_suite(),
                         test_imit_sprintf_o_suite(),
                         test_imit_sprintf_x_X_suite(),
                         test_imit_sprintf_p_suite(),
                         test_imit_sprintf_n_suite(),
                         test_imit_sprintf_length_suite(),
                         test_imit_sprintf_flags_suite(),
                         suite_sscanf_n(),
                         test_imit_many_tests(),
                         NULL};

  for (Suite **current_testcase = list_cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase, counter_testcase);
    counter_testcase++;
  }
}
