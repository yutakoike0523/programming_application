#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#ifndef M_PI
#define M_PI 3.14159
#endif  
#define ARRAY_SIZE 10000
FILE *fp;

double uniform_random() {
    return (double)rand() / ((double)RAND_MAX);
}

double normal_random(double mu, double sigma) {
    double u1 = uniform_random();
    double u2 = uniform_random();
    double z = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
    return mu + sigma * z;
}

int main(void){
  
    fp =  fopen("sample1.txt", "r");
    int i,sum=0;
    int array[ARRAY_SIZE];
    double presumed_X,X,sum2=0,j=0.1;
    while(j<=1.1){
        sum=0;
        for (int i = 0; i < ARRAY_SIZE; i++){
            fscanf(fp, "%d", &array[i]);
            X= array[i];
            presumed_X=X+normal_random(0,sqrt(j));
            if(presumed_X>0){
            presumed_X=1;
            }
            else{presumed_X=-1;}
            sum+=abs(presumed_X-X);
        }  
        printf("dispersion=%f MAE=%f\n",j,(double)sum/ARRAY_SIZE);
        j+=0.2;
    }
}