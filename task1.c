/*正規分布に従う乱数を 10,000 個生成し,1000 個ずつ増やしながら,
それぞれの場合について平均値, 分散, および標準偏差を計算し,
元の平均値との差を出力してください.
また, 出力結果についても検討してください.*/

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