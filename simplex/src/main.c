#include "header.h"






int main (int argc, char * args[])
{

float **matrix = generate_matrix(2,2,zero_array);
float *c = generate_array (2,zero_array); 
float *b = generate_array (2,zero_array); 
float v = 0;

v = 0;

matrix[0][0]=1;
matrix[0][1]=2;

matrix[1][0]=-2;
matrix[1][1]=-6;





b[0]=4;
b[1]=-12;


c[0]=1;
c[1]=-2;



clock_t before = clock();



simplex (&matrix,c,&v,b,2,2,bland_rule );
clock_t after= clock();

  printf("using bland's rule for pivot selection  %ju ticks\n",(uintmax_t)(after - before));







v = 0;

matrix[0][0]=1;
matrix[0][1]=2;

matrix[1][0]=-2;
matrix[1][1]=-6;





b[0]=4;
b[1]=-12;


c[0]=1;
c[1]=-2;



before = clock();



simplex (&matrix,c,&v,b,2,2,max_positive );
after= clock();

  printf("using largest positive coeffcient pivot selection  %ju ticks\n",(uintmax_t)(after - before));





free_matrix(matrix,2);
free (c);
free (b);


return FAILURE;  /*return 0*/
}
