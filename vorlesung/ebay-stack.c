#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/** A single plate in the stack, holding a value and a pointer to the next */
struct Plate {
    int value;
    struct Plate *next;
};

/** Pushes a new value onto the top of the stack */
void push(struct Plate **rsp, int value){
    struct Plate *new = malloc(sizeof(struct Plate));
    if (!new) return;

    new->value = value;
    new->next = *rsp; // new goes on top
    *rsp = new;
}

/** Pops the top value from the stack */
void pop(struct Plate **rsp){
    if (*rsp == NULL) return;

    struct Plate *old = *rsp;
    *rsp = old->next;
    free(old);
}

/** Prints the value at the bottom (base pointer) of the stack */
void bottom(struct Plate **rsp){
    if (*rsp == NULL) {
        printf("Stack empty.\n");
        return;
    }

    struct Plate *tmp = *rsp;
    while (tmp->next) 
        tmp = tmp->next;
    
    printf("Value at the Register Base Pointer: %d\n", tmp->value);
}

/** Prints the value at the top (stack pointer) */
void top(struct Plate **rsp){
    if (*rsp == NULL) {
        printf("Stack empty.\n");
        return;
    }

    printf("Value at the Register Stack Pointer: %d\n", (*rsp)->value);
}

/** Returns true if the stack is empty */
bool isEmpty(struct Plate **rsp){
    return *rsp == NULL;
}

/** Returns the number of elements in the stack */
int size(struct Plate **rsp){
    struct Plate *tmp = *rsp;
    int i = 0;
    while (tmp) {
        i++;
        tmp = tmp->next;
    }
    return i;
}

int main(){
    struct Plate *rsp = NULL;  // top and base (for now)

    push(&rsp, 10);
    push(&rsp, 20);
    push(&rsp, 30);

    top(&rsp);
    bottom(&rsp);
    printf("Stack empty? %s\n", isEmpty(&rsp) ? "yes" : "no");
    printf("Stack size: %d\n", size(&rsp));

    pop(&rsp);
    top(&rsp);
    printf("Stack size: %d\n", size(&rsp));

    // Print and free
    struct Plate *tmp = rsp;
    while (tmp) {
        printf("%d\n", tmp->value);
        struct Plate *old = tmp;
        tmp = tmp->next;
        free(old);
    }

    rsp = NULL; // avoid dangling pointer

    return 0;
}