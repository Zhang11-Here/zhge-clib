/* zhge-clib/include/crudetest.h */

#ifndef ZHGEC_CRUDETEST_H
#define ZHGEC_CRUDETEST_H

/*
 * e.g.
 * ZHGEC_CRUDETEST_TEST(test) {
 * 	int num = 10;
 * 	ZHGEC_CRUDETEST_ASSERT(num < 20);
 * 	ZHGEC_CRUDETEST_FINISH();
 * }
 * (( in a function ))
 * ZHGEC_CRUDETEST_RUN(test)
 *
 * output when it is OK:
 * [   OK] test  <<green>>
 * or fail:
 * [ FAIL] test (what you write) <<red>>
 *     -> file: example/file.c
 *     -> line: 114
 *     -> func: test (the real function name)
 *     -> expression:  num < 20
*/


#include <stdio.h>


#define ZHGEC_CRUDETEST_TEST(func) \
	const char *func(const char *const zhgec_crudetest_test_msg)

#define ZHGEC_CRUDETEST_FINISH() \
	do { \
		return (const char *)0; \
	} while (0)

#define ZHGEC_CRUDETEST_ASSERT(expr) \
	do { \
		if (!(expr)) { \
			fprintf(stderr, "\x1b[31m"); \
			fprintf(stderr, "[ FAIL] %s", \
					zhgec_crudetest_test_msg); \
			fprintf(stderr, "\x1b[0m" "\n"); \
			fprintf(stderr, "    -> file: %s\n", __FILE__); \
			fprintf(stderr, "    -> line: %d\n", __LINE__); \
			fprintf(stderr, "    -> func: %s\n", __func__); \
			fprintf(stderr, "    -> expression:  %s\n", #expr); \
			return __func__; \
		} \
	} while (0)


#define ZHGEC_CRUDETEST_RUN(func) \
	do { \
		const char *funcname = (func)(#func); \
		if (funcname == (const char *)0) { \
			printf("\x1b[32m"); \
			printf("[   OK] %s", #func); \
			printf("\x1b[0m" "\n"); \
		} \
	} while (0)

#endif

