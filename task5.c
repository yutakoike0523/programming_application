/*
cos x − x^2 = 0 (7.1)
式 (７. １) の実根を a=0, b=1 として 2 分法で求めるプログラムを書いてみて.
(収束判定の誤差が EPS = 1.0e-6 より小さくなったら, 収束したとする).
最大繰り返す回数は, ５０回とする.*/

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
    int count = 0;
    double a = 0;
    double b = 1;
    double epsilon = 1e-6;
    int max_iterations = 50;

    double root = bisection(a, b, epsilon, max_iterations, &count);

    if (root != 0) {
        printf("Root: %lf\n", root);
        printf("Count: %d\n", count);
    }

    return 0;
}
