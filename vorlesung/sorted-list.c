#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

/** A single Node holding a value and a pointer to the next */
struct Node {
    int value;
    struct Node *next;
};

/** Returns true if the List is empty */
bool isEmpty(struct Node **head){
    return *head == NULL;
}

/** Returns the number of elements in the List */
int size(struct Node **head){
    struct Node *tmp = *head;
    int i = 0;
    while (tmp) {
        i++;
        tmp = tmp->next;
    }
    return i;
}

/** Inserts a value into the list while keeping it sorted (ascending) */
void add(struct Node **head, int value){
    // Empty list: new head
    if (*head == NULL) {
        struct Node *new_head = malloc(sizeof(struct Node));
        if (!new_head) {
            printf("Memory Allocation failed!\n");
            return;
        }
        new_head->value = value;
        new_head->next = NULL;
        *head = new_head;
        return;
    }

    // Insert at front
    if (value <= (*head)->value) {
        struct Node *new_node = malloc(sizeof(struct Node));
        if (!new_node) {
            printf("Memory Allocation failed!\n");
            return;
        }
        new_node->value = value;
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Insert in middle or end
    struct Node *tmp = *head;

    while (tmp->next != NULL && tmp->next->value < value) {
        tmp = tmp->next;
    }

    struct Node *new_node = malloc(sizeof(struct Node));
    if (!new_node) {
        printf("Memory Allocation failed!\n");
        return;
    }

    new_node->value = value;
    new_node->next = tmp->next;
    tmp->next = new_node;
}

/** Returns the value at a given list position (0-indexed) */
int get(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty!\n");
        exit(EXIT_FAILURE);
    }

    if (position < 0) {
        printf("Invalid position!\n");
        exit(EXIT_FAILURE);
    }

    struct Node *tmp = *head;
    int i = 0;

    while (tmp != NULL && i < position) {
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL) {
        printf("Position out of bounds!\n");
        exit(EXIT_FAILURE);
    }

    return tmp->value;
}

/** Removes the node at the given list position (0-indexed) and returns its value */
int remove_node(struct Node **head, int position) {
    if (*head == NULL)
        exit(EXIT_FAILURE);

    if (position < 0)
        exit(EXIT_FAILURE);

    // Delete head
    if (position == 0) {
        struct Node *tmp = *head;
        int deleted = tmp->value;
        *head = tmp->next;
        free(tmp);
        return deleted;
    }

    struct Node *prev = *head;
    int i = 0;

    while (prev != NULL && i < position - 1) {
        prev = prev->next;
        i++;
    }

    if (prev == NULL || prev->next == NULL)
        exit(EXIT_FAILURE);

    struct Node *to_delete = prev->next;
    prev->next = to_delete->next;
    int deleted = to_delete->value;
    free(to_delete);
    return deleted;
}

int main() {
    struct Node *head = NULL;

    srand(time(NULL));

    // Insert 1000 random values
    for (int i = 0; i < 1000; i++) {
        int r = rand() % 10000;  // random 0–9999
        add(&head, r);
    }

    // Print size
    printf("List size: %d\n", size(&head));

    // Print all elements
    struct Node *tmp = head;
    while (tmp) {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }

    // Free all nodes
    tmp = head;
    while (tmp) {
        struct Node *old = tmp;
        tmp = tmp->next;
        free(old);
    }

    head = NULL;

    return 0;
}