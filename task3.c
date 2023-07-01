/*値が 1 または-1 である乱数 x を 10000 回生成し, ファイルに保存する.
送信側は, 保存されたファイルのデータを読み込んで送信する.
通信路は, 通信路雑音の分散を 0.1 から 1.1 まで,0.2 ずつ変化させた場合を考えます.
送信データがそれぞれの通信路を通過した後, 受信側では送信データを推定します.
各通信路での平均絶対誤差を計算し, 雑音の分散と平均絶対誤差の関係を検討してみて.*/

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

//受信側
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