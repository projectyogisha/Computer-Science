#ifndef BIPARTITE_GRAPH
#define  BIPARTITE_GRAPH

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bpm(float **bpGraph,int seen[], int matchR[],int u,int row, int col);
int maxBPM(float **bpGraph, int row,int col);
#endif 
