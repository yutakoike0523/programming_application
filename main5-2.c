#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#ifndef M_PI
#define M_PI 3.14159
#endif  

double uniform_random() {
    return (double)rand() / ((double)RAND_MAX);
}

int binomial_random(double p) {
        if (uniform_random() < p) {
            return -1;
        }
        else{return 1;}
}
double normal_random(double mu, double sigma) {
    double u1 = uniform_random();
    double u2 = uniform_random();
    double z = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
    return mu + sigma * z;
}


int main(int argc ,char *argv[]){
//-1or1の二項分布
int i,N,sum=0;
double X,presumed_X,sum2=0;
N=atoi(argv[1]);

 time_t t;
    srand((unsigned)time(&t));


    double p = 0.5;
    for (i = 0; i < N; i++) {
        X= binomial_random(p);
        presumed_X=X+normal_random(0,1);
        if(presumed_X>0){
            presumed_X=1;
        }
        else{presumed_X=-1;}
        sum+=abs(presumed_X-X);
        sum2+=(presumed_X-X)*(presumed_X-X);
    }
    printf("N=%d\n",N);
    printf("MAE=%f\n",(double)sum/N);
    printf("MSE=%f\n",(double)sum2/N);
}