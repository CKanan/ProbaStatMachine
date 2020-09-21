#include"ProbaStatMachine.h"

//Global variables
int N=100;
int l=0,c=0;

//This function is used for open file
FILE *OpenFile(char *filename){
    FILE *fp=fopen(filename,"r");
    if(!fp){
        printf("File couldn't be open\n");
        exit(1);
    }
    return fp;
}

//This function read csv file and store in 2d array
float** storeInArray(char *filename){

    FILE *fp=OpenFile(filename);
    if(fp==NULL){
        exit(1);
    }

    char line[1000];
    float** ar;
    int i=0,j=0;

    //Dynamic allocation
    ar= malloc(sizeof(float*) * N);
    for(int k = 0; k < N; k++) {
        ar[k] = malloc(sizeof(float*) * N);
    }

    //reading file and store in 2D array
    while(fgets(line,sizeof(line),fp)){
        char *token;
        token=strtok(line,";");
        j=0;
        while (token!=NULL){
            ar[i][j]=atof(token);  
            token=strtok(NULL,";");
            j++;
        }
        i++;
    }
    l=i; //number of lines
    c=j; //number of columns

    return ar;
}

//This function free data
void freeData(float** ar){
    for(int i = 0; i < N; i++) {
        free(ar[i]);
    }
    free(ar);
}

//This function prints distribution table
void print_dist_table(float** ar){
    printf("\n\t\t-----------------DISTRIBUTION TABLE-------------------------\n\n");
    for(int a=0;a<l;a++){
        for(int b=0;b<c;b++)
            printf("  %.4f  ",ar[a][b]);
        printf("\n");       
    }
    printf("\n");
}

//Check that distribution has  given line  
int checkLine(float** ar,float line){
    for(int a=0;a<l;a++){
        if(line==ar[a][0]) return 0;
    }
    return 1;
}

//Check that distribution has  given column
int checkCol(float** ar,float col){    
    for(int b=0;b<c;b++){
        if(col==ar[0][b]) return 0;
    }
    return 1;
}

//This function prints result
void print_result(float** ar,float line,float col){ 
    ar[0][0]=NAN;
    for(int a=0;a<l;a++){
        for(int b=0;b<c;b++){
            if(line ==ar[a][0] && col==ar[0][b]){
                printf("Result is %.4f\n",ar[a][b]);
            }      
        }
    }
    freeData(ar);
}

//Collection of functions
void function(float** ar,float line,float col){
    char op;
    option: printf("Do you want to see distribution table? (Y/n) : "); scanf("%s",&op);
    if(op!='Y' && op!='y' && op!='n' && op!='N'){
        printf("Wrong option entered\n"); goto option;
    } 
    else if(op=='Y' || op=='y') print_dist_table(ar);
    
    again: printf("Give line : "); scanf("%f",&line);
    if(checkLine(ar,line)==1){
        printf("Wrong line\n"); goto again;
    } 
    try: printf("Give column : "); scanf("%f",&col);
    if(checkCol(ar,col)==1){
        printf("Wrong column\n"); goto try;
    }
    print_result(ar,line,col); 
}