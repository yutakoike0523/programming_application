/*
x^2 − x − 1 = 0 (6.1)
x_(n+1)=1+1/x_n (6,2)  x_(n+1)=√(x_n+1)(6,4)  x_(n+1)=(〖x_n〗^2+1)/(2x_n-1) (6,5)
式 (6.1) の方程式に対して,
漸近式 (6.2), (6.5),(6.6) を使って, 方程式の解を求めてよう.
(相対誤差が EPS = 1.0e-6 より小さくなったら, 収束したとする).
さらに, この三つの漸近式の収束の速さを検討してみて.*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define EPS 1.0e-6
int solve_1(int N){
    double Xn=100.0;
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
    double Xn=100.0;
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
    double Xn=100.0;
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






