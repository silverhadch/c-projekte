#include <stdio.h>
#include <math.h>

#define SIZE 10

struct coordinates {
    int grid[SIZE][SIZE];
};

double distance(int x1, int y1, int x2, int y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx * dx + dy * dy);
}

int main(void) {
    struct coordinates cord = {0};
    int x1, y1, x2, y2;
    int mode; // Verkehrsmittel

    printf("Gebe Koordinate x1 ein (0–9): ");
    scanf("%d", &x1);

    printf("Gebe Koordinate y1 ein (0–9): ");
    scanf("%d", &y1);

    printf("Gebe Koordinate x2 ein (0–9): ");
    scanf("%d", &x2);

    printf("Gebe Koordinate y2 ein (0–9): ");
    scanf("%d", &y2);

    if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE ||
        x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE) {
        printf("Fehler: Koordinaten außerhalb des Bereichs!\n");
        return 1;
    }

    cord.grid[y1][x1] = 1;
    cord.grid[y2][x2] = 2;

    printf("\nKoordinatensystem (10x10):\n");
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            printf("%d ", cord.grid[y][x]);
        }
        printf("\n");
    }

    double dist = distance(x1, y1, x2, y2);
    printf("\nDistanz zwischen den Punkten: %.2f Einheiten\n", dist);

    // Verkehrsmittel auswählen
    printf("\nWähle das Verkehrsmittel:\n");
    printf("1 - Auto (100 km/h)\n");
    printf("2 - Fahrrad (20 km/h)\n");
    printf("3 - Zu Fuß (5 km/h)\n");
    printf("Deine Auswahl: ");
    scanf("%d", &mode);

    double speed = 0.0;
    switch (mode) {
        case 1: speed = 100.0; break;
        case 2: speed = 20.0; break;
        case 3: speed = 5.0; break;
        default:
            printf("Ungültige Auswahl!\n");
            return 1;
    }

    // Wir nehmen an: 1 Gittereinheit = 1 km
    double time = dist / speed; // Stunden
    double minutes = time * 60.0;

    printf("\nVerkehrsmittel: ");
    if (mode == 1) printf("Auto\n");
    else if (mode == 2) printf("Fahrrad\n");
    else printf("Zu Fuß\n");

    printf("Fahrzeit: %.2f Stunden (≈ %.1f Minuten)\n", time, minutes);

    return 0;
}
