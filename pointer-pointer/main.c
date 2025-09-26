#include <stdio.h>

int main() {
    int x = 42;       // normale Variable
    int* p = &x;      // Pointer auf x
    int** pp = &p;    // Pointer auf Pointer p

    printf("Direkter Wert x: %d\n", x);
    printf("Wert über *p: %d\n", *p);
    printf("Wert über **pp: %d\n", **pp);

    printf("\nAdressen:\n");
    printf("Adresse von x (&x): %p\n", (void*)&x);
    printf("Wert von p (Adresse von x): %p\n", (void*)p);
    printf("Adresse von p (&p): %p\n", (void*)&p);
    printf("Wert von pp (Adresse von p): %p\n", (void*)pp);

    return 0;
}