    #ifndef DLLHEADER_H_INCLUDED
    #define DLLHEADER_H_INCLUDED

     #include "commonheader.h"

    /*******************************************************************************
                Function Prototypes
    *******************************************************************************/

    int  insert_dlinked_list_end (node **head, node **tail, void *val);
    int insert_dlinked_list_middle (node **head, node **tail, void *val, int position);
    void* delete_dlinked_list_end (node **head, node **tail);
    int purge_dlinked_list(node **head , node **tail);
    int display_dlinked_list (node *tail);






    #endif // DLLHEADER_H_INCLUDED
