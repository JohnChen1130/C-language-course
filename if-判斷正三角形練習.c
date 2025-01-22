#include <stdio.h>
#include <stdlib.h>
//正三角形判斷練習
/*
輸入某三角形的三邊長（皆為整數），
判斷此三角形是不是正三角形
*/

int main(void)
{
    int a, b, c;
    printf("Please enter the lengths:");
    scanf("%d%d%d", &a, &b, &c);
    if (a == b && b == c && c == a) {
        printf("正三角形！！");
    } else {
        printf("不是正三角形");
    }
    return 0;
}