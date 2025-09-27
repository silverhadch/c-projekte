# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

int main(){

    printf("Enter multiple numbers and finish with -1: \n");
    int input = 0;
    int* heapArray = malloc(1 * sizeof(int));
    if (heapArray == NULL){
        printf("Allocation failed, ending programm to prevent segfault.\n");
        return 1;
    }

    bool finished = false;
    int i = 0;
    while (!finished)
    {
        printf("Enter numbers or finish with -1: \n");
        scanf(" %d", &input);
        if (input == -1){
            finished = true;
            break;
        }
        heapArray[i] = input;
        i++;
        int* tmp = realloc(heapArray, (i + 1) * sizeof(int));
        if (tmp == NULL) {
            printf("Reallocation failed, ending program to prevent segfault.\n");
            free(heapArray); // free the old block to prevent leak
            return 1;
        }
        heapArray = tmp; // only assign if realloc succeeded
    }
    

    for (int j = 0; j < i; j++)
    {
        printf("Heap Array Value at Index %d: %d at addresse %p\n", j, heapArray[j], &heapArray[j]);
    }
    
    free(heapArray);
    heapArray = NULL;
    
    return 0;
}
