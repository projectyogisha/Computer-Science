#include "header.h"



/*test function */
int main()
{
float **matrix = NULL;
int i = 0;

matrix = (float**) malloc (sizeof(float*) * N);
for (i = 0; i < N ;i++)
{
  matrix[i] = (float*) malloc (sizeof(float)*(N + 1));
}

matrix[0][0]=1;
matrix[0][1]=0;
matrix[0][2]=0;
matrix[0][3]=0;
matrix[0][4]=0; 
matrix[1][0]=0;
matrix[1][1]=1;
matrix[1][2]=0;
matrix[1][3]=0;
matrix[1][4]=2;
matrix[2][0]=0;
matrix[2][1]=0;
matrix[2][2]=1;
matrix[2][3]=0;
matrix[2][4]=0;
matrix[3][0]=0;
matrix[3][1]=0;
matrix[3][2]=0;
matrix[3][3]=1;
matrix[3][4]=0;



 gaussian_elimination (matrix, N, N+1);


 
 
    return 0;
}
