#include "Queue.h"

void Enqueue(char* value)
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

char* Dequeue()
{
	char* value = (char*)malloc(sizeof(ELEMENT_SIZE));
	if(head_index==tail_index)
	{
		printf("Queue is Empty...Enqueue some elements before Dequeue");
	}
	else
	{
		if(NULL!=queue[head_index])
		strcpy(value,queue[head_index]);
		head_index = (head_index+1)%QUEUE_SIZE;
	}
	return value;
}

int main(int argc,char** argv)
{
	queue=(char**)malloc(sizeof(QUEUE_SIZE)+1);
	head_index=tail_index=0;
	int index=0;
	while(index <QUEUE_SIZE-1)
	{
		Enqueue("Shashikumar");
		index++;
	}
	index=0;
	printf("%d %d \n",head_index,tail_index);
	while(index<QUEUE_SIZE-1)
	{
		char* val=Dequeue();
		printf("%d) %s\n",index,val);
		index++;
	}	
	return 0;
}
