#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define IN
#define OUT

typedef struct queue_node
{
size_t rear;
size_t front; 
size_t size;
void **data;
} queue;



int create_queue (queue **q, size_t size);
void* dequeue (queue *queue);
int enqueue (queue *queue, void *data);
int queue_size (queue *q);
int print_queue(queue *q);

#endif
