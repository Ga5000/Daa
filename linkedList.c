#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define true 1
#define false 0

struct Node {
    int data;
    struct Node *next;
};

void transverseLinkedList(const struct Node *head);
bool searchLinkedList(const struct Node *head, int target);
void add(struct Node *head, int data);
void delete(struct Node *head, int target);

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
    add(head,40);

    transverseLinkedList(head);
    delete(head,30);
    transverseLinkedList(head);
    printf("%d",searchLinkedList(head, 30));

    free(head);
    free(second);
    free(third);

    return 0;
}

void transverseLinkedList(const struct Node* head){
    const struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

bool searchLinkedList(const struct Node* head, const int target) {
    while(head != NULL) {
        if(head->data == target) {
            return true;
        }
        head = head->next;
    }
        return false;
}

void add(struct Node* head, const int data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    if(newNode == NULL) {
        fprintf(stderr,"Memory allocation failed");
    }
    newNode->data = data;
    newNode->next = nullptr;
    if(head == NULL) {
        head = newNode;
    }else {
        struct Node* current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void delete(struct Node* head, const int target) {
    struct Node* temp = head;
    struct Node* prev = nullptr;
    while(temp != NULL && temp->data == target) {
        head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != target) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        fprintf(stderr,"Memory allocation failed");
    }
    prev->next = temp->next;
    free(temp);
}