# include <stdio.h>

int main() {
    int input;
    printf("Enter the Number: \n");
    scanf("%d",&input);

    if (input % 2 == 0) {
        printf("%d is an even number",input);
    } else {
        printf("%d is an odd number",input);
    }

    return 0;
}