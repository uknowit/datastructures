#include "StackPointer.h"

void push(char* value)
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
		strcpy(returnPointer,stack[stackPointer-1]);
	}	
	stackPointer--;
	return returnPointer;
}
int main(int argc,char** argv)
{
	stack=(char**)malloc(sizeof(char*)*MAX_ELEMENTS);
	stackPointer=0;
	while(stackPointer<MAX_ELEMENTS)
	{
		char *buff="shashi";
		push(buff);
	}
	while(stackPointer!=0)
	{
		char* peekValue=pop();	
		printf("%s\n",peekValue);
		free(peekValue);
	}
	int index=0;
	while(index <MAX_ELEMENTS && stack[index]!=NULL)
	{
		free(stack[index]);
		index++;
	}
	free(stack);
	return 0;
}
