/* zhge-clib/include/crudelog.h */

#ifndef ZHGEC_CRUDELOG_H
#define ZHGEC_CRUDELOG_H

#include <stdio.h>


/*
 * LEVEL_OFF    => off
 * LEVEL_ERROR  => ERROR
 * LEVEL_WARN   => WARN ERROR
 * LEVEL_INFO   => INFO WARN ERROR
 * LEVEL_DEBUG  => DEBUG INFO WARN ERROR
 * LEVEL_MAX    => all
 */

#define ZHGEC_CRUDELOG_LEVEL_OFF    0
#define ZHGEC_CRUDELOG_LEVEL_ERROR  1
#define ZHGEC_CRUDELOG_LEVEL_WARN   2
#define ZHGEC_CRUDELOG_LEVEL_INFO   3
#define ZHGEC_CRUDELOG_LEVEL_DEBUG  4
#define ZHGEC_CRUDELOG_LEVEL_MAX    5

/* default: ZHGEC_CRUDELOG_LEVEL_DEBUG */
#ifndef ZHGEC_CRUDELOG_LEVEL
#define ZHGEC_CRUDELOG_LEVEL ZHGEC_CRUDELOG_LEVEL_DEBUG
#endif


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
 * error: red
 */
#if ZHGEC_CRUDELOG_LEVEL >= ZHGEC_CRUDELOG_LEVEL_ERROR
#define ZHGEC_CRUDELOG_ERROR(...) \
	ZHGEC_CRUDELOG_BASE("ERROR", "\x1b[31m", stderr, __VA_ARGS__)
#else
#define ZHGEC_CRUDELOG_ERROR(...) ((void)0)
#endif

/* warn: yellow */
#if ZHGEC_CRUDELOG_LEVEL >= ZHGEC_CRUDELOG_LEVEL_WARN
#define ZHGEC_CRUDELOG_WARN(...) \
	ZHGEC_CRUDELOG_BASE("WARN", "\x1b[33m", stderr, __VA_ARGS__)
#else
#define ZHGEC_CRUDELOG_WARN(...) ((void)0)
#endif

/* info: green */
#if ZHGEC_CRUDELOG_LEVEL >= ZHGEC_CRUDELOG_LEVEL_INFO
#define ZHGEC_CRUDELOG_INFO(...) \
	ZHGEC_CRUDELOG_BASE("INFO", "\x1b[32m", stdout, __VA_ARGS__)
#else
#define ZHGEC_CRUDELOG_INFO(...) ((void)0)
#endif

/* info: cyan */
#if ZHGEC_CRUDELOG_LEVEL >= ZHGEC_CRUDELOG_LEVEL_DEBUG
#define ZHGEC_CRUDELOG_DEBUG(...) \
	ZHGEC_CRUDELOG_BASE("DEBUG", "\x1b[36m", stdout, __VA_ARGS__)
#else
#define ZHGEC_CRUDELOG_DEBUG(...) ((void)0)
#endif


#endif

