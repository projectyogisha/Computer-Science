#include "commonheader.h"
#include "llheader.h"


int main( int argc, char *argv[] )
{


node *head = NULL;
node *n_last_node =NULL;


head = insert_linked_list_first ( head, "5");
head = insert_linked_list_first ( head, "4");
head = insert_linked_list_first ( head, "3");
head = insert_linked_list_first ( head, "2");
head = insert_linked_list_first ( head, "1");



display_linked_list (head);

n_last_node = nth_node_linked_list (head, -3);

printf ("\n%p" , n_last_node );


return SUCCESS;
}

