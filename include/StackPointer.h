#ifndef _STACK_POINTER_H
#define _STACK_POINTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ELEMENTS 500
#define MAX_LENGTH_STRING 100

#ifdef __cplusplus
extern "C" {
#endif
	char** stack;
	int stackPointer;

	void push(const char* value);
	char* peek();
	char* pop();
#ifdef __cplusplus
}
#endif
#endif
