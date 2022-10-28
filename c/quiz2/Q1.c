#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int m1[n][m], m2[n][m];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            scanf("%d", &m1[i][j]);
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            scanf(" %d", &m2[i][j]);
            m2[i][j] += m1[i][j];
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            printf("%d", m2[i][j]);
            if(j != m - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}