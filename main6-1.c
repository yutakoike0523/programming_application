#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define EPS 1.0e-6
int solve_1(int N){
    double Xn=1.0;
    int n;
        for(n=1;n<N;n++){
        Xn=1.0+1.0/Xn;
        
        if(fabs((1.0+1.0/Xn)-Xn)/Xn<EPS)
        {
        printf("solution:%f\n",Xn);
        printf("count:%d\n",n+1);
        break;}
        }
}

int solve_2(int N){
    double Xn=1.0;
    int n;
        for(n=1;n<N;n++){
            Xn=pow(Xn+1,0.5);
       
        if(fabs(pow(Xn+1,0.5)-Xn)/Xn<EPS)
        {
        printf("solution:%f\n",Xn);
        printf("count:%d\n",n+1);
        break;}    
        }
}

int solve_3(int N){
    double Xn=1.0;
    int n;
        for(n=1;n<N;n++){
            Xn=(pow(Xn,2)+1)/(2*Xn-1);
        if(fabs(((pow(Xn,2)+1)/(2*Xn-1))-Xn)/Xn<EPS)
        {
        printf("solution:%f\n",Xn);
        printf("count:%d\n",n+1);
        break;}    
        }
}


int main(int argc ,char *argv[]){
    int n,N;
    N=atoi(argv[1]);
    solve_1(N);
    solve_2(N);
    solve_3(N);
}






