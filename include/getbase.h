/* zhge-clib/include/getbase.h */

#ifndef ZHGEC_GETBASE_H
#define ZHGEC_GETBASE_H


#include <stddef.h>


/* e.g.
 * struct test_struct *p = GETBASE(memp, struct test_struct, mem);
 */
#define GETBASE(ptr, type, member) \
	((type *)((char *)(ptr) - offsetof(type, member)))


#endif

