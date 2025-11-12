# include <stdio.h>

int main () {
    int input;
    bool prime = true;
    printf("Enter the Number: \n");
    scanf("%d",&input);

    for (int i = 2; i <= (input - 1); i++) {
        if (input % i == 0)
            prime = false;
    }

    if (prime) {
        printf("%d is a prime number.\n", input);
    } else {
        printf("%d is not a prime number.\n", input);
    }


    return 0;
}