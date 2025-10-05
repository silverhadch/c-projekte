#include <stdio.h>
#include <stdlib.h>

/*
 *  Each Node contains a value and a pointer to the next node.
 *  The last node’s pointer is NULL.
 *
 *  The head node is explicitly known; the rest of the list can be
 *  traversed by following the next pointers.
 *
 *  Insertion at the top (prepend):
 *      - Create a new node.
 *      - Set its next pointer to the current head.
 *      - Make the head pointer point to the new node.
 *
 *  Insertion at the bottom (append):
 *      - Traverse the list until you find a node whose 'next' is NULL.
 *      - Allocate a new node, set its value, set its 'next' to NULL.
 *      - Link the last node’s 'next' to this new node.
 *
 *  Deletion logic (for later):
 *      - Top: move the head pointer one node forward, free the old head.
 *      - Middle: point the previous node’s 'next' to the deleted node’s 'next', then free the deleted node.
 *      - End: set the second-to-last node’s 'next' to NULL, free the last node.
 *
 *  Note on pointers:
 *      C passes everything by value — even pointers.
 *      So if we pass 'head' (which is a pointer) to a function, the function receives a *copy* of that pointer.
 *      If we want the function to change 'head' itself (e.g. make it point to a new node),
 *      we must pass the *address of the pointer* (a pointer-to-pointer).
 *
 *      That’s why add_head() takes 'struct Node **old_head' and not 'struct Node *old_head'.
 *      It allows the function to modify the caller’s pointer directly.
 */

struct Node {
    int value;           // The value stored in this node
    struct Node *next;   // Pointer to the next node (or NULL if end)
};

/*
 *  Add a new node at the head (start) of the list.
 *  Takes a pointer-to-pointer because we want to modify the caller’s head pointer.
 */
void add_head(struct Node **old_head, int value) {
    struct Node *new_head = malloc(sizeof(struct Node));
    if (!new_head) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    new_head->value = value;
    new_head->next = *old_head; // The new node points to the current head
    *old_head = new_head;       // Update the head pointer itself to the new node
}

int main() {
    // Create the first node (the initial head)
    struct Node *head = malloc(sizeof(struct Node));
    if (!head) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    head->value = 0;
    head->next = NULL;

    printf("Old head value: %d\n", head->value);

    // Insert a new head node with value 4
    // Passing '&head' gives the function the address of the head pointer,
    // allowing it to change where 'head' points.
    add_head(&head, 4);

    // Now 'head' points to the new node.
    // The new node points to the old one.
    printf("New head value: %d\n", head->value);
    printf("Next node value: %d\n", head->next->value);

    // Clean up: traverse and free all nodes
    struct Node *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    // Set to NULL for safety (optional)
    head = NULL;

    return 0;
}