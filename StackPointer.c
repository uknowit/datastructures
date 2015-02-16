#include "include/StackPointer.h"

void push(const char* value)
{
	if(stackPointer <= MAX_ELEMENTS)
	{	
		stack[stackPointer] = (char*)malloc(sizeof(char)*MAX_LENGTH_STRING);
		strcpy(stack[stackPointer],value);
	}
	else
	{
		printf("STACK is FULL...POP SOME ELEMENTS BEFORE PUSHING!!!!");
	}
	stackPointer++;	
}

char* peek()
{
	char* returnPointer=(char*)malloc(sizeof(char)*MAX_LENGTH_STRING);
	if(stackPointer==0)
	{
		printf("STACK is EMPTY...NO ELEMENTS TO PEEK");
	}
	else
	{
		if(NULL!=returnPointer)
			strcpy(returnPointer,stack[stackPointer-1]);
    }
	return returnPointer;
}
char* pop()
{
	char* returnPointer=(char*)malloc(sizeof(char)*MAX_LENGTH_STRING);
	if(stackPointer==0)
	{
		printf("STACK is EMPTY...NO ELEMENTS TO PEEK");
	}
	else
	{
		if(NULL!=returnPointer)
			strcpy(returnPointer,stack[stackPointer-1]);
	}	
	stackPointer--;
	return returnPointer;
}

