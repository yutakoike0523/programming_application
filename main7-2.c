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
    double initial_guess = 0.5;
    double epsilon = 1e-6;
    int max_iterations = 50;

    int count; // countの宣言を修正
    double root = newton(initial_guess, epsilon, max_iterations, &count);

    if (root != 0) {
        printf("Root: %lf\n", root);
        printf("Count: %d\n", count);
    }

    return 0;
}
