#include <stdio.h>

int main(void) {
    printf("    ");
    for (int i = 1; i <= 12; i++) {
        printf("%4d", i);
    }
    printf("\n----------------------------------------------------\n");

    for (int i = 1; i <= 12; i++) {
        printf("%2d |", i);
        for (int j = 1; j <= 12; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }

    return 0;
}