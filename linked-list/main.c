#include <stdio.h>
#include <stdlib.h>

/*
 *  Linked List — Core Idea:
 *
 *  A linked list is a sequence of nodes stored on the heap.
 *  Each node contains:
 *      - a value (the actual data)
 *      - a pointer to the next node in the list
 *
 *  The *head* pointer points to the first node.
 *  The *last* node points to NULL, marking the end.
 *
 *  Inserting at the top (add_head):
 *      - Allocate a new node.
 *      - Set its next pointer to the current head.
 *      - Update the head pointer to the new node.
 *
 *  Inserting at the end (add_tail):
 *      - Traverse the list until a node’s 'next' is NULL.
 *      - Create a new node, set its value, and make its 'next' NULL.
 *      - Link the last node’s 'next' to the new one.
 *      - If the list was empty, the new node *becomes* the head.
 *
 *  Deleting the head (delete_head):
 *      - Temporarily store the current head.
 *      - Move the head pointer to the next node.
 *      - Free the old head node.
 *
 *  Note on pointer-to-pointer:
 *      - In C, even pointers are passed by value.
 *        That means a function receives a *copy* of the pointer.
 *      - To modify the caller’s pointer (like the actual 'head' variable),
 *        we must pass its *address* (pointer-to-pointer).
 *
 *        Example:
 *            struct Node *head;
 *            add_head(&head, 10);
 *        Inside add_head():
 *            *old_head = new_node;  // directly changes 'head' in main
 */

struct Node {
    int value;           // Data stored in the node
    struct Node *next;   // Pointer to the next node (NULL if end)
};

/*
 *  print_nodes()
 *  Traverses the list and prints each node’s value and address.
 *  Useful for visualizing the structure and memory layout.
 */
void print_nodes(struct Node **head) {
    struct Node *tmp = *head;
    int i = 0;

    while (tmp != NULL) {
        printf("Node %d at address %p:\n", i, (void *)tmp);
        printf("  Value: %d\n", tmp->value);
        printf("  Next:  %p\n\n", (void *)tmp->next);
        tmp = tmp->next;
        i++;
    }

    if (i == 0)
        printf("[empty list]\n");
}

/*
 *  add_head()
 *  Creates a new node and inserts it at the start of the list.
 *  Requires a pointer-to-pointer so the function can change the head itself.
 */
void add_head(struct Node **old_head, int value) {
    struct Node *new_head = malloc(sizeof(struct Node));
    if (!new_head) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    new_head->value = value;
    new_head->next = *old_head;  // Link new node to the current head
    *old_head = new_head;        // Update the head pointer itself
}

/*
 *  delete_head()
 *  Removes the first node in the list and frees its memory.
 */
void delete_head(struct Node **old_head) {
    if (*old_head == NULL)
        return; // Nothing to delete

    struct Node *tmp = *old_head;   // Save current head
    *old_head = tmp->next;          // Move head to the next node
    free(tmp);                      // Free old head
}

/*
 *  add_tail()
 *  Adds a new node at the end of the list.
 *  If the list is empty, the new node becomes the head.
 */
void add_tail(struct Node **head, int value) {
    struct Node *new_tail = malloc(sizeof(struct Node));
    if (!new_tail) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }

    new_tail->value = value;
    new_tail->next = NULL; // Always terminate properly

    // If list is empty, this new node becomes the head
    if (*head == NULL) {
        *head = new_tail;
        return;
    }

    // Otherwise, find the last node
    struct Node *tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;

    // Link old tail to new tail
    tmp->next = new_tail;
}

/*
 *  main()
 *  Demonstrates linked list operations: create, add_head, delete_head, add_tail, print, cleanup.
 */
int main() {
    // Create initial head node
    struct Node *head = malloc(sizeof(struct Node));
    if (!head) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    head->value = 0;
    head->next = NULL;

    // Insert at head
    add_head(&head, 4);
    // Delete head
    delete_head(&head);
    // Append a few nodes
    add_tail(&head, 7);
    add_tail(&head, 6);
    add_tail(&head, 9);

    // Print all nodes
    print_nodes(&head);

    // Free all allocated memory
    struct Node *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    head = NULL; // Optional safety clear
    return 0;
}