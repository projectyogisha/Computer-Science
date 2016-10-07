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
typedef struct phone_node
{
char *name;
int number;
} phone_node;


typedef struct stack_node
{
size_t top;
size_t size;
phone_node **data;
} stack;




/*function prototypes*/
int create_stack (stack **s, size_t size);
phone_node* pop (stack *stack);
int push (stack *stack,phone_node *data);
void print_stack(const stack *q);
int destroy_stack(stack **s, size_t size);
int isEmpty(const stack *s);
phone_node* top(stack *s);
phone_node* create_node(char *name, int number);
int delete_node(phone_node* data);
int search_by_name (const stack *s, const char *name);
int search_by_number (const stack *s, const int number);
int resize_stack (stack *s, size_t size);
int delete_by_number (stack *s, const int number);
int sort_by_name (const stack *s);
int sort_by_number (const stack *s);
#endif
