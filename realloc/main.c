# include <stdio.h>
# include <stdlib.h>

int main(){
    int anzahl = 0;
    int* pAnzahl = &anzahl; // Pointer pAnzahl zeigt auf die Adresse von anzahl im Stack
    printf("Geben Sie eine Zahl ein: ");
    scanf("%d", pAnzahl);
    printf("Wert von anzahl über dereferenzierten Pointer: %d\n", *pAnzahl);

    int size = anzahl * sizeof(int);
    int* heapArray = malloc(size); // Speicher für ein Array von 'anzahl' Integers im Heap reservieren also ist heapArray der Pointer zu diesem Heap Stück
    if (heapArray == NULL) {
        fprintf(stderr, "Speicherreservierung fehlgeschlagen\n");
        return 1;
    }

    printf("Allokierte %d Bytes an Addresse %p im Heap.\n", size, heapArray);

    for (int i = 0; i < anzahl; i++) {
        heapArray[i] = i * i;
        printf("Heap Array Wert am Index %d: %d | Addresse dieses Wertes: %p\n", i, heapArray[i], &heapArray[i]);
    }

    int neueAnzahl = 2 * anzahl;
    int newsize = neueAnzahl * sizeof(int);
    int* neuesHeapArray = realloc(heapArray, newsize);
    printf("Reallokiere %d Bytes an Addresse %p im Heap.\n", newsize, neuesHeapArray);

    for (int i = anzahl; i < neueAnzahl; i++) {
        neuesHeapArray[i] = i * i;
        printf("Heap Array Wert am Index %d: %d | Addresse dieses Wertes: %p\n", i, neuesHeapArray[i], &neuesHeapArray[i]);
    }

    printf("Befreie den Heap.\n");
    free(neuesHeapArray);
    neuesHeapArray = NULL;
    printf("Speicheraddresse von neuesHeapArray nach Befreiung und vernichten des dangling Pointers: %p\n", neuesHeapArray);

    return 0;
}