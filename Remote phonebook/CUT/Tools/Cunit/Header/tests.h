#include <func.h>
void remove_contact_sunnycases(void)
{
        CU_ASSERT_EQUAL(removecontact("a","testing"),1);
        CU_ASSERT_EQUAL(removecontact("b","testing"),1);
        CU_ASSERT_EQUAL(removecontact("c","testing"),1);
}

void remove_contact_rainycases(void)
{
        CU_ASSERT_EQUAL(removecontact("shreyas","testing"),0);
        CU_ASSERT_EQUAL(removecontact("siraj","testing"),0);
        CU_ASSERT_EQUAL(removecontact("chahar","testing"),0);
}

void ToChgrp_sunnycases(void)
{
        CU_ASSERT_EQUAL(ToChgrp("rohit","testing"),1);
        CU_ASSERT_EQUAL(ToChgrp("kohli","marketing"),1);
        CU_ASSERT_EQUAL(ToChgrp("surya","production"),1);
}
void ToChgrp_rainycases(void)
{
        CU_ASSERT_EQUAL(ToChgrp("bumrah","production"),0);
        CU_ASSERT_EQUAL(ToChgrp("arshdeep","testing"),0);
        CU_ASSERT_EQUAL(ToChgrp("chahal","marketing"),0);
}

void AuthenticatedAddData_sunnycases(void)
{
        CU_ASSERT_EQUAL(AuthenticatedAddData("add1","123","production"),1);
        CU_ASSERT_EQUAL(AuthenticatedAddData("add2","123","marketing"),1);
        CU_ASSERT_EQUAL(AuthenticatedAddData("add4","123","testing"),1);
}
void AuthenticatedAddData_rainycases(void)
{
        CU_ASSERT_EQUAL(AuthenticatedAddData("bumrah","1",""),0);
        CU_ASSERT_EQUAL(AuthenticatedAddData("arshdeep","2","public group"),0);
        CU_ASSERT_EQUAL(AuthenticatedAddData("arshdeep","2","public group"),0);
}

void Tolistcontact_sunnycases(void)
{
        CU_ASSERT_EQUAL(Tolistcontact("a","production"),1);
        CU_ASSERT_EQUAL(Tolistcontact("ad","marketing"),1);
        CU_ASSERT_EQUAL(Tolistcontact("add4","testing"),1);
}
void Tolistcontact_rainycases(void)
{
        CU_ASSERT_EQUAL(Tolistcontact("bumrah",""),0);
        CU_ASSERT_EQUAL(Tolistcontact("arshdeep","production"),0);
        CU_ASSERT_EQUAL(Tolistcontact("narendra","testing"),0);
}

