#include <stdio.h>
#include <stdlib.h>

/*
 * ─────────────────────────────────────────────────────────────
 * Linked List (Singly-Linked)
 * ─────────────────────────────────────────────────────────────
 *
 *  Concept:
 *      A linked list is a sequence of dynamically allocated nodes.
 *      Each node stores:
 *          • a data value
 *          • a pointer to the next node
 *
 *      The list starts at the *head* node, and each node points to
 *      the next. The final node points to NULL.
 *
 *  Why use pointers-to-pointers?
 *      In C, function arguments are passed by value — even pointers.
 *      To modify the caller’s pointer (like 'head'), you must pass
 *      its address. That’s why many functions take a `struct Node **`.
 *
 *      Example:
 *          struct Node *head = NULL;
 *          add_head(&head, 42);   // '&head' allows modifying 'head' itself
 *
 *  Operations implemented:
 *      - print_nodes()  : Print all nodes and their addresses.
 *      - add_head()     : Insert a node at the start.
 *      - delete_head()  : Remove the first node.
 *      - add_tail()     : Insert a node at the end.
 *      - delete_tail()  : Remove the last node.
 *
 *  This example focuses on correctness and clarity rather than performance.
 */

struct Node {
    int value;           // Data stored in this node
    struct Node *next;   // Pointer to the next node (NULL if end)
};

/*──────────────────────────────────────────────────────────────
 * print_nodes()
 * Prints all nodes in the list along with their memory addresses.
 * Useful for debugging and understanding how nodes are linked.
 *──────────────────────────────────────────────────────────────*/
void print_nodes(struct Node *head) {
    struct Node *tmp = head;
    int i = 0;

    while (tmp != NULL) {
        printf("Node %d at address %p:\n", i, (void *)tmp);
        printf("  Value: %d\n", tmp->value);
        printf("  Next:  %p\n\n", (void *)tmp->next);
        tmp = tmp->next;
        i++;
    }

    if (i == 0)
        printf("[empty list]\n\n");
}

/*──────────────────────────────────────────────────────────────
 * add_head()
 * Inserts a new node at the beginning of the list.
 *──────────────────────────────────────────────────────────────*/
void add_head(struct Node **head, int value) {
    struct Node *new_head = malloc(sizeof(struct Node));
    if (!new_head) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    new_head->value = value;
    new_head->next = *head;  // Link new node to current head
    *head = new_head;        // Update head pointer
}

/*──────────────────────────────────────────────────────────────
 * delete_head()
 * Removes the first node and updates the head pointer.
 *──────────────────────────────────────────────────────────────*/
void delete_head(struct Node **head) {
    if (*head == NULL)
        return; // List is empty, nothing to delete

    struct Node *tmp = *head;   // Store current head
    *head = tmp->next;          // Move head to next node
    free(tmp);                  // Free old head
}

/*──────────────────────────────────────────────────────────────
 * add_tail()
 * Appends a new node at the end of the list.
 * If the list is empty, the new node becomes the head.
 *──────────────────────────────────────────────────────────────*/
void add_tail(struct Node **head, int value) {
    struct Node *new_tail = malloc(sizeof(struct Node));
    if (!new_tail) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    new_tail->value = value;
    new_tail->next = NULL; // End of list

    if (*head == NULL) {
        // Empty list: new node becomes head
        *head = new_tail;
        return;
    }

    // Traverse to last node
    struct Node *tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = new_tail; // Link the old tail to new tail
}

/*──────────────────────────────────────────────────────────────
 * delete_tail()
 * Deletes the last node in the list.
 * Handles both single-node and multi-node cases.
 *──────────────────────────────────────────────────────────────*/
void delete_tail(struct Node **head) {
    if (*head == NULL)
        return; // Empty list

    // If there's only one node
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Traverse to the second-to-last node
    struct Node *tmp = *head;
    while (tmp->next->next != NULL)
        tmp = tmp->next;

    // tmp now points to second-to-last
    struct Node *to_delete = tmp->next;
    tmp->next = NULL;  // Update new tail
    free(to_delete);   // Free old tail
}

/*──────────────────────────────────────────────────────────────
 * main()
 * Demonstrates basic linked list operations.
 *──────────────────────────────────────────────────────────────*/
int main(void) {
    struct Node *head = NULL; // Start with an empty list

    // Build a list step-by-step
    add_head(&head, 4);
    add_head(&head, 67);
    add_tail(&head, 7);
    add_tail(&head, 6);
    add_tail(&head, 9);

    printf("List after insertions:\n");
    print_nodes(head);

    // Delete operations
    delete_head(&head);
    delete_tail(&head);

    printf("List after deleting head and tail:\n");
    print_nodes(head);

    // Cleanup all nodes
    struct Node *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    head = NULL;
    return 0;
}