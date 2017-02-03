    #ifndef HEADER_H_INCLUDED
    #define HEADER_H_INCLUDED

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include <time.h>
    #include <math.h>

#include <stdint.h>

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


    #define RAND_MATRIX 1
    #define EMPTY_MATRIX 0

    /*******************************************************************************
                Function Prototypes
    *******************************************************************************/




/*common.c */
unsigned min(const float a,const float b);
unsigned max(const float a,const float b);
unsigned order_index ( const float *c,
                       const unsigned length, 
                       unsigned (*compare) (float a,float b));
float* random_array (unsigned row);
float* zero_array (unsigned row);
float** generate_matrix (unsigned row, unsigned col, float* (*function_array)(unsigned row));
float* generate_array (unsigned row,  float* (*function_array) (unsigned row));
void display_matrix (float **matrix, int row,int col);
void display_array (float *matrix, int row);
float**  resize_matrix  (float **matrix, unsigned row, unsigned col );
void free_matrix (float **matrix,const unsigned row);
unsigned search_array (const unsigned *array, unsigned length, unsigned value);
/*simplex.c */
unsigned max_positive (const float *c, const unsigned length ,const unsigned *N );
unsigned bland_rule (const float *c, const unsigned length, const unsigned *N );
unsigned astenn_positive_sampling (const float *c, const unsigned length, const unsigned *N);
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
                      unsigned l_index  /*leaving variable */  );

         void simplex (float ***matrix_t,  /*this is the entry matrix */
                       float *c,  /*this is the array objective function coefficients*/
                       float *v, /*cons*/
                       float *b,  /*this is the array of elements on set b*/
                       unsigned size_c, /*the size of Basic variables*/
                       unsigned size_b, /*size of non basic variables*/  
                       unsigned (*select_e) (const float *c,const unsigned
                       length,const unsigned *N));

void initialize_feasible_solution (float ***matrix_b,  /*this is the entry matrix */
                                   float ***matrix_l_b, /*this is the leaving matrix */     
                                   float *c,  /*this is the array objective function coefficients*/
                                   float *b,  /*this is the array of elements on set b*/
                                   float *v,  /*constant in the objective function */
                                   unsigned *B, /*set of basic variables*/
                                   unsigned size_B, /*the size of Basic variables*/
                                   unsigned *N, /*set of non basic variables*/
                                   unsigned size_N, /*size of non basic variables*/
                                   unsigned e_index,   /*entering variable */
                                   unsigned l_index,  /*leaving variable */ 
                                   unsigned (*select_e) (const float *c,const unsigned length,const unsigned *N));

    #endif // DLLHEADER_H_INCLUDED
