#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define di(i) printf("%d\n", (i));
#define ds(i) printf("%s\n", (i));


void question() {
    srand(time(NULL));
    
    // generate answer;
    int ans[4] = {-1};
    for(int i = 0; i < 4; ++i) {
        bool isRepeat = false;
        do {
            int temp = rand() % 10;
            ans[i] = temp;

            for(int j = 0; j < i; ++j) {
                if(ans[j] == temp) {
                    isRepeat = true;
                    break;
                } else {
                    isRepeat = false;
                }
            }
        } while(isRepeat);
    }

    // user guess
    bool isCorrect = false;
    do {
        printf("Guess!\n");
        char input[5] = {'\0'};
        scanf("%s", input);
        if(input[4] != '\0') {
            printf("hmmmmm..., too long!\n");
        }

        // check isDigit and repeat
        bool error = false;
        for(int i = 0; i < 4; ++i) {
            if(input[i] - '0' > 9 || input[i] - '0' < 0) {
                printf("please input four number\n");
                error = true;
                break;
            }
            for(int j = 0; j < i; ++j) {
                if(input[i] == input[j]) {
                    printf("please input four non-repeating number!\n");
                    error = true;
                    break;
                }
            }
            if(error) break;
        }
        if(error) {
            continue;
        }

        // compare
        int a = 0, b = 0;
        for(int i = 0; i < 4; ++i) {
            int guess = input[i] - '0';
            for(int j = 0; j < 4; ++j) {
                if(guess == ans[j] && i == j) {
                    ++a;
                } else if(guess == ans[j]) {
                    ++b;
                }
            }
        }
        if(a == 4 && b == 0) {
            isCorrect = true;
            printf("YOU WIN!\n");
            continue;
        }
        printf("%dA%dB\n", a, b);
    } while(!isCorrect);
}

void answer() {
    int posible[10000];

    // set all posible answer
    int a, b, c, d;
    for(int i = 0; i < 10000; ++i) {
        int value = i + 1;
        posible[i] = value;
        a = value / 1000;
        b = value % 1000 / 100;
        c = value % 100 / 10;
        d = value % 10;
        if(a == b || b == c || c == d || a == c || a == d || b == d) {
            posible[i] = -1;
        }
    }

    while(true) {
        int test = -1;
        int A, B;
        for(int i = 0; i < 10000; ++i) {
            if(posible[i] != -1) {
                test = posible[i];
                break;
            }
        }

        // no answer match
        if(test == -1) {
            printf("YOU CHEAT!\n");
            return;
        }

        // pc guess
        printf("%04d\n", test);
        
        bool isValid = true;
        do {
            isValid = true;
            scanf(" %d %d", &A, &B);

            if(A > 4 || A < 0 || B > 4 || B < 0) {
                isValid = false;
                printf("please input guess result separated by space!\n");
            }
        } while (!isValid);
            
        if(A == 4 && B == 0) {
            printf("PC WIN!\n");
            return;
        }

        for(int i = 0; i < 10000; ++i) {
            if(posible[i] == -1) continue;
            int currA = 0, currB = 0;

            int t[4] = {
                test / 1000,
                test % 1000 / 100,
                test % 100 / 10,
                test % 10
            };

            int p[4] = {
                posible[i] / 1000,
                posible[i] % 1000 / 100,
                posible[i] % 100 / 10,
                posible[i] % 10,
            };

            for(int j = 0; j < 4; ++j) {
                for(int k = 0; k < 4; ++k) {
                    if(t[j] == p[k] && k == j) {
                        ++currA;
                    } else if(t[j] == p[k]) {
                        ++currB;
                    }
                }
            }
            if(currA != A || currB != B) {
                posible[i] = -1;
            }
        }
    }
}

int main(void) {

    // input mode
    int mode = 0;

    do {
        printf("Which mode do you want to enter? (1 or 2)\n1. guess\n2. question\n");
        scanf("%d", &mode);
    } while(mode != 1 && mode != 2);

    printf("-----------------------------\n");
    if(mode == 1) {
        question();
    } else {
        answer();
    }

    return 0;
}