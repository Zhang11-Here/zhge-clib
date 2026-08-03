/* zhge-clib/tests/test_getbase.c */

#include "crudelog.h"
#include "crudetest.h"
#include "getbase.h"


struct test_struct
{
	int mem1;
	int mem2;
};

ZHGEC_CRUDETEST_TEST(test_getbase_common)
{
	struct test_struct st;
	st.mem1 = 10;
	st.mem2 = 20;

	int *p2 = &st.mem2;
	struct test_struct *p = GETBASE(p2, struct test_struct, mem2);
	ZHGEC_CRUDETEST_ASSERT(p == &st);

	ZHGEC_CRUDETEST_FINISH();
}

ZHGEC_CRUDETEST_TEST(test_getbase_write)
{
	struct test_struct st;
	st.mem1 = 10;
	st.mem2 = 20;

	int *p2 = &st.mem2;
	struct test_struct *p = GETBASE(p2, struct test_struct, mem2);
	p->mem1 = 40;
	ZHGEC_CRUDETEST_ASSERT(st.mem1 == 40);

	ZHGEC_CRUDETEST_FINISH();
}


int main(void)
{
	ZHGEC_CRUDETEST_RUN(test_getbase_common);
	ZHGEC_CRUDETEST_RUN(test_getbase_write);

	return 0;
}

