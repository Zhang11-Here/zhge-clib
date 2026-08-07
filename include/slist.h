/* zhge-clib/include/slist.h */

#ifndef ZHGEC_SLIST_H
#define ZHGEC_SLIST_H


struct zhgec_slist_node
{
	struct zhgec_slist_node *next;
};



#define zhgec_slist_foreach(ptr, begin, end) \
	for ((ptr) = (begin); (ptr) != (end); (ptr) = (ptr)->next)


#endif

