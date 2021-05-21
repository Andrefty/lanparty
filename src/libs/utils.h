#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>


#define TEST_FILE1 "../date/t1/d.in"
#define TEST_FILE2 "../data/data2.txt"
#define READ_MODE "r+"

/**
 * @brief 
 * //TODO: Completeaza sectiunea
 * @param filename 
 * @param mode 
 * @return FILE* 
 */
FILE *openFile(const char *filename, const char *mode);

/**
 * @brief 
 * 
 * @param argument 
 * @return true or false
 */
bool isNull(void *argument);


/**
 * @brief 
 * 
 * @param argument 
 * @return true or false
 */
bool isNotNull(void *argument);

