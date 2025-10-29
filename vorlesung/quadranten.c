#include <stdio.h>

int main() {
    float x, y;

    printf("Gebe Koordinate x ein: ");
    scanf("%f", &x);

    printf("Gebe Koordinate y ein: ");
    scanf("%f", &y);

    if (x == 0 && y == 0) {
        printf("x: %.2f und y: %.2f liegen im Ursprung.\n", x, y);
    } else if (x > 0 && y > 0) {
        printf("x: %.2f und y: %.2f liegen im 1. Quadranten.\n", x, y);
    } else if (x < 0 && y > 0) {
        printf("x: %.2f und y: %.2f liegen im 2. Quadranten.\n", x, y);
    } else if (x < 0 && y < 0) {
        printf("x: %.2f und y: %.2f liegen im 3. Quadranten.\n", x, y);
    } else if (x > 0 && y < 0) {
        printf("x: %.2f und y: %.2f liegen im 4. Quadranten.\n", x, y);
    } else if (x == 0) {
        printf("x: %.2f und y: %.2f liegen auf der y-Achse.\n", x, y);
    } else if (y == 0) {
        printf("x: %.2f und y: %.2f liegen auf der x-Achse.\n", x, y);
    }

    return 0;
}
