#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    char eingabe;

    printf("Gebe einen Buchstaben ein: \n");
    scanf(" %c", &eingabe);

    int buchstabe = toupper(eingabe);
    bool vokal = false;

    switch (buchstabe) {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            vokal = true;
            break;
    }

    printf("%c ist ein Vokal: %s\n", buchstabe, vokal ? "true" : "false");
    return 0;
}
