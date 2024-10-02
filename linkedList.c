#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void transverseLinkedList(struct Node *head);

int main(void) {
   struct Node* head =  malloc(sizeof(struct Node));
    free(head);
}

void traverseLinkedList(struct Node* head){

    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}