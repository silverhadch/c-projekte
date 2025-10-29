# include "stdio.h"

void dreieck(int* size) {
    for (int i = 0; i < *size; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void quadrat(int* size) {
    for (int i = 0; i < *size; i++) {
        for (int j = 0; j <= *size; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void kreis(int* size) {
    int radius = *size / 2;
    for (int i = 0; i <= *size; i++) {
        for (int j = 0; j <= *size; j++) {
            // Die Rechnung passiert hier
            int dist = (i - radius) * (i - radius) + (j - radius) * (j - radius);
            /*
                i  → aktuelle Zeile (Y-Koordinate)
                j  → aktuelle Spalte (X-Koordinate)
                (i - radius) → vertikaler Abstand zum Mittelpunkt
                (j - radius) → horizontaler Abstand zum Mittelpunkt
                Beide Abstände werden quadriert und addiert → ergibt die quadratische Entfernung vom Mittelpunkt
            */
            if (dist <= radius * radius) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int auswahl;
    printf("Gebe Dreieck (0), Quadrat (1) oder Kreis (2) ein: \n");
    scanf("%d", &auswahl);

    int size;
    printf("Gebe Groeße als Ganzzahl (beim Kreis geht nur gerade Ganzzahlen) ein: \n");
    scanf("%d", &size);

    if (auswahl == 0) {
        dreieck(&size);
    } else if (auswahl == 1) {
        quadrat(&size);
    } else if (auswahl == 2) {
        kreis(&size);
    }

    return 0;
}