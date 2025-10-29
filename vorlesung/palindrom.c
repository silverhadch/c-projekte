# include "stdio.h"
# include "stdbool.h"
# include "string.h"

bool is_palindrom(const char* eingabe){
    int lenght = strlen(eingabe);
    char first[(lenght / 2) + 1];
    char second[lenght - (lenght / 2) + 1];

    strncpy(first, eingabe, (lenght / 2));
    first[(lenght / 2)] = '\0'; // null-terminate
    strcpy(second, eingabe + (lenght / 2)); 

    if (strcmp(second, first) == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    char eingabe[100];
    printf("Gebe ein Wort (Max: 99 Buchstaben) ein: \n");
    scanf("%99s", eingabe);

    if (is_palindrom(eingabe)) {
        printf("%s ist ein Palindrom.\n", eingabe);
    } else {
        printf("%s ist ein kein Palindrom.\n", eingabe);
    }

    return 0;
}