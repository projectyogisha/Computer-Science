#include "header.h"


int main (int argc, char* args[])
{

stack *s = NULL;

create_stack(&s, 5);
push (s,"1");

push (s,"2");
push (s,"3");
push (s,"4");
push (s,"5");


print_stack(s);
printf ("%p\n\n",pop(s));
printf ("%p\n\n",pop(s));
printf ("%p\n\n",pop(s));
printf ("%p\n\n",pop(s));

printf ("%p\n\n99",pop(s));

printf ("%p\n\n",pop(s));
printf ("%p\n\n",pop(s));
printf ("%p\n\n",pop(s));








print_stack(s);


return SUCCESS;
}
