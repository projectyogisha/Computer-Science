    #include "dllheader.h"


    /*function prototypes*/
    static node* create_linked_list_node (void * val);
    static int delete_linked_list_node (node *temp);
    static int isempty (node *head);




    static int isempty (node *head)
    {
        if ( NULL == head)
        {
            return SUCCESS;
        }
        else
        {
            return FAILURE;
        }
    }

  static node* create_linked_list_node (void *val)
  {
    node *newNode = NULL;
    newNode = (node*) malloc(sizeof(node));

    if ( NULL ==  newNode )
    {
        printf ("Out of memory\n");
        return NULL;

    }

    newNode -> next = NULL;
    newNode -> data = val;

    return newNode;
  }


    static int delete_linked_list_node (node *temp)
    {

    if ( NULL == temp )
     {
        printf("Node to be free points to null\n");
        return FAILURE;
     }

    free(temp);
    return SUCCESS;
  }




    static node* xor (node * a, node * b)

    {
    return ((node *) ((unsigned int) a ^ (unsigned int) b));
    }

/*static int check_memory_flags(node *node)
{
void *p = NULL;  
   
    __asm__("pushf\n"  
                   "orl $0x40000, (%rsp)\n" 
                 "popf"); 
 
              p = malloc(sizeof(void*) + 1);  
              memset(p, 0, sizeof(void*) + 1);  
if (NULL == (p - node->data))
{
return FAILURE;
  }




              return SUCCESS;  
}
*/

    int insert_dlinked_list_end (node **head, node **tail, void *val)
    {

        node *newNode = create_linked_list_node ( val );

        if ( NULL == newNode )
        {
        return FAILURE;

           }

    if (isempty(*head) && isempty(*tail)){

    newNode -> next = xor(NULL, *head);

            *head = newNode;
             *tail = newNode;
    }
    else{



            newNode -> next = xor(NULL, *tail);
            (*tail) -> next = xor ( (*tail) -> next , newNode);

            *tail = newNode;

        }

         //  check_memory_flags(*tail);
           return SUCCESS;


    }

    int insert_dlinked_list_middle (node **head, node **tail, void *val, int position)
    {
      if ( position < 1)
        {
            printf ("Please enter a position between 1 and N (N being the position of last element)\n");
            return FAILURE;
        }

        node *newNode = create_linked_list_node ( val );
        node *current_temp = *head ;
        node *prev_temp = NULL;
        node *temp = NULL;
        if ( NULL == newNode  )
        {

        return FAILURE;
        }

    if (isempty(*head) && isempty(*tail))
    {
             newNode -> next = xor(NULL, *head);
            *head = newNode;
            *tail = newNode;
    }
            else if (1 == position)
            {
            newNode -> next = xor(NULL, *head);
            (*head) -> next = xor ( (*head) -> next , newNode);
            *head = newNode;
            }
            else
            {
                while ( ( NULL != current_temp ) && ( 1 != position ) )
                {
                    temp = prev_temp;
                    prev_temp = current_temp;
                    current_temp = xor ( current_temp -> next , temp);
                    position--;
                }

               prev_temp -> next = xor (xor (prev_temp -> next, current_temp ), newNode);
               newNode -> next = xor (current_temp, prev_temp);
               if (NULL != current_temp) 
               {
                    current_temp -> next = xor (xor (current_temp -> next, prev_temp ), newNode);
               }
               else
               {
                    *tail = newNode;
               }

            }
        return SUCCESS;

    }


    void* delete_dlinked_list_first (node **head, node **tail)
    {

        node *temp = NULL;
        void *val= NULL;
        if ( NULL == *head && NULL == *tail)
        {
        printf ("\nList is empty\n");
            return NULL;
        }


       temp = xor ( (*head) -> next, NULL );
       if (NULL != temp)
       {


       temp -> next = xor ( xor (*head, temp ->next) , NULL );

    } else {
        *tail = NULL;
    }

        val = (*head) -> data;

        if ( !delete_linked_list_node (*head))
        {
            printf ("Could not free node memory");

        }
        *head = temp;
            return val ;

    }


    int purge_dlinked_list(node **head , node **tail)
    {


         node * temp = *head;
         node *current_node = *head;


      while (NULL != temp)
         {


         temp = xor ( (current_node) -> next, NULL );
       if (NULL != temp)
       {
       temp -> next = xor ( xor (current_node, temp ->next) , NULL );

    }
    if ( !delete_linked_list_node (current_node))
        {
            printf ("Could not free node memory");

        }

    current_node = temp;
    }

    *head = NULL;
    *tail = NULL;
    return SUCCESS;
    }



    int display_dlinked_list (node *head)
    {

    node *prev_node = NULL;
    node * temp = NULL;
    printf ("\n");
        while ( NULL != head )
        {

            printf ("%p ->", head -> data);
            temp = prev_node;
            prev_node = head;
            head = xor ( head -> next , temp);


        }
        printf("NULL\n");

        return SUCCESS;
    }




