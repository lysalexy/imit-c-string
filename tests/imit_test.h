#ifndef imit_TEST_H_
#define imit_TEST_H_

#include <check.h>
#include <string.h>

#include "../imit_string.h"
#include "stdio.h"

void run_tests();
void run_testcase(Suite *testcase, int counter_testcase);

Suite *test_imit_strncmp_suite();
Suite *test_imit_strncpy_suite();
Suite *test_imit_strncat_suite();
Suite *test_imit_strchr_suite();
Suite *test_imit_memchr_suite();
Suite *test_imit_strcspn_suite();
Suite *test_imit_strlen_suite();
Suite *test_imit_strpbrk_suite();
Suite *test_imit_memcmp_suite();
Suite *test_imit_memcpy_suite();
Suite *test_imit_memset_suite();
Suite *test_imit_strrchr_suite();
Suite *test_imit_strstr_suite();
Suite *test_imit_strtok_suite();
Suite *test_imit_strerror_suite();

Suite *test_imit_to_upper_suite();
Suite *test_imit_to_lower_suite();
Suite *test_imit_insert_suite();
Suite *suite_trim();

Suite *test_imit_sprintf_suite();
Suite *test_imit_sprintf_f_suite();
Suite *test_imit_sprintf_s_suite();
Suite *test_imit_sprintf_precision_suite();
Suite *test_imit_sprintf_e_E_suite();
Suite *test_imit_sprintf_g_G_suite();
Suite *test_imit_sprintf_width_number_suite();
Suite *test_imit_sprintf_o_suite();

Suite *test_imit_sprintf_length_suite();
Suite *test_imit_sprintf_flags_suite();

Suite *simpletest_p1_suite();
Suite *simpletest_sprintf_suite();
Suite *test_imit_sprintf_x_X_suite();
Suite *test_imit_sprintf_p_suite();
Suite *test_imit_sprintf_n_suite();
Suite *test_imit_many_tests();

Suite *test_imit_sscanf_s_suite();
Suite *test_imit_sscanf_c_suite();
Suite *test_imit_sscanf_d_i_suite();
Suite *test_imit_sscanf_p_suite();
Suite *test_imit_sscanf_u_o_x_suite();
Suite *test_imit_sscanf_feg_suite();
Suite *suite_sscanf_n();

#endif