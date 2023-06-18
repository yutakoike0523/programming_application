#include "main5-1.h"

double uniform_random() {
    return ((double)rand() / ((double)RAND_MAX ));
}

double normal_random(double mu, double sigma) {
    double u1 = uniform_random();
    double u2 = uniform_random();
    double z = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
    return mu + sigma * z;
}
int main(int argc ,char *argv[]){
 printf("=== normal Distribution ===\n");
    int i,N;
    double sum = 0;
    double sum2 = 0;
    N=atoi(argv[1]);
        for (i = 0; i < N; i++) {
            double u = normal_random(0,1);
            sum += u;
            sum2 += u * u;
        }
        double mean = sum / N;
        double var = sum2 / N - mean * mean;
        double std = sqrt(var);
        printf("N=%d\n",N);
        printf("Mean: %f\n", mean);
        printf("Variance: %f\n", var);
        printf("Standard Deviation: %f\n", std);
}