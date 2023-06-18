
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#ifndef M_PI
#define M_PI 3.14159
#endif  


// 一様分布の乱数を生成する関数
double uniform_random() {
    return (double)rand() / ((double)RAND_MAX + 1);
}

// 二項分布の乱数を生成する関数
int binomial_random(int n, double p) {
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (uniform_random() < p) {
            x++;
        }
    }
    return x;
}

// 指数分布の乱数を生成する関数
double exponential_random(double lambda) {
    return -(log(uniform_random()) / lambda);
}

// 正規分布の乱数を生成する関数
double normal_random(double mu, double sigma) {
    double u1 = uniform_random();
    double u2 = uniform_random();
    double z = sqrt(-2 * log(u1)) * cos(2 * M_PI * u2);
    return mu + sigma * z;
}

int main(int argc ,char *argv[]) {
    int i, x,N;
    double sum, sum2;

    N=atoi(argv[1]);

    time_t t;
    srand((unsigned)time(&t));

    // 一様分布の乱数を生成
    printf("=== Uniform Distribution ===\n");
    sum = 0;
    sum2 = 0;
    for (i = 0; i < N; i++) {
        double u = uniform_random();
        sum += u;
        sum2 += u * u;
    }
    double mean = sum / N;
    double var = sum2 / N - mean * mean;
    double std = sqrt(var);
    printf("Mean: %f\n", mean);
    printf("Variance: %f\n", var);
    printf("Standard Deviation: %f\n", std);

    // 二項分布の乱数を生成
    printf("\n=== Binomial Distribution ===\n");
    sum = 0;
    sum2 = 0;
    int n = 100;
    double p = 0.5;
    for (i = 0; i < N; i++) {
        x = binomial_random(n, p);
        sum += x;
        sum2 += x * x;
    }
    mean = sum / (double)N;
    var = sum2 / N - mean * mean;
    std = sqrt(var);
    printf("Mean: %f\n", mean);
    printf("Variance: %f\n", var);
    printf("Standard Deviation: %f\n", std);

    // 指数分布の乱数を生成
    printf("\n=== Exponential Distribution ===\n");
    sum = 0;
    sum2 = 0;
    double lambda = 1.0;
    for (i = 0; i < N; i++) {
        double x = exponential_random(lambda);
        sum += x;
        sum2 += x * x;
    }
    mean = sum / N;
    var = sum2/N -mean*mean;
    std =sqrt(var);
    printf("Mean: %f\n", mean);
    printf("Variance: %f\n", var);
    printf("Standard Deviation: %f\n", std);
}
