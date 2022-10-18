#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "CUnit/Basic.h"
#include <ctype.h>
#include <CUnit/Basic.h>
#include <stdbool.h>
#include "init.h"
#include "tests.h"
#include "func.h"
int main()
{
        CU_pSuite pSuite1 = NULL;
        CU_pSuite pSuite2 = NULL;

        if (CUE_SUCCESS != CU_initialize_registry())
        {
                return CU_get_error();
        }

        pSuite1 = CU_add_suite("suite for removing contact frrom a file...", init_suite_remove_contact, clean_suite_remove_contact);

        if (NULL == pSuite1)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

       pSuite2 = CU_add_suite("suite for changing group...", init_suite_ToChgrp, clean_suite_ToChgrp);

        if (NULL == pSuite2)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

        if ((NULL == CU_add_test(pSuite1, "Test for removecontact() in sunny cases", remove_contact_sunnycases)) || (NULL == CU_add_test(pSuite1, "Test for removecontact() in rainy cases", remove_contact_rainycases)))
        {
                CU_cleanup_registry();
                return CU_get_error();
        }

       if ((NULL == CU_add_test(pSuite2, "Test for ToChgrp() in sunny cases", ToChgrp_sunnycases)) || (NULL == CU_add_test(pSuite2, "Test for ToChgrp() in rainy cases", ToChgrp_rainycases)))
        {
                CU_cleanup_registry();
                return CU_get_error();
        }
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
        CU_cleanup_registry();
        return CU_get_error();
}
