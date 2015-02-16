#ifndef _QUEUE_HEADER_H
#define _QUEUE_HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEUE_SIZE 200
#define ELEMENT_SIZE 100

class Queue {

char **queue;
int head_index;
int tail_index;

public:
	Queue()
	{
	head_index=0;
	tail_index=0;
	queue=(char**)malloc(sizeof(QUEUE_SIZE)+1);
	}
	Queue(const Queue&){head_index=0;tail_index=0;queue=(char**)malloc(sizeof(QUEUE_SIZE)+1);}
	Queue& operator=(const Queue&){return *this;}
	~Queue(){free(queue);};
	void Enqueue(const char* value);
	char* Dequeue();
};
#endif
