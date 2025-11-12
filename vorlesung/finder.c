#include <stdio.h>
#include <math.h>

#define SIZE 10

struct coordinates {
    int grid[SIZE][SIZE];
};

double distance(int x1, int y1, int x2, int y2) {
    // Use double for accurate distance calculation
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dist = sqrt(dx * dx + dy * dy);

    return dist;
}


int main(void) {
    struct coordinates cord = {0}; // initialize all to 0

    int x1, y1, x2, y2;

    printf("Gebe Koordinate x1 ein (0–9): ");
    scanf("%d", &x1);

    printf("Gebe Koordinate y1 ein (0–9): ");
    scanf("%d", &y1);

    printf("Gebe Koordinate x2 ein (0–9): ");
    scanf("%d", &x2);

    printf("Gebe Koordinate y2 ein (0–9): ");
    scanf("%d", &y2);

    // check that coordinates are valid
    if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE || x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE) {
        printf("Fehler: Koordinaten außerhalb des Bereichs!\n");
        return 1;
    }

    cord.grid[y1][x1] = 1; // mark first point
    cord.grid[y2][x2] = 2; // mark second point

    printf("\nKoordinatensystem (10x10):\n");
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            printf("%d ", cord.grid[y][x]);
        }
        printf("\n");
    }

    printf("\nPunkt 1: (%d, %d)\n", x1, y1);
    printf("Punkt 2: (%d, %d)\n", x2, y2);

    double dist = distance(x1, y1, x2, y2);
    printf("Distance: %.2f\n", dist);

    return 0;
}
