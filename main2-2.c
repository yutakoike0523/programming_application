#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
    int i,n;
    double p;
    p=atof(argv[1]);
    n=atoi(argv[2]);

    for(i=0;i<n;i++){
        if((double)rand()/RAND_MAX <p){
            printf("1");
        }
        else printf("0");
    }
    printf("\n");
}