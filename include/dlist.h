/* zhge-clib/include/dlist.h */

#ifndef ZHGEC_DLIST_H
#define ZHGEC_DLIST_H


/*
 * Regulations on dlist behavior:
 * 1) 'dlist' list:  A circular concatenation of nodes.
 * 2) 'dlist' segments:  Only connected nodes or a node.
 * 3) dlist does not manage memory or store data.
 * 4) removed segments can still touch the surrounding nodes.
 * 5) removed segments will not be remembered. Please manage them.
 */
struct zhgec_dlist_node
{
	struct zhgec_dlist_node *prev;
	struct zhgec_dlist_node *next;
};



/*
 * Only force link two nodes.
 * If there is content in the middle, it will be removed.
 * Please know what you are doing.
 * > Init a node into a circle:
 *	zhgec_dlist_link(node, node)
 * > Remove a segment:
 *	zhgec_dlist_link(prev, next)
 */
static inline void zhgec_dlist_link(
		struct zhgec_dlist_node *first,
		struct zhgec_dlist_node *second)
{
	first->next = second;
	second->prev = first;
}

/*
 * Replace the content of (front, back) into [front, back].
 * Old content will be removed.
 * > Insert a node:
 *	zhgec_dlist_replace(node, node, prev, next)
 */
static inline void zhgec_dlist_replace(
		struct zhgec_dlist_node *front,
		struct zhgec_dlist_node *back,
		struct zhgec_dlist_node *prev,
		struct zhgec_dlist_node *next)
{
	zhgec_dlist_link(prev, front);
	zhgec_dlist_link(back, next);
}


/*
 * Traverse through [begin, end).
 * POS will be used multiple times, do not use expressions with side effects.
 * If there is no next one, assign next to NULL and end with NULL;
 * If you only removed the node without destroying, it can be applied.
 */
#define zhgec_dlist_foreach(pos, begin, end) \
	for ((pos) = (begin); (pos) != (end); (pos) = (pos)->next)


/*
 * Reverse traverse through [rbegin, rend).
 * Other matters are the same as zhgec_dlist_foreach.
 */
#define zhgec_dlist_foreach_reverse(pos, rbegin, rend) \
	for ((pos) = (rbegin); (pos) != (rend); (pos) = (pos)->prev)


#endif


