#include "header.h"


unsigned max (const float a,const float b)
{
if (a > b)
{

  return 1;
}
return 0;

}


unsigned min (const float a,const float b)
{
if (a < b)
{

  return 1;
}
return 0;

}





unsigned order_index ( const float *c,
                       const unsigned length, 
                       unsigned  (*compare) (float a,float b))
{

unsigned index_l = 0;
unsigned index;
for (index= 1;index < length;index++)
{
if (compare (c[index] , c[index_l]))
{
  index_l = index;
}
}
return index_l;
}




void  resize_matrix  (float **matrix, unsigned row, unsigned col )
{

unsigned index = 0;

  matrix = (float**) realloc ( matrix , row * sizeof (float));
 if (NULL == matrix)
   {
      printf ("no memory\n");
      exit(1);
    }
  
for (;index < row;index++)
{
  matrix[index] = (float*) realloc (matrix[index], col * sizeof (float));
 if (NULL == matrix[index])
   {
      printf ("no memory\n");
      exit(1);
    }
 
}

return;
}





float* random_array (unsigned row)
{
unsigned row_l = 0;
float *matrix =NULL;
 struct timespec ts;
     clock_gettime(CLOCK_MONOTONIC, &ts);
     
              
  matrix = (float*) malloc ( row * sizeof (float));
  if (NULL == matrix)
   {
      printf ("no memory\n");
      exit(1);
    }
  
  
  srand((time_t)ts.tv_nsec);
  for (;row_l < row; row_l++)
  {
    matrix[row_l] = (rand() % 100);
  }

return matrix;
}



float* zero_array (unsigned row)
{
float *matrix =NULL;
unsigned index = 0;
  
  matrix = (float*) calloc (row , sizeof (float));
  if (NULL == matrix)
   {
      printf ("no memory\n");
      exit(1);
    }
  
 for (;index < row;index ++)
{
  matrix[index] = 0;
}
return matrix;
}




float** generate_matrix (unsigned row, unsigned col, float* (*function_array) (unsigned row) )
{

float **matrix = NULL;
unsigned row_l = 0;

matrix = (float **) malloc (row * sizeof(float *));
if (NULL == matrix)
{
  printf ("no memory\n");
  exit(1);
}

  for (;row_l < row; row_l++)
  {
    matrix[row_l] = function_array(col);
  }



return matrix;
}



float* generate_array (unsigned row,  float* (*function_array) (unsigned row))
{

   return  function_array(row);
}

void display_matrix (float **matrix, int row,int col)
{
  unsigned row_l = 0;
  unsigned col_l = 0;
  for (;row_l < row;row_l++)
  {
    printf("\n");
    for (col_l = 0;col_l < col;col_l ++)
    {
      printf ("%f\t",matrix[row_l][col_l]);
    }
  }

    printf("\n");
}



void display_array (float *matrix, int row)
{
  unsigned row_l = 0;
  
    printf("\n");
    for (row_l = 0;row_l < row;row_l ++)
    {
      printf ("%f\t",matrix[row_l]);
    }
  

    printf("\n");
}



unsigned search_array (const unsigned *array, unsigned length, unsigned value)
{
  unsigned index = 0;
  for (;index < length;index++)
  {
    if (value == array[index])
      return index;
  }

return -1;
}



void set_matrix_to_val (float **matrix, unsigned row,unsigned col)
{
  unsigned index = 0;
  for (;index < row;index++)
  {
    memset (matrix[index], 0, sizeof (float) * col);
  }
}
