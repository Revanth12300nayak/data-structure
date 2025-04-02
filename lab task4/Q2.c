#include <stdio.h>
#include <stdlib.h>
 struct Node { int data; struct Node* next; };

 void insertAtBeginning(struct Node** head, int newData)
{ struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); newNode->data = newData; newNode->next = *head; *head = newNode; }

void insertAtEnd(struct Node** head, int newData)
{ struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); newNode->data = newData; newNode->next = NULL;

if (*head == NULL) {
    *head = newNode;
    return;
}

struct Node* temp = *head;
while (temp->next != NULL) {
    temp = temp->next;
}
temp->next = newNode;

}
void insertAtPosition(struct Node** head, int newData, int position)
{ struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); newNode->data = newData;

if (position == 1) {
    newNode->next = *head;
    *head = newNode;
    return;
}

struct Node* temp = *head;
for (int i = 1; temp != NULL && i < position - 1; i++) {
    temp = temp->next;
}

if (temp == NULL) {
    printf("Position out of bounds!\n");
    free(newNode);
    return;
}

newNode->next = temp->next;
temp->next = newNode;

}
 void printList(struct Node* head)
{ struct Node* temp = head; while (temp != NULL) { printf("%d -> ", temp->data); temp = temp->next; } printf("NULL\n"); }

 int main() { struct Node* head = NULL;

insertAtBeginning(&head, 10);
insertAtEnd(&head, 20);
insertAtEnd(&head, 30);
insertAtPosition(&head, 25, 3);
insertAtBeginning(&head, 5);
insertAtPosition(&head, 15, 3);

printList(head);

return 0;

}
