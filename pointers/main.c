# include <stdio.h>
# include <stdlib.h>

int main(){
    printf("Gebe Anzahl an: ");
    int anzahl = 0; // Variable anzahl mit Wert 0
    int* pAnzahl = &anzahl; // Zeigt zur Addresse von anzahl
    scanf("%d", pAnzahl); // Schreibe zum Wert in der angegebenen Adresse den stdio
    printf("Wert von der Variable anzahl: %d\n", anzahl);
    printf("Dereferenzierter Wert des pAnzahl Pointer: %d\n", *pAnzahl); // der Zeiger zur Speicheraddresse des Wertes wird aufgelöst in den Wert 
    printf("Die Speicheraddresse der Variable anzahl: %p\n", pAnzahl);

    // Wir möchten um Arbeitsspeicher zu schonen, den Linux Kernel nach einem Heap fragen (dynamischer Arbeitsspeicherabschnitt vom Betriebssystem)
    int* werte = malloc(anzahl * sizeof(int));

    // Wir checken ob der Pointer zu einer nicht validen Addresse zeigt, da sonst der free eine Arbeitsspeicherverletzung begehen und der Kernel wird sauer!
    if (werte == NULL){
        printf("Allokierung von dynamischen Arbeitsspeicher (Heap) vom Linux Kernel fehlgeschlagen!\n");
        printf("Breche ab um Speicherverletzung zuverhindern!\n");
        return 1; // Beende das Programm mit Exit Code 1
    }

    // Zählen wir einfach in Zähner Schritten von Null bis Anzahl
    for (int i = 0; i < anzahl; i++)
    {
        if (i == 0){
            werte[i] = 10;
        } else {
            werte[i] = werte[i - 1] + 10;
        }
        printf("Wert von werte im Heap am Index %d: %d\n", i, werte[i]);
    }

    // Vernichte den Heap nach Nutzung um kein Memory Leak zu verursachen sonst wird der Kernel sauer!
    free(werte);
    
    // Vernichte den Zeiger um Arbeitsspeicherverletzungen zu verhindern
    // Wir fragen den Linux Kernel nach Arbeitsspeicher über malloc, kriegen wir 
    // Arbeitsspeicher geliehen vom Betriebssystem (Heap) und der Pointer würde nach dem freigeben des Heaps im Arbeitsspeicher
    // des Betriebssystem rum hängen, was A. unsicher ist und B. eine Arbeitsspeicherverletzung ist und der Kernel wird sauer!
    pAnzahl = NULL;

    printf("Wert des pAnzahl Pointer nach seiner Vernichtung: %p\n", pAnzahl);
    return 0;
}