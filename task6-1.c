/*
cos x − x^2 = 0 (7.1)
式 (７. １) の実根をニュートン法で求めるアルゴリズム (もしくは, フローチャート)
及びプログラムを書いてみて.
(収束判定の誤差が EPS = 1.0e-6 より小さくなったら, 収束したとする).
最大繰り返す回数は, ５０回とする.
初期値を変えて, 収束速度を検討してみよ.
さらに, ２分法と比較して, 収束速度を検討してもよ*/
#include <stdio.h>
#include <math.h>

double f(double x) {
    return cos(x) - x*x;
}

double f_prime(double x) {
    return -sin(x) - 2*x;
}

double newton(double initial_guess, double epsilon, int max_iterations, int *count) {
    double x = initial_guess;

    *count = 0; // countの初期化を追加
    for (int i = 0; i < max_iterations; i++) {
        double f_x = f(x);
        double f_prime_x = f_prime(x);

        if (fabs(f_prime_x) < epsilon) {
            printf("Root not found\n");
            return 0;
        }

        double x_next = x - f_x / f_prime_x;

        if (fabs(x_next - x) / fabs(x) < epsilon) {
            return x_next;
        }

        x = x_next;
        (*count)++; // countのインクリメントを修正
    }

    printf("Root not found\n");
    return 0;
}



int main() {
    double x0[4]={1,5,10,100};
    double epsilon = 1e-6;
    int max_iterations = 50;
    for(int i=0;i<4;i++){
        int count; // countの宣言を修正
        double root = newton(x0[i], epsilon, max_iterations, &count);
    if (root != 0) {
         printf("x0=%f\n",x0[i]);
        printf("Root: %lf\n", root);
        printf("Count: %d\n", count);
    }
    }
    return 0;
}
