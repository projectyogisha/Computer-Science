#include "header.h"


int create_stack (stack **s, size_t size)
{

(*s) = (stack *) malloc (sizeof (stack));

if (NULL == (*s))
{
return FAILURE;
}

(*s)->size = size;
(*s)->top = -1;
(*s)->data = (void *) malloc (sizeof(void*) * size);

if (NULL == (*s)->data)
{
free (*s);
  return FAILURE;
}

return SUCCESS;
}

int push (stack *s, void* data)
{

if ((s->size - 1) == s->top)
{
return FAILURE;
}

s->top = s->top + 1;
s->data[s->top] = data;



return SUCCESS;
}

void* pop (stack *s)
{

void *data = NULL;

if (-1 == s->top)
{
return NULL;
}

data = s->data[s->top];
s->top = s->top - 1;

return data;
}


void print_stack (const stack *s)
{

int top = 0;

if (-1 == s->top)
{
return;
}
top = s->top;

while (top >= 0)
{
printf ("%p " ,s->data[top]);
top--;
}


printf ("\n");
return;
}


