#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char in[200000] = {'\0'};
    int i = 0;
    while(scanf("%c", &in[i]) != EOF) {
        if((in[i] - 'A' >= 0 && in[i] - 'A' <= 25) ||
            in[i] - 'a' >= 0 && in[i] - 'a' <= 25) {

            if((in[i] - 'A' >= 0 && in[i] - 'A' <= 25)) {
                in[i] = 'a' + in[i] - 'A';
            }
            ++i;
        } else {
            in[i] = '\0';
        }
    }
    // for(int j = 0; j < 200000; ++j) {
    //     printf("%c", in[j]);
    // }

    for(int j = 0; j < 200000; ++j) {
        if(in[j] == '\0') {
            break;
        }
        if(in[j] != in[i - 1 - j]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}