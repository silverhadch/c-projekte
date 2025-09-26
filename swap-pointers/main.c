# include <stdio.h>

void swap(int *pA, int *pB)
{
    int temp = *pA;
    *pA = *pB;
    *pB = temp;
}

int main(){

    int a = 3;
    int b = 5;

    swap(&a, &b);

    printf("a: %d\nb: %d\n", a, b);

    return 0;
}