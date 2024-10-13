#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void transverseLinkedList(const struct Node *head);
bool searchLinkedList(const struct Node *head, int target);
void add(struct Node *head, int data);
void deleteNode(struct Node **head, int target);
void reverse(struct Node **head);

int main(void) {
    struct Node* head =  malloc(sizeof(struct Node));
    struct Node* second = malloc(sizeof(struct Node));
    struct Node* third = malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;
    third->data = 30;
    third->next = NULL;

    add(head, 40);

    transverseLinkedList(head);
    deleteNode(&head, 30);
    transverseLinkedList(head);
    printf("%d\n", searchLinkedList(head, 30));

    reverse(&head);
    transverseLinkedList(head);

    // Freeing memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

void transverseLinkedList(const struct Node* head) {
    const struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

bool searchLinkedList(const struct Node* head, const int target) {
    while (head != NULL) {
        if (head->data == target) {
            return true;
        }
        head = head->next;
    }
    return false;
}

void add(struct Node* head, const int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void deleteNode(struct Node** headRef, const int target) {
    struct Node* temp = *headRef;
    struct Node* prev = NULL;


    if (temp != NULL && temp->data == target) {
        *headRef = temp->next;
        free(temp);
        return;
    }


    while (temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }

    // If the node wasn't found
    if (temp == NULL) {
        printf("Node with data %d not found.\n", target);
        return;
    }


    prev->next = temp->next;
    free(temp);
}

void reverse(struct Node** headRef) {
    struct Node* current = *headRef;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headRef = prev;
}
