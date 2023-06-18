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