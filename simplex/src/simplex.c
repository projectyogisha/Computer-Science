#include "header.h"


/**************************************************************************************************************************
* Function Name -
* Description - 
* Return - 
* Date - Nov 20 2016
* ************************************************************************************************************************/

static void N_to_B (unsigned *N,unsigned *B,unsigned e, unsigned l )
{
  int temp = N[e];
  N[e]=B[l];
  B[l]=temp;
} 



/**************************************************************************************************************************
* Function Name -
* Description - 
* Return - 
* Date - Nov 20 2016
* ************************************************************************************************************************/

unsigned max_positive (const float *c, const unsigned length, const unsigned *N )
{

unsigned index_max =  order_index (c, length, max);

if (c[index_max] > 0)
return index_max;

return length;

}

/**************************************************************************************************************************
* Function Name -
* Description - 
* Return - 
* Date - Nov 21 2016
* ************************************************************************************************************************/

unsigned bland_rule (const float *c, const unsigned length, const unsigned *N )
{
unsigned index_sub = length;
unsigned index;
for (index= 0;(index < length);index++)
{

if (c[index] > 0)
{
  if (length == index_sub)
  {
    index_sub = index;
  }
  else if (N[index]< N[index_sub])
  {
    index_sub = index;
  }
}
}

return index_sub;
}


/**************************************************************************************************************************
* Function Name -
* Description - 
* Return - 
* Date - Nov 21 2016
* ************************************************************************************************************************/

unsigned astenn_positive_sampling (const float *c, const unsigned length, const unsigned *N )
{
unsigned index_min = length;
unsigned index;
for (index= 0;index < length;index++)
{
if ( c[index] > 0)
{
return index;

}
}
return index_min;
}





/**************************************************************************************************************************
* Function Name - calculate_pivot
* Description - returns the modified version of the linear function
* Return - void
* Date - Nov 18 2016
* ************************************************************************************************************************/

void  calculate_pivot (float **matrix,  /*this is the entry matrix */
                      float **matrix_l, /*this is the leaving matrix */     
                      float *c,  /*this is the array objective function coefficients*/
                      float *b,  /*this is the array of elements on set b*/
                      float *v,  /*constant in the objective function */
                      unsigned *B, /*set of basic variables*/
                      unsigned size_B, /*the size of Basic variables*/
                      unsigned *N, /*set of non basic variables*/
                      unsigned size_N, /*size of non basic variables*/
                      unsigned e_index,   /*entering variable */
                      unsigned l_index  /*leaving variable */  )
{

unsigned index_row = 0;
unsigned index_col = 0;

for (; (index_row < size_N) ;index_row++)
{

  if  (index_row != e_index)
  {
    matrix_l[l_index][index_row] =matrix[l_index][index_row]/matrix[l_index][e_index];
  }
}


b[l_index] = b[l_index]/matrix[l_index][e_index]; 
matrix_l[l_index][e_index] = (1 / matrix[l_index][e_index] );




for (index_row = 0; (index_row < size_B);index_row++)
{
if (index_row != l_index)
  {
  b[index_row] = b[index_row] - (b[l_index] * matrix[index_row][e_index]); 
    for (index_col = 0;index_col < size_N;index_col++)
    {
      if (index_col != e_index)
        {
          matrix_l[index_row][index_col] = (matrix[index_row][index_col]
          - (matrix[index_row][e_index]*matrix_l[l_index][index_col]));
        }
    
  matrix_l [index_row][e_index] = matrix[index_row][e_index] * -matrix_l[l_index][e_index];  

    }
}
}

*v = *v + (c[e_index] * b[l_index]);


for (index_row = 0;index_row < size_N;index_row++)
{
  if (index_row != e_index)
  {
  c[index_row] = c[index_row] - (c[e_index] * matrix_l[l_index][index_row]); 

  }
  
}

  c[e_index] =  c[e_index] * -matrix_l[l_index][e_index];


N_to_B(N,B,e_index,l_index);

}


/**************************************************************************************************************************
* Function Name - simplex
* Description - this is the main loop for the modified simplex algorithm
* Return - vois
* Date - Dec 13 2016
* ************************************************************************************************************************/




         void simplex (float **matrix,  /*this is the entry matrix */
                       float *c,  /*this is the array objective function coefficients*/
                       float *v, /*constant iterative value*/
                       float *b,  /*this is the array of elements on set b*/
                       unsigned size_c, /*the size of non Basic variables*/
                       unsigned size_b, /*size of  basic variables*/  
                       unsigned (*select_e) (const float *c,const unsigned
                       length,const unsigned *N))
{

float **matrix_l = generate_matrix(size_b,size_c ,zero_array);
float **matrix_temp = NULL;
unsigned e = 0;
unsigned l = 0;
unsigned index = 0;
float delta = INFINITY;
float temp = 0;
unsigned *B = (unsigned*)malloc (sizeof(unsigned)*size_b);
if (NULL == B)
{
  printf("out of memory");
  exit (1);
}
unsigned *N =  (unsigned*)malloc (sizeof(unsigned)* (size_c + 1));
if (NULL == N)
{
  printf("out of memory");
  exit (1);
}

initialize_feasible_solution
(matrix,matrix_l,c,b,v,B,size_b,N,size_c,e,l,select_e);

if (INFINITY == *v)
{
  return;
}


while ((e = select_e(c,size_c,N)) < size_c)
{

 delta = INFINITY;
 temp = 0;
  for (index = 0;index < size_b;index++)
  {
    if (matrix[index][e] > 0 && ((temp = (b[index]/matrix[index][e])) <= delta ))
    {
      l = index;
      delta = temp;
    }
  }

if (delta == INFINITY)
{
  printf ("UNBOUND\n");
  *v = INFINITY;
  return;

}  
else
{
calculate_pivot (matrix,matrix_l,c,b,v,B,size_b,N,size_c,e,l);
matrix_temp=matrix;
matrix=matrix_l;
matrix_l = matrix_temp;

}


}


printf ("\a\nOptimal value:%f\n",*v);
for (index = 0;index < size_c;index++)
{
  printf ("X%d = 0\n",N[index]);
}

for (index = 0;index < size_b;index++)
{
  printf ("X%d = %f\n",B[index],b[index]);
}
free (N);
free (B);

for (index = 0;index < size_b;index++)
{
  free (matrix_l[index]);
}


}

/**************************************************************************************************************************
* Function Name - initialize_feasible_solution
* Description - to check if there is a feasible solution to the linear system
* Return - void, sets a initialized linear system which has a feasible solution
* Date - Dec 13 2016
* ************************************************************************************************************************/
void initialize_feasible_solution (float **matrix,  /*this is the entry matrix */
                                   float **matrix_l, /*this is the leaving matrix */     
                                   float *c,  /*this is the array objective function coefficients*/
                                   float *b,  /*this is the array of elements on set b*/
                                   float *v,  /*constant in the objective function */
                                   unsigned *B, /*set of basic variables*/
                                   unsigned size_B, /*the size of Basic variables*/
                                   unsigned *N, /*set of non basic variables*/
                                   unsigned size_N, /*size of non basic variables*/
                                   unsigned e_index,   /*entering variable */
                                   unsigned l_index, /*leaving variable */ 
                                   unsigned (*select_e) (const float *c,const unsigned
                                  length,const unsigned *N))/*This is to
                                  maintain the use of the same pivoting method
                                  when optimaizing initialization function*/
{

unsigned b_min = order_index(b,size_B,min);
unsigned index = 0;
unsigned index_1 = 0;
unsigned e, l =0;
float temp = 0;
float delta ;
float v_temp = 0;

/*initializing Basic and Non Basic array*/
for (index = 0;index< size_N;index++)
{
  N[index] = index + 1;
}

N[size_N] = 0;

for (index = 0;index< size_B;index++)
{
  B[index] = size_N + index + 1;
}



/*check if there are any negative B values */
if (b[b_min] > 0) 
{
  return;
}
else 
{
/*resizing matrix to add x0 variable */
resize_matrix(matrix, size_B, size_N + 1);
resize_matrix(matrix_l, size_B, size_N + 1);
float *c_temp = zero_array (size_N+1);
c_temp[size_N] = -1;  
/*setting the coefficient of x0 to -1 */
for (index =0;index < size_B ;index++)
{
matrix[index][size_N] = -1;
}
/*performing a single pivoting operation to make all b values as positive */
calculate_pivot (matrix,matrix_l,c_temp,b,&v_temp,B,size_B,N,size_N + 1,size_N,b_min);
float **matrix_temp=matrix;
matrix=matrix_l;
matrix_l = matrix_temp;

/*solving the new linear system of equations */
while ((e = select_e(c_temp,size_N + 1,N)) < size_N + 1)
{

 delta = INFINITY;
 temp = 0;
  for (index = 0;index < size_B;index++)
  {
    if (matrix[index][e] > 0 && ((temp = (b[index]/matrix[index][e])) <= delta ))
    {
      l = index;
      delta = temp;
    }
  }

calculate_pivot (matrix,matrix_l,c_temp,b,&v_temp,B,size_B,N,size_N+1,e,l);
matrix_temp=matrix;
matrix=matrix_l;
matrix_l = matrix_temp;

}




/*check if the optimal value is 0 */
if (0 ==v_temp)
{
/*if x0 is part of the basic varible set exchange with a nonbasic
 * variable with a positive c coefficient */
  if ( (index = search_array(B,size_B,0)) != -1)
  {
    calculate_pivot (matrix,matrix_l,c_temp,b,&v_temp,B,size_B,N,size_N
    + 1,astenn_positive_sampling(matrix[index],size_N+1,N),index);
    matrix_temp=matrix;
    matrix=matrix_l;
    matrix_l = matrix_temp;
  }
  
/*remove x0 from the set of non basic variables (exchange it with the last
 * column */
for (index = 0;index < size_N;index++)
{
  if (N[index] == 0)
  {
    for (index_1 = 0;index_1 < size_B;index_1++)
    {
    matrix[index_1][index] = matrix[index_1][size_N];  
    }
    N[index] = N[size_N];
    }
}
memset (c_temp,0,size_N *sizeof(float));
/*substitute all basic variabled in the original objective function*/
for (index = 0;index < size_B;index++)
{
if (B[index] <= size_N)
{
for (index_1 = 0;index_1 < size_N;index_1++)
    {
     c_temp[index_1] = c_temp[index_1] + c[(B[index] - 1)] * -matrix[index][index_1]; 
    }
v_temp = v_temp + (c[(B[index] - 1)] * b[index]);
}
}

for (index = 0;index < size_N;index++)
{
if (N[index] <= size_N)
{
  c_temp[index] = c_temp[index] + c[N[index] - 1];

}
c[index] = c_temp[index];
}
*v= *v + v_temp;

free(c_temp);

}
else 
{
printf ("\ainfisable\n");
*v = INFINITY;
}

}
         
}



