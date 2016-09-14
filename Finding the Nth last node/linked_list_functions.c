#include "llheader.h"


node* nth_node_linked_list (node *head, int position)
{

node *forward_node = head;
node *backward_node = head;
int count = 0;

if (position < 0)
{
    printf ("\nposition must be a whole number");
return NULL;
}

for (;NULL != forward_node; forward_node = forward_node-> next)
{
    if ( count  ==  position)
    {
        backward_node = backward_node -> next;

    }
    else
        {
        count = count + 1;
        }

}

if ( count != position)
{
    printf ("\nLinked-List is too short");
    backward_node = NULL;
}
return backward_node;
}
