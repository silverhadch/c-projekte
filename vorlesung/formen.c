# include "stdio.h"

void dreieck(int* size) {

}

void quadrat(int* size) {
    
}

void kreis(int* size) {
    
}

int main() {
    int auswahl;
    printf("Gebe Dreieck (0), Quadrat (1) oder Kreis (2) ein: \n");
    scanf("%d", &auswahl);

    int size;
    printf("Gebe Groeße als Ganzzahl ein: \n");
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