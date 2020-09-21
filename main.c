#include<stdio.h>
#include<stdlib.h>
#include"ProbaStatMachine.h"

int main(int argc,char **argv){
    
    int d;
    float line,col;
    float** data;

    printf("-----Welcome to the Proba Stat Machine-----\n\n");
    printf("1 for Normal distribution\n2 for Student’s t-distribution\n3 for Chi-square distribution\n4 for F-distribution\n5 for Binomial distribution\n\n");
    begin: printf("Please, select one distribution: "); scanf("%d",&d);
    switch (d){
    
    case 1: 
        data=storeInArray("Loi Normal.csv");
        function(data,line,col);
        break;
    
    case 2: 
        data=storeInArray("Student_T.csv");
        function(data,line,col);
        break;
    
    case 3:
        data=storeInArray("Chi_Square.csv");
        function(data,line,col);
        break;
 
    case 4: 
        data=storeInArray("F.csv");
        function(data,line,col);
        break;

    case 5: printf("Sorry, it doesnt work\n");
        break;    
 
    default: printf("Wrong selection\n");
        goto begin;
    
    }

    return 0;
}