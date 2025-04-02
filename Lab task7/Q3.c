#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to delete a node at the beginning of the doubly linked list
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->prev = NULL;
    }

    free(temp);
    printf("Node at the beginning deleted.\n");
}

// Function to delete a node at the end of the doubly linked list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    // If there is only one node
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        printf("Node at the end deleted.\n");
        return;
    }

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Now, temp points to the last node
    temp->prev->next = NULL;
    free(temp);
    printf("Node at the end deleted.\n");
}

// Function to delete a node at a specific index in the doubly linked list
void deleteAtIndex(struct Node** head, int index) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;
    int count = 0;

    // Traverse the list to find the node at the given index
    while (temp != NULL && count < index) {
        temp = temp->next;
        count++;
    }

    // If index is out of range
    if (temp == NULL) {
        printf("Index out of range.\n");
        return;
    }

    // If deleting the first node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next; // Move the head if the node is the first node
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node at index %d deleted.\n", index);
}

// Function to print the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the implementation
int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->prev = head;
    head->next->next = createNode(30);
    head->next->next->prev = head->next;

    printf("Original List: ");
    printList(head);

    deleteAtBeginning(&head);
    printf("After deletion at the beginning: ");
    printList(head);

    deleteAtEnd(&head);
    printf("After deletion at the end: ");
    printList(head);

    deleteAtIndex(&head, 0);
    printf("After deletion at index 0: ");
    printList(head);

    return 0;
}
