#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createLinkedList(int n) {
    if (n <= 0) return NULL;

    int data;
    printf("Enter data for node 1: ");
    scanf("%d", &data);

    Node* head = createNode(data);
    Node* temp = head;

    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        temp->next = createNode(data);
        temp = temp->next;
    }
    return head;
}

void displayLinkedList(Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }
    
    printf("Linked List: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    Node* head = createLinkedList(n);
    displayLinkedList(head);

    return 0;
}
