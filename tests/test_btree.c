/* zhge-clib/tests/test_btree.c */


#include "crudelog.h"
#include "crudetest.h"
#include "btree.h"

#define OUTPUT(node) \
	ZHGEC_CRUDELOG_DEBUG("%s: %X, L:%X, R:%X", #node, \
			(node), (node)->left, (node)->right)

ZHGEC_CRUDETEST_TEST(test_rotate_left)
{
	struct zhgec_btree_node x, y, a, b, c;
	x.left = &a; x.right = &y;
	y.left = &b; y.right = &c;
	a.left = 0; a.right = 0;
	b.left = 0; b.right = 0;
	c.left = 0; c.right = 0;
	/* x[a,y[b,c]] */

	struct zhgec_btree_node *tree = &x;


	OUTPUT(&x);
	OUTPUT(&y);
	OUTPUT(&a);
	OUTPUT(&b);
	OUTPUT(&c);
	OUTPUT(tree);

	zhgec_btree_rotate_left(&tree);

	OUTPUT(&x);
	OUTPUT(&y);
	OUTPUT(&a);
	OUTPUT(&b);
	OUTPUT(&c);
	OUTPUT(tree);

	ZHGEC_CRUDETEST_FINISH();
}


int main()
{
	ZHGEC_CRUDETEST_RUN(test_rotate_left);

	return 0;
}

