#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double exp_dist_inv(double u, double lambda) {
    return -log(1.0 - u) / lambda;
}

int main() {
    double u = 0.5; // 0から1までの一様分布の乱数
    double lambda = 1.0; // 指数分布のパラメータ
    double x = exp_dist_inv(u, lambda); // 逆関数による変換
    printf("u = %f\n", u);
    printf("lambda = %f\n", lambda);
    printf("x = %f\n", x);
    return 0;
}

