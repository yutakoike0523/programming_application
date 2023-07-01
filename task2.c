/*[システム概要]
送信側は, 値が 1 または-1 である乱数 x を生成し, 送信します.
(p(x=1) = 0.5; p(x=-1) = 0.5)
通信路では, 送信信号に正規分布に従うガウス雑音 n を加えます.
受信側は, 受信信号 x+n から送信信号 x を推定します.
[推定方法]
x+n > 0 の場合, 推定値 x =1 とします.
x+n <= 0 の場合, 推定値 x=-1 とします.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double uniform_random() {
    return (double)rand() / ((double)RAND_MAX);
}

int binomial_random(double p) {
        if (uniform_random() < p) {
            return -1;
        }
        else{return 1;}
}
//送信側
int main(){
    int i,NUM=10000;

    srand(time(NULL));

    FILE* fp;
    fp =  fopen("sample1.txt", "w"); // バイナリモードで書き込み
    if (fp == NULL) {
    printf("Can not open the file.\n");
    return -1;
    }
    // 乱数を生成して表示する
    for (i = 0; i < NUM; i++) {
    fprintf(fp, "%d ",binomial_random(0.5) );
    }
    fclose(fp);
}