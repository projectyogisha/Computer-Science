#ifndef LLHEADER_H_INCLUDED
#define LLHEADER_H_INCLUDED

#include "commonheader.h"

/*******************************************************************************
			Function Prototypes
*******************************************************************************/

node * insert_linked_list_first (node *head, void *val);
node * insert_linked_list_last( node* head,void *val);
node* insert_linked_list_middle( node* head,void *val,int position);
void* delete_linked_list_first (node **head);
void* delete_linked_list_last (node** head);
void* delete_linked_list_middle( node** head,int position);
int display_linked_list (node *head);
node* purge_linked_list (node* head);




/***********Extra prototypes

*******************/
node* reverse_linked_list (node *head);
node* loop_linked_list (node *head , int position);
int unloop_linked_list (node *head);
int check_loop_linked_list ( node *head);
node* nth_node_linked_list (node *head, int position);
#endif // LLHEADER_H_INCLUDED
