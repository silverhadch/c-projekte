#include <stdio.h>
#include <stdlib.h>

/*
 * ─────────────────────────────────────────────────────────────
 * Singly Linked List Implementation
 * ─────────────────────────────────────────────────────────────
 *
 * Supports:
 *      - Adding, deleting, and modifying head and tail
 *      - Inserting, deleting, and modifying at arbitrary positions
 *      - Printing node structure with addresses
 */

struct Node {
    int value;
    struct Node *next;
};

/*──────────────────────────────────────────────────────────────
 * print_nodes()
 *──────────────────────────────────────────────────────────────
 * Prints all nodes, showing memory addresses to visualize links.
 * Helps debug pointer connections.
 *──────────────────────────────────────────────────────────────*/
void print_nodes(struct Node *head) {
    struct Node *tmp = head;
    int i = 0;

    while (tmp != NULL) {
        printf("Node %d at %p:\n", i, (void *)tmp);
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
 *──────────────────────────────────────────────────────────────
 * Adds a node to the beginning of the list.
 *
 * We use a pointer to pointer (Node **) because we might
 * need to update the head pointer in main() itself.
 *──────────────────────────────────────────────────────────────*/
void add_head(struct Node **head, int value) {
    // allocate memory for a new node
    struct Node *new_head = malloc(sizeof(struct Node));
    if (!new_head) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    // set its data
    new_head->value = value;

    // point new_head->next to the current head
    // this order is critical: we don't want to lose the existing list
    new_head->next = *head;

    // update the head pointer (since head changes, we need **head)
    *head = new_head;
}

/*──────────────────────────────────────────────────────────────
 * delete_head()
 *──────────────────────────────────────────────────────────────*/
void delete_head(struct Node **head) {
    if (*head == NULL)
        return;
        
    // store current head to free later
    struct Node *tmp = *head;

    // move head forward to the next node
    *head = tmp->next;

    // free old head
    free(tmp);
}

/*──────────────────────────────────────────────────────────────
 * modify_head()
 *──────────────────────────────────────────────────────────────*/
void modify_head(struct Node *head, int value) {
    if (head == NULL)
        return;

    // directly change value of the first node
    head->value = value;
}

/*──────────────────────────────────────────────────────────────
 * add_tail()
 *──────────────────────────────────────────────────────────────
 * Traverses to the end of the list and adds a node.
 *──────────────────────────────────────────────────────────────*/
void add_tail(struct Node **head, int value) {
    struct Node *new_tail = malloc(sizeof(struct Node));
    if (!new_tail) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    new_tail->value = value;
    new_tail->next = NULL;

    // if list is empty, new node becomes head
    if (*head == NULL) {
        *head = new_tail;
        return;
    }

    // otherwise traverse to the end
    struct Node *tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;

    // link last node’s next to the new one
    tmp->next = new_tail;
}

/*──────────────────────────────────────────────────────────────
 * delete_tail()
 *──────────────────────────────────────────────────────────────
 * Traverses to the second-to-last node and deletes the last.
 *──────────────────────────────────────────────────────────────*/
void delete_tail(struct Node **head) {
    if (*head == NULL)
        return;

    // if there's only one node, free it and clear the head
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // stop at the node just before the tail
    struct Node *tmp = *head;
    while (tmp->next->next != NULL)
        tmp = tmp->next;

    // now tmp->next is the tail
    free(tmp->next);
    tmp->next = NULL; // detach the freed node
}

/*──────────────────────────────────────────────────────────────
 * modify_tail()
 *──────────────────────────────────────────────────────────────*/
void modify_tail(struct Node *head, int value) {
    if (head == NULL)
        return;

    // traverse to the last node
    struct Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    // overwrite value
    tail->value = value;
}

/*──────────────────────────────────────────────────────────────
 * delete_node()
 *──────────────────────────────────────────────────────────────
 * Deletes a node at a given position (0-based index).
 *──────────────────────────────────────────────────────────────*/
void delete_node(struct Node **head, int position) {
    if (*head == NULL)
        return;

    // deleting first node is special — head changes
    if (position == 0) {
        delete_head(head);
        return;
    }

    struct Node *prev = *head;
    int i = 0;

    // move to node before the one we want to delete
    while (prev != NULL && i < position - 1) {
        prev = prev->next;
        i++;
    }

    // if we ran out of list — position out of bounds
    if (prev == NULL || prev->next == NULL)
        return;

    // link prev->next to skip the target node
    struct Node *to_delete = prev->next;
    prev->next = to_delete->next;

    // free the node safely (we no longer reference it)
    free(to_delete);
}

/*──────────────────────────────────────────────────────────────
 * add_node()
 *──────────────────────────────────────────────────────────────
 * Inserts a new node at a given position.
 *──────────────────────────────────────────────────────────────*/
void add_node(struct Node **head, int position, int value) {
    // inserting into an empty list
    if (*head == NULL) {
        if (position == 0)
            add_head(head, value);
        else
            fprintf(stderr, "Cannot insert beyond end in empty list.\n");
        return;
    }

    // inserting at head position
    if (position == 0) {
        add_head(head, value);
        return;
    }

    struct Node *prev = *head;
    int i = 0;

    // stop right before the insertion point
    while (prev->next != NULL && i < position - 1) {
        prev = prev->next;
        i++;
    }

    // if we reached end, append instead
    if (prev->next == NULL) {
        add_tail(head, value);
        return;
    }

    // allocate and set up new node
    struct Node *new_node = malloc(sizeof(struct Node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = value;

    // here is the core pointer logic:
    // step 1: connect new node to the next existing node
    new_node->next = prev->next;

    // step 2: link previous node to the new node
    prev->next = new_node;
}

/*──────────────────────────────────────────────────────────────
 * modify_node()
 *──────────────────────────────────────────────────────────────
 * Updates the value at a specific index.
 *──────────────────────────────────────────────────────────────*/
void modify_node(struct Node **head, int position, int value) {
    if (*head == NULL) {
        fprintf(stderr, "Cannot modify node in an empty list.\n");
        return;
    }

    // modifying head separately is easier
    if (position == 0) {
        modify_head(*head, value);
        return;
    }

    struct Node *tmp = *head;
    int i = 0;

    // move to desired node by index
    while (tmp->next != NULL && i < position) {
        tmp = tmp->next;
        i++;
    }

    // if position is beyond last node, modify last one instead
    if (tmp->next == NULL && i < position) {
        modify_tail(*head, value);
        return;
    }

    // reached correct position — update value
    tmp->value = value;
}

/*──────────────────────────────────────────────────────────────
 * main()
 *──────────────────────────────────────────────────────────────*/
int main(void) {
    struct Node *head = NULL;
    
    // Build list
    add_head(&head, 4);
    add_head(&head, 67);
    add_tail(&head, 7);
    add_tail(&head, 6);
    add_tail(&head, 9);

    printf("List after insertions:\n");
    print_nodes(head);

    // Modify endpoints
    modify_head(head, 100);
    modify_tail(head, 999);

    printf("After modifying head and tail:\n");
    print_nodes(head);

    // Delete head and tail
    delete_head(&head);
    delete_tail(&head);

    printf("After deleting head and tail:\n");
    print_nodes(head);

    // Delete node in the middle (position 1)
    printf("Deleting node at position 1:\n");
    delete_node(&head, 1);
    print_nodes(head);

    // Insert new node at position 1
    printf("Inserting new node (value 777) at position 1:\n");
    add_node(&head, 1, 777);
    print_nodes(head);

    // Modify node in the middle
    printf("Modifying node at position 1 (to 888):\n");
    modify_node(&head, 1, 888);
    print_nodes(head);

    // Delete out of range
    printf("Deleting node at out-of-range position 10:\n");
    delete_node(&head, 10);
    print_nodes(head);

    // Cleanup
    struct Node *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    head = NULL;
    return 0;
}
