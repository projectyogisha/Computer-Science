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

typedef struct stack_node
{
size_t top;
size_t size;
void **data;
} stack;



int create_stack (stack **s, size_t size);
void* pop (stack *stack);
int push (stack *stack, void *data);
void print_stack(const stack *q);

#endif
