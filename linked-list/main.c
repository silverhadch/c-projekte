# include "stdio.h"
# include "stdlib.h"

/*  Node should contain a value and the pointer to the next node if we are at the bottom the pointer becomes null
*   the Head Node will be explicitly know as the rest can be found by going to pointer to pointer 
*   We need to allow inserts at the top so we duplicate head and then ceate a new one that points to the old head,
*   inserts at the bottom are just finding the pointer that points to null and set it to the pointer of the new node value and set the new nodes pointer to null
*   deleting in the middle is just copying the next pointer of the deleted node to the prevoius node then free the delted node, 
*   at the top we simply make the head move one node and clean up the old head and deleting the end is just making the previous to the end node point to null and free the old end
*   we also need a way to do this interactivly but that comes later.
*/

struct Node {   // Structure declaration
  int value;           // Value in Node
  struct Node *next;   // Point to next Node
};

// we assign the new node the next pointer to the current head then we make the old_head point to the new one so in main the pointer chnages too
void add_head(struct Node **old_head, int value) {
  struct Node *new_head = malloc(sizeof(struct Node));
  new_head->value = value;
  new_head->next = *old_head;
  *old_head = new_head;
}

int main(){
    // The Node is a pointer
    struct Node *head = malloc(sizeof(struct Node));
    head->value = 0;
    head->next = NULL;
    // To pass the pointer by refrence make a pointer to the pointer 
    struct Node **pHead = &head;

    printf("Head node value: %d\n", head->value);

    // we pass by reference the head node pointer via the pHead pointer to a pointer since even pointers get copied by value in C
    add_head(pHead, 4);

    printf("Head node value: %d\n", head->value);

    struct Node *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    head = NULL;
    pHead = NULL;

    return 0;
}