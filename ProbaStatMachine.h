#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

FILE *OpenFile(char *filename);
float** storeInArray(char *filename);
void freeData(float** ar);
void print_dist_table(float** ar);
int checkLine(float** ar,float line);
int checkCol(float** ar,float col);
void print_result(float** ar,float line,float col);
void function(float** ar,float line,float col);