#include "llheader.h"


node* reverse_linked_list (node *head)
{

node * forward_node =head;
node * current_node = head;
node * prev_node = NULL;

while ( NULL != forward_node )
{
    forward_node = forward_node -> next;
    current_node -> next = prev_node ;
    prev_node = current_node;
    current_node = forward_node;

}

return prev_node;


}

