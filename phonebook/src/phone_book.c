#include "phone_book.h"

/**************************************************************************
*Name : destory_stack
*Des: free stack memory including each phonebook entry
*return : SUCCESS 
**************************************************************************/

int destroy_stack(stack **s, size_t size)
{
int i = 0;

if (isEmpty(*s)) /*check if there are any entries in the phonebook (or stack) if stack is empty return*/
{
return FAILURE;
}



for (i = 0;i <= (*s)->top;i++) /*delete all the entries in the stack one after the other*/
{
free ((*s)->data[i]->name);
free ((*s)->data[i]);
}


  free((*s)->data); /*free the memory for the stack*/
  free(*s);
  *s = NULL;
return SUCCESS;

}


/**************************************************************************
*Name : create_stack
*Des: allocate memory to stack
*return : SUCCESS or FAILURE 
**************************************************************************/

int create_stack (stack **s, size_t size)
{

(*s) = (stack *) malloc (sizeof (stack)); /*allocate memory for the stack*/

if (NULL == (*s))
{
return FAILURE;
}

(*s)->size = size;
(*s)->top = -1;
(*s)->data = (phone_node **) malloc (sizeof(phone_node*) * size); /*create an array of phone_node pointers*/

if (NULL == (*s)->data)
{
  free (*s);
  return FAILURE;
}

return SUCCESS;
}


/**************************************************************************
*Name : isEmpty
*Des: check if stack is empty
*return : SUCCESS or FAILURE
**************************************************************************/

int isEmpty (const stack *s)/*usefull for checking if there is an entry in the phone book*/
{

if (s->top == -1 )
{
  return SUCCESS;
}
return FAILURE;

}


/**************************************************************************
*Name : top
*Des: check if stack is empty
*return : s->top
**************************************************************************/

phone_node* top (stack *s) /*usless function as far as phoenbook is concerned*/
{
return ( s->data[s->top]); /*return the topmost element in stack*/
}


/**************************************************************************
*Name : push
*Des: push element into stack
*return : SUCCESS or FAILURE
**************************************************************************/

int push (stack *s, phone_node* data)
{
int i = 0;


if (-1 != s->top)
{
for (i = 0;i <= s->top;i++)
{
if ((0 == strcmp((s->data[i])->name, data->name)) || ((s->data[i])->number == data->number)) /*check if the entry presented is a duplicate entry or not*/
{

free (data->name); /*since its a duplicate entry free the node data*/
free (data);
  printf ("this is an duplicate entry\n");
return FAILURE;
}
}
}
if ((s->size - 1) == s->top)/*if the stack is full then then call resize stack and then insert in the stack*/
{
  
 if (!resize_stack (s, (2 * s->size)))
 {
return FAILURE;
 }
}

s->top = s->top + 1;
s->data[s->top] = data;
return SUCCESS;
}


/**************************************************************************
*Name : pop
*Des: returns the top element of stack
*return : *s->data[s->top]
**************************************************************************/

phone_node* pop (stack *s) /*usless for the phone book implementation, to lazy to delete*/
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

/**************************************************************************
*Name : print_stack
*Des: displays the stack
*return : void
**************************************************************************/

void print_stack (const stack *s)
{

int top = 0;

if (-1 == s->top) /*return if stack is empty*/
{
return;
}
top = s->top;

while (top >= 0)/*print the name and number of each element in the stack*/
{
printf ("\n%s\t%d\n" , s->data[top]->name, s->data[top]->number);
top--;
}


printf ("\n");
return;
}
/**************************************************************************
*Name : search_by_name
*Des: search phonebook by name
*return : SUCCESS or FAILURE
**************************************************************************/


int search_by_name (const stack *s, const char *name)
{
int i = 0;

if (isEmpty(s))
{
return FAILURE;
}


for (i = 0;i <= s->top;i++)
{
if ((0 == strcmp((s->data[i])->name, name)))  /*search the stack by name using the strcmp function  */ 
{
printf ("\n%s\t%d\n",(s->data[i])->name,(s->data[i])->number);
return SUCCESS;
}
}

return FAILURE;
}
/**************************************************************************
*Name : search_by_number
*Des: search phonebook by number
*return : SUCCESS or FAILURE
**************************************************************************/


int search_by_number (const stack *s, const int number)
{
int i = 0;

if (isEmpty(s))
{
return FAILURE;
}


for (i = 0;i <= s->top;i++)
{
if ((s->data[i])->number == number) /*search the stack by number*/
{
printf ("\n%s\t%d\n",(s->data[i])->name,(s->data[i])->number);
return SUCCESS;
}
}

return FAILURE;
}

/**************************************************************************
*Name : resize_stack
*Des: resize the phonebook when it is full
*return : SUCCESS or FAILURE
**************************************************************************/




int resize_stack (stack *s, size_t size)
{


s->size = size;
s->data = (phone_node **) realloc (s->data, sizeof(phone_node*) * size); /*use realloc to resize the stack make sure the get the return value since there is a possibility the address changes*/

if (NULL == s->data)
{
printf ("unable to increase phonebook size\n");
return FAILURE;
}

printf ("resize");
return SUCCESS;
}
/**************************************************************************
*Name : delete_by_number
*Des : delete an entry in the phonebook by number
*return : SUCCESS or FAILURE
**************************************************************************/


int delete_by_number (stack *s, const int number)
{
int i = 0;
int j = 0;
if (isEmpty(s))
{
return FAILURE;
}


for (i = 0;i <= s->top;i++)
{
if ((s->data[i])->number == number) 
{
delete_node (s->data[i]);/*if a matching number is found call delete_node node to remove the entry*/
  
for (j = i; j < s->top; j++)
{
s->data[j] = s->data[j+1]; /*copy all entries from index n to n-1 and decrement the value of top */

}
s->top = s->top - 1;
return SUCCESS;
}
}

return FAILURE;
}
/**************************************************************************
*Name : sort_by_name
*Des: sort the phonebook by name
*return : SUCCESS or FAILURE
**************************************************************************/



int sort_by_name (const stack *s)
{
int i = 0;
int j = 0;
phone_node* t = NULL;
if (isEmpty(s))
{
return FAILURE;
}


for (i = 0;i < s->top;i++)
{
for (j = i+1; j <= s->top;j++)
{
if ((0 > strcmp((s->data[i])->name, (s->data[j])->name))) /*use strcmp to judge is string is smaller or not based on ascii value and then swap address of each entry*/
{
t = (s->data[i]);
 (s->data[i]) =  (s->data[j]);
 (s->data[j]) = t;

}
}
}

return FAILURE;
}
/**************************************************************************
*Name : sort_by_number
*Des: sort the phonebook by number
*return : SUCCESS or FAILURE
**************************************************************************/


int sort_by_number (const stack *s)
{
int i = 0;
int j = 0;
phone_node* t = NULL;
if (isEmpty(s))
{
return FAILURE;
}


for (i = 0;i < s->top;i++)
{
for (j = i+1; j <= s->top;j++)
{
if ((s->data[i])->number < (s->data[j])->number) /*check if the phone number is smaller and then swap*/
{
t = (s->data[i]);
 (s->data[i]) =  (s->data[j]);
 (s->data[j]) = t;

}
}
}

return FAILURE;
}

/**************************************************************************
*Name : create_node
*Des: create a structure containing a phonebook entry
*return : NULL or entry (address to the struture)
**************************************************************************/

phone_node* create_node (char *name, int number) /*this is used to create a phonebook entry node, NOTE:- this node has to be inserted into the stack*/
{
phone_node *entry = NULL;


entry = (phone_node *) malloc (sizeof(phone_node));
if (NULL == entry)
{
return NULL;
}
entry->name = (char*) malloc (sizeof(char)* strlen(name));
if (NULL == entry->name)
{
free (entry);
return NULL;
}
memset (entry->name , '\0', (sizeof(char) * strlen(name)));
strcpy (entry->name, name);
entry->number = number;

return entry;
}
/**************************************************************************
*Name : delete_node
*Des: delete a structure containing phonebook entry
*return : SUCCESS or FAILURE
**************************************************************************/



int delete_node(phone_node* data)/*deletes a reference to a phonebook entry by freeing the memory*/
{

if (NULL == data)
{
return FAILURE;
}



  free (data->name);
  free (data);


return SUCCESS;
}

