#include "header.h"


int main ( int argc, char** argv)
{

queue  *q1 = NULL;

create_queue (&q1, 6 );

enqueue (q1, "1");

enqueue (q1, "2");
enqueue (q1, "3");


printf ("%p\n\n",dequeue (q1));


printf ("size of queue:%d\n" ,queue_size (q1));


print_queue (q1);



}
