/* zhge-clib/include/btree.h */

#ifndef ZHGEC_BTREE_H
#define ZHGEC_BTREE_H


/*
 * A binary tree.
 * Node does not have a pointer to its parent node.
 */
struct zhgec_btree_node
{
	struct zhgec_btree_node *left;
	struct zhgec_btree_node *right;
};


/*
 * Rotate left. Oprate on (**pnode).
 */
static inline void zhgec_btree_rotate_left(
		struct zhgec_btree_node **pnode)
{
	struct zhgec_btree_node *parent = *pnode;
	struct zhgec_btree_node *child = parent->right;
	*pnode = child;
	parent->right = child->left;
	child->left = parent;
}

/*
 * Rotate right. Oprate on (**pnode).
 */
static inline void zhgec_btree_rotate_right(
		struct zhgec_btree_node **pnode)
{
	struct zhgec_btree_node *parent = *pnode;
	struct zhgec_btree_node *child = parent->left;
	*pnode = child;
	parent->left = child->right;
	child->right = parent;
}

#endif

