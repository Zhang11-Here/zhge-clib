/* zhge-clib/include/test_crudetest/test_crudetest.c */

#include "crudetest/crudetest.h"

ZHGEC_CRUDETEST_TEST(test_ok)
{
	int num = 10;
	ZHGEC_CRUDETEST_ASSERT(num == 10);
	ZHGEC_CRUDETEST_FINISH();
}

ZHGEC_CRUDETEST_TEST(test_fail)
{
	int num = 10;
	ZHGEC_CRUDETEST_ASSERT(num == 20);
	ZHGEC_CRUDETEST_FINISH();
}

ZHGEC_CRUDETEST_TEST(test_ok_rename)
{
	ZHGEC_CRUDETEST_ASSERT(20 > 10);
	ZHGEC_CRUDETEST_FINISH();
}

ZHGEC_CRUDETEST_TEST(test_fail_rename)
{
	ZHGEC_CRUDETEST_ASSERT(20 < 10);
	ZHGEC_CRUDETEST_FINISH();
}


int main()
{
	ZHGEC_CRUDETEST_RUN(test_ok);
	ZHGEC_CRUDETEST_RUN(test_fail);
	ZHGEC_CRUDETEST_RUN(*&*&test_ok_rename); /* deliberate */
	ZHGEC_CRUDETEST_RUN(*&*&test_fail_rename);

	return 0;
}

