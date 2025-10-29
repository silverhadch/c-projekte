# include "stdio.h"
# include "stdbool.h"

bool check_schaltjahr(int* jahr) {
    if ((*jahr % 4 == 0) && ((*jahr % 100 != 0) || (*jahr % 400 == 0))) {
        return true;
    }

    return false;
}

int main(void) {
    printf("Gebe ein Jahr ein: ");
    int jahr;
    scanf(" %d", &jahr);

    bool schaltjahr = check_schaltjahr(&jahr);

    printf("%d ist ein Schaltjahr: %s\n", jahr, schaltjahr ? "true" : "false");
    return 0;
}