#include <stdio.h>
#include <limits.h>

int main(void) {
    // Konstanten für PI in verschiedenen Datentypen
    const float       pi_f  = 3.14159265358979323846f;
    const double      pi_d  = 3.14159265358979323846;
    const long double pi_ld = 3.14159265358979323846L;

    printf("PI-Werte in verschiedenen Datentypen:\n");
    printf("  float:       %.20f\n",  pi_f);
    printf("  double:      %.20lf\n", pi_d);
    printf("  long double: %.20Lf\n\n", pi_ld);

    // Ganzzahl-Demonstration
    int a = 0;
    printf("Integer-Infos:\n");
    printf("  sizeof(int): %zu Bytes\n", sizeof(a));
    printf("  INT_MIN:     %d\n", INT_MIN);
    printf("  INT_MAX:     %d\n\n", INT_MAX);

    // Wertebereich-Test
    a = 2147483647; // INT_MAX
    printf("a = %d (INT_MAX)\n", a);

    a += 1; // Überlauf
    printf("Nach Überlauf (a += 1): %d\n", a);
    printf("→ Der int-Wert 'wrappt' von INT_MAX zu INT_MIN.\n");

    return 0;
}