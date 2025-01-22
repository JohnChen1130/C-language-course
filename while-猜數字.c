#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int guess, answer;
    answer = 10;

    while (guess != answer) 
    {
        printf("Please enter your guess number: ");
        scanf("%d", &guess);
        if (guess > answer) 
        {
            printf("Too large!\n");
        } else if (guess < answer) 
        {
            printf("Too small!\n");
        } else 
        {
            printf("Correct!!!\n");
        }
    }

    return 0;
}