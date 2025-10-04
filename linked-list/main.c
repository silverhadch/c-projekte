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

int main(){
    // Dont start on the stack lmao
    // struct Node head;
    // head.next = NULL;
    struct Node *head = malloc(sizeof(struct Node));
    head->value = 0;
    head->next = NULL;

    printf("Head node value: %d\n", head->value);

    free(head); // clean up
    head = NULL;

    return 0;
}