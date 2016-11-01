#include "header.h"
#include "bipartite_graph.h"

/**************************************************************************************************************************
* Function Name - reduce_to_zero
* Description - for each row make all the column elements 0
* Return - SUCCESS or FAILURE
* Date - Oct 29 2016
* ************************************************************************************************************************/



static int upper_triangle (float **matrix, int row, int col, int index)
{
int col_index = 0;
int row_index = 0;
float key_val = matrix[index][index];
if (0 ==  matrix[index][index])
{
  return FAILURE;
}


for (col_index = 0; col_index < (col+1); col_index++)
{
  matrix[index][col_index] = (matrix[index][col_index] / key_val);
matrix[index][col_index] = roundf(matrix[index][col_index] * ROUND_FACTOR)
/ ROUND_FACTOR; 

}

for (row_index = index + 1; row_index < row; row_index++)
{
key_val =matrix[row_index][index];  
for (col_index = 0;col_index < (col + 1);col_index++)
{


matrix[row_index][col_index] = matrix[row_index][col_index]
- ( key_val * matrix [index][col_index]);
}
}
return SUCCESS;
}

/**************************************************************************************************************************
* Function Name - back_substition
* Description - this is used to get values using back substitution
* Return - SUCCESS or FAILURE
* Date - Oct 30 2016
* ************************************************************************************************************************/

static int back_substition (float **matrix, int row, int col)
{

int row_index = row - 1;
int col_index = 0;
float *x = (float *)malloc (sizeof(float)*row);
if (NULL == x)
{
  return FAILURE;
}
memset (x, 0 , sizeof(float)*row);

for (;row_index > -1;row_index--)
{
x[row_index] = matrix [row_index][(col - 1)];
for (col_index = col - 2; col_index > row_index; col_index --)
{
x[row_index]=x[row_index] - (matrix[row_index][col_index] * x[col_index]);  
}
if (0 == matrix[row_index][row_index])
  {
  if (0 != x[row_index])
  {
     x[row_index] = 1; 
    printf ("\nsystem in-consistent\n");
    break;
  }
  else
  {
    x[row_index] = 0; 
    printf ("\nx%d is free finding solution with 1\n",row_index);
    continue;;
  }
}
}
for (row_index = 0;row_index < row;row_index++)
{
printf ("x%d = %f\n",(row_index + 1 ),x[row_index]);
}



return SUCCESS;
}









/**************************************************************************************************************************
* Function Name -guassian elimination
* Description - reduce given matrix to the upper triangle using cache and
* localized graph method
* Return - SUCCESS or FAILURE
* Date - Oct 25 2016
* ************************************************************************************************************************/

int gaussian_elimination (float **matrix, int row, int col)
{

int row_index = 0;

display_matrix(matrix,row,col);
if (0 == maxBPM(matrix,row,(col-1))) 
{
return FAILURE;
}
//printf ("\n\nmatrix after rearragning\n\n");
//display_matrix(matrix,row,col);
for (row_index = 0; row_index < row; row_index++)
{
upper_triangle (matrix, row,  col, row_index);
}

display_matrix(matrix,row,col);
back_substition (matrix,  row,  col);


return SUCCESS;
}


/**************************************************************************************************************************
* Function Name -display matrix
* Description - prfloat the values in the matrix
* Return - SUCCESS or FAILURE
* Date - Oct 29 2016
* ************************************************************************************************************************/

void display_matrix (float **matrix, int row, int col)
{
int i = 0;
int j = 0;

for (i =0;i<row;i++)
{
   printf ("\n\n");
   for (j=0;j<col;j++)
   {
     printf ("%.2f\t",matrix[i][j]);
   }

}
printf ("\n");

}



