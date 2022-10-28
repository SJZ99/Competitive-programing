#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int r, c;
    scanf("%d %d", &r, &c);

    char input[r][c];
    int arround[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            scanf(" %hhd", &input[i][j]);
            if(input[i][j] == 1) {
                input[i][j] = 9; // boom
            }
        }
    }

    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {

            if(input[i][j] == 9) {
                for(int k = 0; k < 8; ++k) {
                    if(i + arround[k][0] >= 0 && i + arround[k][0] < r
                    && j + arround[k][1] >= 0 && j + arround[k][1] < c) {
                        if(input[i + arround[k][0]][j + arround[k][1]] < 9) {
                            ++input[i + arround[k][0]][j + arround[k][1]];
                        }
                    }
                }
            }
        }
    }

    //  for(int i = 0; i < r; ++i) {
    //     for(int j = 0; j < c; ++j) {
    //         printf("%d ", input[i][j]);
    //     }
    //     printf("\n");
    // }

    char output[15] = "";
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            switch (input[i][j]) {
                case 0:
                    strcpy(output, " :zero: ");
                    break;
                case 1:
                    strcpy(output, " :one: ");
                    break;
                case 2:
                    strcpy(output, " :two: ");
                    break;
                case 3:
                    strcpy(output, " :three: ");
                    break;
                case 4:
                    strcpy(output, " :four: ");
                    break;
                case 5:
                    strcpy(output, " :five: ");
                    break;
                case 6:
                    strcpy(output, " :six: ");
                    break;
                case 7:
                    strcpy(output, " :seven: ");
                    break;
                case 8:
                    strcpy(output, " :eight: ");
                    break;
                case 9:
                    strcpy(output, " :boom: ");
                    break;
            }
            printf("||%s||", output);
            if(j != c - 1) {
                printf(" ");
            } else {
                printf("\n");
            }
        }
    }
    return 0;
}