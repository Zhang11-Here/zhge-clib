/* zhge-clib/tests/test_crudelog.c */


#include "crudelog.h"

int main(void)
{
	ZHGEC_CRUDELOG_ERROR("exam: %d", 10);
	ZHGEC_CRUDELOG_WARN("exam: %d", 20);
	ZHGEC_CRUDELOG_INFO("exam: %d", 30);
	ZHGEC_CRUDELOG_DEBUG("exam: %d", 40);

	printf("now it should be white\n");
	return 0;
}

