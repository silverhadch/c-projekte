#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrom(const char *eingabe) {
    int len = strlen(eingabe);
    for (int i = 0; i < len / 2; i++) {
        if (eingabe[i] != eingabe[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main(void) {
    char eingabe[100];
    printf("Gebe ein Wort (Max: 99 Buchstaben) ein: \n");
    scanf("%99s", eingabe);

    if (is_palindrom(eingabe)) {
        printf("%s ist ein Palindrom.\n", eingabe);
    } else {
        printf("%s ist kein Palindrom.\n", eingabe);
    }

    return 0;
}