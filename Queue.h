#ifndef _QUEUE_HEADER_H
#define _QUEUE_HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEUE_SIZE 200
#define ELEMENT_SIZE 100


char **queue;
int head_index;
int tail_index;

void Enqueue(char* value);
char* Dequeue();

#endif
