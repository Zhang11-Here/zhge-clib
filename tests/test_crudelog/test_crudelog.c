// zhge-clib/tests/test_crudelog/test_crudelog.c


#include "crudelog/crudelog.h"

int main(void)
{
	ZHGEC_CRUDELOG_ERROR("error: %d", 10);
	ZHGEC_CRUDELOG_WARN("warn: %d", 20);
	ZHGEC_CRUDELOG_INFO("info: %d", 30);
	ZHGEC_CRUDELOG_DEBUG("debug: %d", 40);
	printf("now it should be white\n");
	return 0;
}

