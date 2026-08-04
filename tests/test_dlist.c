/* zhge-clib/tests/test_dlist.c */

#include "crudelog.h"
#include "crudetest.h"
#include "dlist.h"

ZHGEC_CRUDETEST_TEST(test_init)
{
	struct zhgec_dlist_node head;

	zhgec_dlist_link(&head, &head);

	ZHGEC_CRUDETEST_ASSERT(head.next == &head);
	ZHGEC_CRUDETEST_ASSERT(head.prev == &head);

	ZHGEC_CRUDETEST_FINISH();
}

ZHGEC_CRUDETEST_TEST(test_replace)
{
	struct zhgec_dlist_node head;
	zhgec_dlist_link(&head, &head);

	struct zhgec_dlist_node node1;
	struct zhgec_dlist_node node2;

	zhgec_dlist_replace(&node1, &node1, &head, &head);
	zhgec_dlist_replace(&node2, &node2, &node1, &head);

	ZHGEC_CRUDETEST_ASSERT(head.next == &node1);
	ZHGEC_CRUDETEST_ASSERT(node1.next == &node2);
	ZHGEC_CRUDETEST_ASSERT(node2.next == &head);
	ZHGEC_CRUDETEST_ASSERT(head.prev == &node2);
	ZHGEC_CRUDETEST_ASSERT(node2.prev == &node1);
	ZHGEC_CRUDETEST_ASSERT(node1.prev == &head);

	ZHGEC_CRUDETEST_FINISH();
}

ZHGEC_CRUDETEST_TEST(test_foreach)
{
	struct zhgec_dlist_node head;
	zhgec_dlist_link(&head, &head);

	struct zhgec_dlist_node node1;
	struct zhgec_dlist_node node2;

	zhgec_dlist_replace(&node1, &node1, &head, &head);
	zhgec_dlist_replace(&node2, &node2, &node1, &head);

	ZHGEC_CRUDELOG_INFO("head: %X", &head);
	ZHGEC_CRUDELOG_INFO("node1: %X", &node1);
	ZHGEC_CRUDELOG_INFO("node2: %X", &node2);

	struct zhgec_dlist_node *pos;
	zhgec_dlist_foreach(pos, head.next, &head)
		ZHGEC_CRUDELOG_INFO("pos: %X", pos);

	zhgec_dlist_foreach_reverse(pos, head.prev, &head)
		ZHGEC_CRUDELOG_INFO("pos: %X", pos);

	ZHGEC_CRUDETEST_FINISH();
}



int main(void)
{
	ZHGEC_CRUDELOG_INFO("test: zhgec-dlist-test_foreach");

	ZHGEC_CRUDETEST_RUN(test_init);
	ZHGEC_CRUDETEST_RUN(test_replace);
	ZHGEC_CRUDETEST_RUN(test_foreach);

	return 0;
}

