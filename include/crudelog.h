/* zhge-clib/include/crudelog.h */

#ifndef ZHGEC_CRUDELOG_H
#define ZHGEC_CRUDELOG_H

#include <stdio.h>


#define ZHGEC_CRUDELOG_BASE(level, color, ofile, ...) \
	do { \
		fprintf(ofile, "%s[%s]\t[%s:%d %s]\t", \
				color, level, \
				__FILE__, __LINE__, __func__); \
		fprintf(ofile, __VA_ARGS__); \
		fputs("\x1b[0m" "\n", ofile); \
	} while (0)

/*
 * e.g. ZHGEC_CRUDELOG_ERROR("example %d", code);
 * output: [ERROR] [exam.c:114 func]  example 514
 */

/* error: red */
#define ZHGEC_CRUDELOG_ERROR(...) \
	ZHGEC_CRUDELOG_BASE("ERROR", "\x1b[31m", stderr, __VA_ARGS__)

/* warn: yellow */
#define ZHGEC_CRUDELOG_WARN(...) \
	ZHGEC_CRUDELOG_BASE("WARN", "\x1b[33m", stderr, __VA_ARGS__)

/* info: green */
#define ZHGEC_CRUDELOG_INFO(...) \
	ZHGEC_CRUDELOG_BASE("INFO", "\x1b[32m", stdout, __VA_ARGS__)

/* debug: cyan */
#define ZHGEC_CRUDELOG_DEBUG(...) \
	ZHGEC_CRUDELOG_BASE("DEBUG", "\x1b[36m", stdout, __VA_ARGS__)


#endif

