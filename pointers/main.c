#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Programm gestartet!\n");

    printf("Bitte Anzahl eingeben: ");
    int anzahl = 0; // Variable 'anzahl' wird mit dem Wert 0 initialisiert
    int* pAnzahl = &anzahl; // 'pAnzahl' ist ein Pointer, der auf die Speicheradresse von 'anzahl' zeigt

    // Wir lesen die Eingabe direkt in die Speicherstelle von 'anzahl' ein.
    // Das bedeutet: scanf schreibt den Wert in die Adresse, die wir mit pAnzahl übergeben.
    if (scanf("%d", pAnzahl) != 1) {
        printf("Ungültige Eingabe! Programm wird beendet.\n");
        return 1;
    }

    printf("Adresse der Variable 'anzahl': %p\n", (void*)pAnzahl);
    printf("Wert der Variable 'anzahl': %d\n", anzahl);
    printf("Dereferenzierter Wert über pAnzahl (also *pAnzahl): %d\n", *pAnzahl);
    printf("Eingabe erfolgreich gelesen!\n");

    // Wir wollen dynamischen Arbeitsspeicher (Heap) vom Betriebssystem anfordern.
    // malloc fragt beim Linux Kernel nach Speicherblöcken, die NICHT im Stack liegen,
    // sondern im Heap – einem Bereich für dynamische Allokierung.
    printf("Versuche %d Ganzzahlen (int) auf dem Heap zu reservieren...\n", anzahl);
    int* werte = malloc(anzahl * sizeof(int));

    // Wir überprüfen, ob malloc fehlgeschlagen ist.
    // Falls ja, bekommen wir einen NULL-Pointer zurück.
    // Ein free(NULL) wäre ungefährlich, aber ein Zugriff auf NULL würde eine Speicherverletzung
    // (Segmentation Fault) auslösen → Linux Kernel beendet unser Programm mit SIGSEGV.
    if (werte == NULL) {
        printf("Speicherallokierung fehlgeschlagen!\n");
        printf("Breche ab, um Speicherverletzungen zu vermeiden!\n");
        return 1;
    }

    printf("Speicherallokierung erfolgreich!\n");
    printf("Adresse des allokierten Heaps: %p\n", (void*)werte);

    // Nun befüllen wir das Array im Heap.
    // Wir zählen nicht linear hoch, sondern speichern Vielfache von 10.
    printf("Befülle Array im Heap mit Werten...\n");
    for (int i = 0; i < anzahl; i++) {
        if (i == 0) {
            werte[i] = 10; // erster Wert wird explizit gesetzt
        } else {
            werte[i] = werte[i - 1] + 10; // alle folgenden sind +10 vom vorherigen
        }
    }

    // Wir geben alle gespeicherten Werte mit ihren Adressen aus.
    printf("Gebe alle gespeicherten Werte mit Adresse aus:\n");
    for (int i = 0; i < anzahl; i++) {
        printf("  -> Index %d | Adresse im Heap: %p | Wert: %d\n", i, &werte[i], werte[i]);
    }

    // Wenn wir malloc benutzt haben, müssen wir den Speicher wieder freigeben!
    // Andernfalls „vergessen“ wir den Speicherblock → Memory Leak.
    // Viele Leaks → Linux Kernel muss für unseren Prozess immer mehr Speicher reservieren.
    printf("Speicherfreigabe des Heap-Speichers...\n");
    free(werte);
    printf("Speicher erfolgreich freigegeben!\n");

    // Nach free zeigt unser Pointer 'werte' noch auf die alte Adresse,
    // ABER diese Adresse ist nun ungültig. Ein Zugriff wäre eine Speicherverletzung!
    // Darum setzen wir ihn explizit auf NULL → sicherer Programmierstil.
    pAnzahl = NULL; // auch wenn er hier nur auf eine Stack-Variable zeigte
    werte = NULL;

    printf("pAnzahl nach Freigabe/Reset: %p\n", (void*)pAnzahl);
    printf("werte nach Freigabe/Reset: %p\n", (void*)werte);

    printf("Programm beendet erfolgreich!\n");
    return 0;
}
