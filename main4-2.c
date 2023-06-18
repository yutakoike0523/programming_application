
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159
#endif



int main(int argc ,char *argv[]){
    int N,i;
    double u_1,u_2,R,c,X,Y;
    N=atoi(argv[1]);
    for(i=0;i<N;i++){
        u_1=rand()/RAND_MAX;
        u_2=rand()/RAND_MAX;
        R=sqrt(2*log(u_1));
        c=2*M_PI*u_2;
        X=R*cos(c);
        Y=R*sin(c);
        printf("X=%f,Y=%f\n",X,Y);
        
    }
    
}