#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void transverseDoublyLinkedList(const struct Node *head);
bool searchDoublyLinkedList(const struct Node *head, int target);

int main(void) {
    struct Node* head = malloc(sizeof(struct Node));
    struct Node* second = malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;
    head->prev = NULL;

    second->data = 20;
    second->next = NULL;
    second->prev = head;

    transverseDoublyLinkedList(head);
     printf("%d", searchDoublyLinkedList(head, 20));

    free(second);
    free(head);

    return 0;
}

void transverseDoublyLinkedList(const struct Node* head) {
    const struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

bool searchDoublyLinkedList(const struct Node* head, int target) {
    const struct Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            return true;
        }
        current = current->next;
    }
    return false;
}
