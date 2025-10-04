#include <stdio.h>

void check(int* main_a){
    int b = 0;
    int* pB = &b;

    printf("local a from stackframe main is at addresse: %p\n", main_a);
    printf("local b from stackframe check is at addresse: %p\n", pB);

    if (pB < main_a){
        printf("Stack grows down.");
    } else {
        printf("Stack grows up.");
    }
}

int main(){
    // sollte im stack "höher" sein also wenn der stack nach unten wächst ist das hier größer und naher der wurzel des Stacks
    int a = 0;
    int* pA = &a;
    check(pA);
    return 0;
}
