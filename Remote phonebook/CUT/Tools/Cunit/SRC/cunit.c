#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "CUnit/Basic.h"
#include "CUnit/Automated.h"
#include <ctype.h>
#include <CUnit/Basic.h>
#include <init.h>
#include <tests.h>

int main()
{
        CU_pSuite pSuite1 = NULL;
        CU_pSuite pSuite2 = NULL;
		CU_pSuite pSuite3 = NULL;
		CU_pSuite pSuite4 = NULL;
		
        if (CUE_SUCCESS != CU_initialize_registry())
        {
                return CU_get_error();
        }

        pSuite1 = CU_add_suite("suite for removing contact from a file...", init_suite_remove_contact, clean_suite_remove_contact);

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
		
		pSuite3 = CU_add_suite("suite for adding contact...", init_suite_AuthenticatedAddData, clean_suite_AuthenticatedAddData);

        if (NULL == pSuite3)
        {
                CU_cleanup_registry();
                return CU_get_error();
        }
        
        pSuite4 = CU_add_suite("suite for listing contact...", init_suite_Tolistcontact, clean_suite_Tolistcontact);

        if (NULL == pSuite4)
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
        
        if ((NULL == CU_add_test(pSuite3, "Test for AuthenticatedAddData() in sunny cases", AuthenticatedAddData_sunnycases)) || (NULL == CU_add_test(pSuite3, "Test for AuthenticatedAddData() in rainy cases", AuthenticatedAddData_rainycases)))
        {
                CU_cleanup_registry();
                return CU_get_error();
        }
        
        if ((NULL == CU_add_test(pSuite4, "Test for Tolistcontact() in sunny cases", Tolistcontact_sunnycases)) || (NULL == CU_add_test(pSuite4, "Test for Tolistcontact() in rainy cases", Tolistcontact_rainycases)))
        {
                CU_cleanup_registry();
                return CU_get_error();
        }
        
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
        printf("\n");
	   CU_basic_show_failures(CU_get_failure_list());
	   printf("\n\n");

	   /* Run all tests using the automated interface */
	   CU_automated_run_tests();
	   CU_list_tests_to_file();
	   
        CU_cleanup_registry();
        return CU_get_error();
}
