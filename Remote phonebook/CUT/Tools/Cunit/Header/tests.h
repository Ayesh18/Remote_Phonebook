void remove_contact_sunnycases(void)
{
        CU_ASSERT_EQUAL(removecontact("sec","testing"),1);
        CU_ASSERT_EQUAL(removecontact("second","testing"),1);
        CU_ASSERT_EQUAL(removecontact("fir","testing"),1);
        CU_ASSERT_EQUAL(removecontact("first","testing"),1);
        CU_ASSERT_EQUAL(removecontact("surya","testing"),1);
}

void remove_contact_rainycases(void)
{
        CU_ASSERT_EQUAL(removecontact("shreyas","testing"),1);
        CU_ASSERT_EQUAL(removecontact("siraj","testing"),1);
        CU_ASSERT_EQUAL(removecontact("chahar","testing"),0);
        CU_ASSERT_EQUAL(removecontact("shardul","testing"),0);
        CU_ASSERT_EQUAL(removecontact("umesh","testing"),0);
}

void ToChgrp_sunnycases(void)
{
        CU_ASSERT_EQUAL(ToChgrp("rohit","testing"),1);
        CU_ASSERT_EQUAL(ToChgrp("kohli","marketing"),1);
        CU_ASSERT_EQUAL(ToChgrp("surya","production"),1);
        CU_ASSERT_EQUAL(ToChgrp("karthik","testing"),1);
        CU_ASSERT_EQUAL(ToChgrp("shreyas","production"),1);
}
void ToChgrp_rainycases(void)
{
        CU_ASSERT_EQUAL(ToChgrp("bumrah","production"),0);
        CU_ASSERT_EQUAL(ToChgrp("arshdeep","testing"),1);
        CU_ASSERT_EQUAL(ToChgrp("chahal","marketing"),0);
        CU_ASSERT_EQUAL(ToChgrp("shami","production"),0);
        CU_ASSERT_EQUAL(ToChgrp("siraj","marketing"),0);
}
