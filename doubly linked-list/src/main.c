#include "commonheader.h"
#include "dllheader.h"

int main( int argc, char *argv[] )
{

node *head = NULL;
node *tail = NULL;

 insert_dlinked_list_end (&head, &tail, "33");
 insert_dlinked_list_end (&head, &tail, "34");
 insert_dlinked_list_end (&head, &tail, "35");
 insert_dlinked_list_end (&head, &tail, "36");
 insert_dlinked_list_end (&head, &tail, "37");

    display_dlinked_list (head);
   return 0;

}
