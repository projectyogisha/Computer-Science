#ifndef COMMONHEADER_H_INCLUDED
#define COMMONHEADER_H_INCLUDED


    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    /*******************************************************************************
                Macros
    *******************************************************************************/
    #define SUCCESS 1
    #define FAILURE 0
    #define MAX 20

    #define TRUE 1
    #define FALSE 0

    #define IN
    #define OUT

typedef struct node
    {
        void *data;
        struct node *next;

    } node;


typedef struct binary_tree_node
{

void *data;
struct binary_tree_node *left;
struct binary_tree_node *right;

} binary_tree_node;
    /******************************
    FUNCTION PROTOTYPES
    ****************************/

    char* create_string ( char *val);
    int free_string ( void *val);
    int print_integer_array (int *arr, int array_length);
#endif // COMMONHEADER_H_INCLUDED

