#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define true 1
#define false 0

struct Node {
    int data;
    struct Node *next;
};

void transverseLinkedList(struct Node *head);
bool searchLinkedList(struct Node *head, int target);

int main(void) {
   struct Node* head =  malloc(sizeof(struct Node));
    struct Node* second = malloc(sizeof(struct Node));
    struct Node* third = malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = nullptr;

    transverseLinkedList(head);
    printf("%d",searchLinkedList(head, 30));

    free(head);
    free(second);
    free(third);

    return 0;
}

void transverseLinkedList(struct Node* head){

    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

bool searchLinkedList(struct Node* head, int target) {
    while(head != NULL) {
        if(head->data == target) {
            return true;
        }
        head = head->next;
    }
        return false;
}