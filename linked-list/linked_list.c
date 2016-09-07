#include "llheader.h"


/*function prototypes*/
static node* create_linked_list_node (void *val);
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










node* insert_linked_list_first (node *head, void *val)
{

    node *newNode = create_linked_list_node ( val );

    if ( NULL != newNode  )
    {

        newNode -> next = head;
        head = newNode;
    }

    return head;

}


node* insert_linked_list_last( node* head,void *val)
{

    node *newNode = create_linked_list_node ( val );
    node *current_temp = head;

    if ( NULL != newNode  )
    {


        if ( NULL == head)
        {

            head = newNode;
        }
        else
        {

            while ( NULL != (current_temp -> next) )
            {
                current_temp = current_temp -> next;
            }
            current_temp -> next = newNode;
        }

    }

    return head;

}

node* insert_linked_list_middle( node* head,void  *val,int position)
{

    if ( position < 1)
    {
        printf ("Please enter a position between 1 and N (N being the position of last element)\n");
        return head;
    }

    node *newNode = create_linked_list_node ( val );
    node *current_temp = head ;
    node *prev_temp = NULL;

    if ( NULL != newNode  )
    {


        if (isempty (head))
        {
            head = newNode;
            return head;
        }
        else if (1 == position)
        {
            newNode -> next = head;
            return newNode;
        }
        else
        {
            while ( ( NULL != current_temp ) && ( 1 != position ) )
            {

                prev_temp = current_temp;
                current_temp = current_temp -> next;
                position--;
            }


            newNode -> next = current_temp;
            prev_temp -> next = newNode;

        }
    }
    return head;
}





int display_linked_list (node *head)
{

printf("\n");

    while ( NULL != head )
    {

        printf ("%p ->", head -> data );
        head = head -> next;

    }
    printf("NULL");


    return SUCCESS;
}



void* delete_linked_list_first (node** head)
{

    node *temp = NULL;
    void *data = NULL;

    if ( isempty (*head))
    {
        return NULL;
    }

    temp = *head;
    *head = (*head) -> next;
    data = temp -> data;

    if ( !delete_linked_list_node (temp))
    {
        printf ("\nCould not free node memory");
    }


    return data;

}


void* delete_linked_list_last (node** head)
{

    node *prev_temp = *head;
    node *current_temp = *head;
    void *data = NULL;
    if ( isempty (*head))
    {
        return NULL;
    }
    else if ( NULL == ((*head) -> next) )
    {
        data = (*head) -> data;
        if ( !delete_linked_list_node (*head))
        {
            printf ("\nCould not free node memory");
        }
        *head = NULL;
        return data;
    }


    while ( NULL != (current_temp -> next) )
    {
        prev_temp = current_temp;
        current_temp = current_temp -> next;
    }

    prev_temp -> next = NULL;

    data = current_temp -> data;
    if ( !delete_linked_list_node (current_temp))
    {
        printf ("\nCould not free node memory");
    }
    return data;

}


void* delete_linked_list_middle( node** head,int position)
{

    node *current_temp = *head ;
    node *prev_temp = NULL;
    void *data = NULL;

    if ( position < 1)
    {
        printf ("\nPlease enter a position between 1 and N (N being the position of last element)");
        return data;
    }

    if (isempty (*head))
    {
        return data;
    }
    else if (1 == position)
    {

        prev_temp = *head;
        *head = (*head) -> next;
        data = prev_temp -> data;

        if ( !delete_linked_list_node (prev_temp))
        {
            printf ("\nCould not free node memory");
        }


    }
    else
    {

        while ( ( NULL != current_temp ) && ( 1 != position ) )
        {

            prev_temp = current_temp;
            current_temp = current_temp -> next;
            position--;
        }

        if ( NULL == current_temp)
        {
            printf ("\nNot enough node(s) in the Linked list");

            return data;
        }
        prev_temp -> next = current_temp -> next;
        data = current_temp -> data;
        if ( !delete_linked_list_node (current_temp))
        {
            printf ("\nCould not free node memory");
        }


    }

    return data;
}

node* purge_linked_list (node* head)
{

node * prev_temp = head;

while ( NULL != head)
{

prev_temp = head;
head = head -> next;

        if ( !delete_linked_list_node (prev_temp))
        {
            printf ("\nCould not free node memory");

        }


}
return NULL;
}
