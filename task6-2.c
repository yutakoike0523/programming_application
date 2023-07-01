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

double bisection(double a, double b, double epsilon, int max_iterations, int *count) {
    if (f(a) * f(b) >= 0) {
        printf("Answer not found\n");
        return 0;
    }

    *count = 0;
    for (int i = 0; i < max_iterations; i++) {
        double c = (a + b) / 2;
        (*count)++;

        if (fabs(a - b) < epsilon) {
            return a;
        } else if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    printf("Answer not found\n");
    return 0;
}

int main() {
    double b[4]={1,5,10,100};
    double epsilon = 1e-6;
    int max_iterations = 50;
    for(int i=0;i<4;i++){
    int count = 0;
    double a = 0;

    double root = bisection(a, b[i], epsilon, max_iterations, &count);

    if (root != 0) {
        printf("b=%f\n",b[i]);
        printf("Root: %lf\n", root);
        printf("Count: %d\n", count);
    }
    }
    return 0;
}
