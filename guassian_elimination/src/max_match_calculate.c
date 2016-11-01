#include "bipartite_graph.h"



int bpm(float **bpGraph, int checked[], int row_match[],int u, int row, int col)
{
    for (int v = 0; v < col; v++)
    {
        if (bpGraph[u][v] && !checked[v])
        {
            checked[v] = 1;/*mark v as visited since the node can be part of
            multiple match give a bipratitegraph*/ 
            if (row_match[v] < 0 || bpm(bpGraph, checked, row_match,row_match[v],row,col))
            {
                row_match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
 
int maxBPM(float **bpGraph, int row,int col)
{
    float **matrix;
    int exposed_f_index = 0;
    int matchR[col];
    int exposedR[col];
    matrix = (float**) malloc (sizeof(float*) * row);
if (NULL == matrix)
{
  return 0;
}


    memset(matchR, -1, sizeof(matchR));
    memset(exposedR, -1,sizeof(exposedR));
    int result = 0; 
    for (int u = 0; u < col; u++)
    {
        int seen[row];
        memset(seen, 0, sizeof(seen));
 
        if (bpm(bpGraph, seen, matchR,u,row,col))
            result++;
    
    }

      
while (exposed_f_index < col)
  {
  if (-1 != matchR[exposed_f_index])
   {
    exposedR[matchR[exposed_f_index]] = 0;
   }
   
   exposed_f_index = exposed_f_index + 1; 
  }

    int i = 0;
    int j = 0;
    for (i = 0;i<row;i++)
    {
      matrix[i]= bpGraph[i];
      if (-1 == matchR[i])
      {
        while (j < row)
        {
          if (-1 == exposedR[j])
          {
            exposedR[j]=0;
            break;
          }

          j++;
        }
        bpGraph[i]=matrix[j];
        continue;
      }
      else if (matchR[i] <= i)
      {
      bpGraph[i] = matrix[matchR[i]];
      }
      else
      {
      bpGraph[i] = bpGraph[matchR[i]];
      }

    }
    free (matrix);
    return result;
}
