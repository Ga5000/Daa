#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}LinkedList;

int main(void) {
    LinkedList* head = (LinkedList *) malloc(sizeof(LinkedList));
    free(head);
}