#include <stdio.h>
#include <stdbool.h>

void sort(int* a, int* b, int* c){
    printf("a?\n");
    scanf(" %d", a);

    printf("b?\n");
    scanf(" %d", b);

    printf("c?\n");
    scanf(" %d", c);

    if (*a > *b) {
        int t = *a;
        *a = *b;
        *b = t;
    }

    if (*a > *c) {
        int t = *a;
        *a = *c;
        *c = t;
    }

    if (*b > *c) {
        int t = *b;
        *b = *c;
        *c = t;
    }
}

int main(){
    int a;
    int b;
    int c;

    sort(&a, &b, &c);
    printf("a: %d, b: %d, c: %d\n", a, b, c);

    return 0;
}
