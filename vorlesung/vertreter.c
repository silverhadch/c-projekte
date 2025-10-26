#include <stdio.h>
#include <stdbool.h>

bool check(int* kunden, int* vertrag_anzahl, int* vertrag_gesamtwert){
    printf("Wie viele Kunden hattest du?\n");
    scanf(" %d", kunden);

    printf("Wie viele Verträge hattest du?\n");
    scanf(" %d", vertrag_anzahl);

    printf("Wie viel ist der Gesamtwert der Verträge?\n");
    scanf(" %d", vertrag_gesamtwert);

    if (*kunden > 2) {
        if ((*vertrag_anzahl >= 10 && *vertrag_gesamtwert >= 50000) || (*vertrag_gesamtwert >= 100000)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main(){
    int kunden;
    int vertrag_anzahl;
    int vertrag_gesamtwert;
    bool bonus  = check(&kunden, &vertrag_anzahl, &vertrag_gesamtwert);
    if (bonus)
        printf("Du bekommst den Bonus!\n");
    return 0;
}
