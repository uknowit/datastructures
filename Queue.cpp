#include "include/Queue.h"

void Queue::Enqueue(const char* value)
{
	int insert_index = ((tail_index)+1)%QUEUE_SIZE;
	if(head_index==insert_index)
	{
		printf("Queue is full... Dequeue the queue before adding an entry to the queue");
	}
	else
	{	
		queue[insert_index-1]=(char*)malloc(sizeof(ELEMENT_SIZE));
		strcpy(queue[insert_index-1],value);
		tail_index = insert_index;
	} 
}

char* Queue::Dequeue()
{
	char* value = (char*)malloc(sizeof(ELEMENT_SIZE));
	if(head_index==tail_index)
	{
		printf("Queue is Empty...Enqueue some elements before Dequeue");
	}
	else
	{
		if(NULL!=queue[head_index])
		if(NULL!=value)
			strncpy(value,queue[head_index],1);
		head_index = (head_index+1)%QUEUE_SIZE;
	}
	return value;
}

