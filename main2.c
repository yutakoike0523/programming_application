#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double add(double p,double q);
double minus(double p,double q);
double multi(double p,double q);
double divi(double p,double q);

int main(int argc ,char *argv[]){
    double num1,num2,out;
    char *operator;
    double (*op)(double x,double y);

    num1=atof(argv[1]);
    operator=argv[2];
    num2=atof(argv[3]);

    if(num1<-1000 || num1>1000 || num2<-1000 || num2>1000) 
           {printf("invalid input\n");exit(-1);}
    else if(strcmp(operator,"+")==0)   {op=add;}
    else if(strcmp(operator,"-")==0)   {op=minus;}
    else if(strcmp(operator,"*")==0)   {op=multi;}
    else if(strcmp(operator,"/")==0)   {op=divi;}
    else {printf("invalid operator\n");exit(-1);}
    out =op(num1,num2);
    printf("result =%f\n",out);
    return 0;
}
double add(double p,double q){return p+q;}
double minus(double p,double q){return p-q;}
double multi(double p,double q){return p*q;}
double divi(double p,double q){return p/q;}