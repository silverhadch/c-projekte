# include "stdio.h"

int main() {
    int zahl, geraten = 0;
    const int geheim = 7;
    int versuche = 0;

    printf("Errate die Zahl zwischen 1 und 10:\n");

    while (geraten != geheim) {
        printf("Dein Tipp: ");
        scanf("%d", &zahl);

        if (zahl < geheim) {
            printf("Zu klein!\n");
        } else if (zahl > geheim) {
            printf("Zu gross!\n");
        } else {
            printf("Richtig geraten!\n");
            geraten = zahl;
        }
        versuche++;
    }
    printf("Du hast %d Versuche gebraucht.\n", versuche);

    return 0;
}