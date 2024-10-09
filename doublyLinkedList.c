#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0


struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void transverseDoublyLinkedList(const struct Node* head);
bool searchDoublyLinkedList(const struct Node* head, int target);
void insertNode(struct Node** head, int data, int position);

int main(void) {
    struct Node* head = NULL;

    insertNode(&head, 10, 1); // insert at end
    insertNode(&head, 20, 1);
    insertNode(&head, 5, 0); // insert at start
    insertNode(&head, 30, 1);

    transverseDoublyLinkedList(head);
    printf("%d\n", searchDoublyLinkedList(head, 20));

    struct Node* current = head;
    while (current != NULL) {
        struct Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }

}

void insertNode(struct Node** head, int data, int position) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
    } else {
        if (*head == NULL) {
            *head = newNode;
        } else {
            struct Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
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
