# include <stdio.h>

int main() {
    
    printf("While Schleife:\n");
    int n = 1;
    while (n != 20) {
        n = n + 1;
        printf("Das Quadrat von %d ist %d.\n", n, n * n);
    }

    printf("For Schleife:\n");
    n = 1;
    for (n = 1; n < 21; n++) {
        printf("Das Quadrat von %d ist %d.\n", n, n * n);
    }

    printf("Do-While Schleife:\n");
    n = 1;
    do {
        printf("Das Quadrat von %d ist %d.\n", n, n * n);
        n = n + 1;
    }while (n != 21);

    return 0;
}