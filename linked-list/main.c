#include <stdio.h>
#include <stdlib.h>

/*
 * ─────────────────────────────────────────────────────────────
 * Linked List (Singly-Linked)
 * ─────────────────────────────────────────────────────────────
 *
 *  Basic linked list that supports:
 *      - Add / delete / modify head and tail
 *      - Print all nodes
 *
 *  Next steps: implement insert/delete/modify in the middle.
 */

struct Node {
    int value;
    struct Node *next;
};

/*──────────────────────────────────────────────────────────────
 * print_nodes()
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
 *──────────────────────────────────────────────────────────────
 * Finds the last node and modifies its value.
 *──────────────────────────────────────────────────────────────*/
void modify_tail(struct Node *head, int value) {
    if (head == NULL)
        return;

    struct Node *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->value = value;
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

    modify_head(head, 100);
    modify_tail(head, 999);

    printf("After modifying head and tail:\n");
    print_nodes(head);

    delete_head(&head);
    delete_tail(&head);

    printf("After deleting head and tail:\n");
    print_nodes(head);

    // Cleanup
    struct Node *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}