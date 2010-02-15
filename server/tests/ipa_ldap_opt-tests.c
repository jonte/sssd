/*
   SSSD

   Tests if IPA and LDAP backend options are in sync

   Authors:
       Jakub Hrozek <jhrozek@redhat.com>

   Copyright (C) 2010 Red Hat

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <check.h>
#include <stdlib.h>

#include "providers/ipa/ipa_common.h"
#include "providers/ldap/sdap.h"

START_TEST(test_check_num_opts)
{
    fail_if(IPA_OPTS_BASIC_TEST != SDAP_OPTS_BASIC);
}
END_TEST

Suite *ipa_ldap_opt_suite (void)
{
    Suite *s = suite_create ("ipa_ldap_opt");

    TCase *tc_ipa_ldap_opt = tcase_create ("ipa_ldap_opt");

    tcase_add_test (tc_ipa_ldap_opt, test_check_num_opts);
    suite_add_tcase (s, tc_ipa_ldap_opt);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s = ipa_ldap_opt_suite ();
    SRunner *sr = srunner_create (s);
    /* If CK_VERBOSITY is set, use that, otherwise it defaults to CK_NORMAL */
    srunner_run_all(sr, CK_ENV);
    number_failed = srunner_ntests_failed (sr);
    srunner_free (sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
