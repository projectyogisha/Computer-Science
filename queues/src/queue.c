#include "header.h"


int create_queue (queue **q, size_t size)
{


  (*q) = (queue*) malloc (sizeof (queue) );
  if ( NULL == (*q) )
  {
    return FAILURE;
  }

  (*q)->front = -1;
  (*q)->rear = -1;
  (*q)->size = size;



  (*q)->data = (void**) malloc (size * sizeof (void *) );


  if ( NULL == (*q)->data )
  {
    return FAILURE;
  }
  memset ((*q)->data, '\0', (size * sizeof (void *)) );


  return SUCCESS;
}



int enqueue (queue *queue, void *data)
{

  if (((queue -> rear + 1) % queue -> size) == queue->front)
  {
    return FAILURE;
  }

  queue->rear = ((queue->rear + 1) % queue->size);
  queue->data[(queue->rear)] = data;

  if (-1 == queue->front)
  {
    queue->front = queue->rear;
  }



  return SUCCESS;
}


void* dequeue (queue *queue)
{

  void *data;
  
  if (queue -> rear == -1)
  {
    return NULL;
  }

  
  data = queue-> data[queue->front];
  
  if (queue -> rear == queue->front)
  {
    queue->rear = -1;
    queue->front = -1;
  }
  else
  {
  queue->front = ((queue->front + 1) % queue->size);
  }


  return data;
}


int queue_size (queue *q)
{
 if (-1 == q->front)
  {
    return 0;
  } 


 return (((q->size - q->front) + (q->rear + 1)) % q->size);

}



int print_queue(queue *q)
{

int front = q->front;
int rear = q->rear;

if (-1 == front)
{
return SUCCESS;
}



while (front <= rear)
{

 printf ("%p\t", q->data[front]); 

 front = (front + 1) % q->size;

}

printf ("\n");
return SUCCESS;
}
