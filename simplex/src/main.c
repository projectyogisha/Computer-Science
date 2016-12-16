#include "header.h"






int main (int argc, char * args[])
{

float **matrix = generate_matrix(4,3,random_array);
float *c = generate_array (3,random_array); 
float *b = generate_array (4,random_array); 
float v = 0;

/*
matrix[0][0]=1;
matrix[0][1]=-1;
matrix[0][2]=0;
//matrix[0][3]=2;

matrix[1][0]=2;
matrix[1][1]=1;
matrix[1][2]=0;
//matrix[1][3]=2;

matrix[2][0]=1;
matrix[2][1]=1;
matrix[2][2]=1;
//matrix[2][3]=2;

matrix[3][0]=0;
matrix[3][1]=1;
matrix[3][2]=3;
//matrix[3][3]=2;






b[0]=1;
b[1]=2;
b[2]=400;
b[3]=600;


c[0]=5;
c[1]=-3;
c[2]=13;

calculate_pivot (matrix,matrix_l,c,b,&v,B,3,N,3,1,6);
temp=matrix;
matrix=matrix_l;
matrix_l = temp;


calculate_pivot (matrix,matrix_l,c,b,&v,B,3,N,3,3,5);
temp=matrix;
matrix=matrix_l;
matrix_l = temp;

   clock_t before = clock();
  
simplex (matrix,c,&v,b,2,2,bland_rule);
   clock_t after = clock();
  printf("number of %ju ticks\n",(uintmax_t)(after - before));




v = 0;
matrix[0][0]=1;
matrix[0][1]=0;
matrix[0][2]=0;
//matrix[0][3]=2;

matrix[1][0]=0;
matrix[1][1]=1;
matrix[1][2]=0;
//matrix[1][3]=2;

matrix[2][0]=1;
matrix[2][1]=1;
matrix[2][2]=1;
//matrix[2][3]=2;

matrix[3][0]=0;
matrix[3][1]=1;
matrix[3][2]=3;
//matrix[3][3]=2;






b[0]=200;
b[1]=300;
b[2]=400;
b[3]=600;


c[0]=1;
c[1]=6;
c[2]=13;





before = clock();

simplex (matrix,c,&v,b,3,4,max_positive);
after= clock();

  printf("number of  %ju ticks\n",(uintmax_t)(after - before));


*/
v = 0;

matrix[0][0]=1;
matrix[0][1]=2;
matrix[0][2]=0;
//matrix[0][3]=2;

matrix[1][0]=2;
matrix[1][1]=66;
matrix[1][2]=0;
//matrix[1][3]=2;

matrix[2][0]=0;
matrix[2][1]=1;
matrix[2][2]=1;
//matrix[2][3]=2;

matrix[3][0]=0;
matrix[3][1]=1;
matrix[3][2]=3;
//matrix[3][3]=2;






b[0]=4;
b[1]=12;
b[2]=1;
b[3]=600;


c[0]=1;
c[1]=2;
c[2]=13;





clock_t before = clock();

simplex (matrix,c,&v,b,2,3,bland_rule );
clock_t after= clock();

  printf("number of  %ju ticks\n",(uintmax_t)(after - before));


//calculate_pivot (matrix,matrix_l,c,b,&v,B,3,N,3,2,3);
//display_matrix(matrix,2,2);
//display_matrix(matrix_l,3,3);
//display_array(b,2);
//display_array(c,2);
//display_array(&v,1);

return FAILURE;  /*return 0*/
}
