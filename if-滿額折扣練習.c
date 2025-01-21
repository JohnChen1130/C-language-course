#include <stdio.h>
#include <stdlib.h>
//滿額折扣計算練習
/*
某吃到飽餐廳的套餐一人300元（無額外費用），
今日因周年慶特價，每桌滿3000元打8折
試寫程式讓服務生輸入一桌消費人數後，
輸出該桌應付總額
*/
int main(void)
{
    int num, total; //人數、總價
    printf("請輸入用餐人數：");
    scanf("%d", &num);
    total = num * 300;

    if (total >= 3000) 
    {
        total = total * 0.8;
        printf("總價是：%d\n", total);
    } else 
    {
        printf("總價是：%d\n", total);
    }

    return 0;
}
