#include <stdio.h>
#include <stdlib.h>

int main(void){
    int guess, answer, count;
    answer = 10;
    count = 1;

    printf("Please enter your guess: ");
    scanf("%d", &guess);

    while (guess != answer) {
        if(guess > answer) {
            printf("Too large!\n");
        } else {
            printf("Too small!\n");
        }
        printf("Please enter your guess: ");
        scanf("%d", &guess);
        count = count + 1;
    }
    printf("Correct!!!(猜%d次)\n", count);

    return 0;
}

