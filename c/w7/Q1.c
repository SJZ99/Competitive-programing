#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    int number[100] = {0};
    char score[100] = {0};
    // fetch input
    int len = 0;
    scanf("%d", &len);
    for(int i = 0; i < len; ++i) {
        scanf(" %d %d", number + i, score + i);
    }

    char index = -1;
    int min = INT_MAX;
    int temp;
    for(int i = 0; i < len; ++i) {
        min = INT_MAX;
        index = -1;

        for(int j = 0; j < len - i; ++j) {
            if(score[j] < min) {
                index = j;
                min = score[j];
            } else if(score[j] == min && number[j] > number[index]) {
                index = j;
                min = score[j];
            }
        }

        temp = min;
        score[index] = score[len - 1 - i];
        score[len - 1 - i] = temp;

        temp = number[index];
        number[index] = number[len - 1 - i];
        number[len - 1 - i] = temp;
    }

    for(int i = 0; i < len; ++i) {
        printf("%d %d\n", number[i], score[i]);
    }
    return 0;
}