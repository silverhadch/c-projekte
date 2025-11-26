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
 *──────────────────────────────────────────────────────────────*/
 
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
 *──────────────────────────────────────────────────────────────*/
void add_head(struct Node **head, int value) {
    struct Node *new_head = malloc(sizeof(struct Node));
    if (!new_head) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    new_head->value = value;
    new_head->next = *head;
    *head = new_head;
}

/*──────────────────────────────────────────────────────────────
 * delete_head()
 *──────────────────────────────────────────────────────────────*/
void delete_head(struct Node **head) {
    if (*head == NULL)
        return;
        
    struct Node *tmp = *head;
    *head = tmp->next;
    free(tmp);
}

/*──────────────────────────────────────────────────────────────
 * modify_head()
 *──────────────────────────────────────────────────────────────*/
void modify_head(struct Node *head, int value) {
    if (head == NULL)
        return;
    head->value = value;
}

/*──────────────────────────────────────────────────────────────
 * add_tail()
 *──────────────────────────────────────────────────────────────*/
void add_tail(struct Node **head, int value) {
    struct Node *new_tail = malloc(sizeof(struct Node));
    if (!new_tail) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    new_tail->value = value;
    new_tail->next = NULL;

    if (*head == NULL) {
        *head = new_tail;
        return;
    }

    struct Node *tmp = *head;
    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = new_tail;
}

/*──────────────────────────────────────────────────────────────
 * delete_tail()
 *──────────────────────────────────────────────────────────────*/
void delete_tail(struct Node **head) {
    if (*head == NULL)
        return;

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *tmp = *head;
    while (tmp->next->next != NULL)
        tmp = tmp->next;

    free(tmp->next);
    tmp->next = NULL;
}

/*──────────────────────────────────────────────────────────────
 * modify_tail()
 *──────────────────────────────────────────────────────────────*/
void modify_tail(struct Node *head, int value) {
    if (head == NULL)
        return;

    struct Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    tail->value = value;
}

/*──────────────────────────────────────────────────────────────
 * delete_node()
 *──────────────────────────────────────────────────────────────*/
void delete_node(struct Node **head, int position) {
    if (*head == NULL)
        return;

    if (position == 0) {
        delete_head(head);
        return;
    }

    struct Node *prev = *head;
    int i = 0;

    while (prev != NULL && i < position - 1) {
        prev = prev->next;
        i++;
    }

    if (prev == NULL || prev->next == NULL)
        return;

    struct Node *to_delete = prev->next;
    prev->next = to_delete->next;
    free(to_delete);
}

/*──────────────────────────────────────────────────────────────
 * add_node()
 *──────────────────────────────────────────────────────────────*/
void add_node(struct Node **head, int position, int value) {
    if (*head == NULL) {
        if (position == 0)
            add_head(head, value);
        else
            fprintf(stderr, "Cannot insert beyond end in empty list.\n");
        return;
    }

    if (position == 0) {
        add_head(head, value);
        return;
    }

    struct Node *prev = *head;
    int i = 0;

    while (prev->next != NULL && i < position - 1) {
        prev = prev->next;
        i++;
    }

    if (prev->next == NULL) {
        add_tail(head, value);
        return;
    }

    struct Node *new_node = malloc(sizeof(struct Node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    new_node->value = value;
    new_node->next = prev->next;
    prev->next = new_node;
}

/*──────────────────────────────────────────────────────────────
 * modify_node()
 *──────────────────────────────────────────────────────────────*/
void modify_node(struct Node **head, int position, int value) {
    if (*head == NULL) {
        fprintf(stderr, "Cannot modify node in an empty list.\n");
        return;
    }

    if (position == 0) {
        modify_head(*head, value);
        return;
    }

    struct Node *tmp = *head;
    int i = 0;

    while (tmp->next != NULL && i < position) {
        tmp = tmp->next;
        i++;
    }

    if (tmp->next == NULL && i < position) {
        modify_tail(*head, value);
        return;
    }

    tmp->value = value;
}

/*──────────────────────────────────────────────────────────────
 * main()
 *──────────────────────────────────────────────────────────────*/
int main(void) {
    struct Node *head = NULL;
    
    add_head(&head, 4);
    add_head(&head, 67);
    add_tail(&head, 7);
    add_tail(&head, 6);
    add_tail(&head, 9);

    printf("List after insertions:\n");
    print_nodes(head);

    modify_head(head, 100);
    modify_tail(head, 999);

    printf("After modifying head and tail:\n");
    print_nodes(head);

    delete_head(&head);
    delete_tail(&head);

    printf("After deleting head and tail:\n");
    print_nodes(head);

    printf("Deleting node at position 1:\n");
    delete_node(&head, 1);
    print_nodes(head);

    printf("Inserting new node (value 777) at position 1:\n");
    add_node(&head, 1, 777);
    print_nodes(head);

    printf("Modifying node at position 1 (to 888):\n");
    modify_node(&head, 1, 888);
    print_nodes(head);

    printf("Deleting node at out-of-range position 10:\n");
    delete_node(&head, 10);
    print_nodes(head);

    struct Node *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}
