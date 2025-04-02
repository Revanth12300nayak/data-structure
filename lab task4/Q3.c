#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

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

struct Node* concatenateLists(struct Node* head1, struct Node* head2) { if (head1 == NULL) return head2; if (head2 == NULL) return head1;

struct Node* temp = head1;
while (temp->next != NULL) {
    temp = temp->next;
}
temp->next = head2;
return head1;

}

 void printList(struct Node* head) { struct Node* temp = head; while (temp != NULL) { printf("%d -> ", temp->data); temp = temp->next; } printf("NULL\n"); }

 int main() { struct Node* head1 = NULL; struct Node* head2 = NULL;

insertAtEnd(&head1, 1);
insertAtEnd(&head1, 2);
insertAtEnd(&head1, 3);

insertAtEnd(&head2, 4);
insertAtEnd(&head2, 5);
insertAtEnd(&head2, 6);

printf("First Linked List: ");
printList(head1);

printf("Second Linked List: ");
printList(head2);

struct Node* head3 = concatenateLists(head1, head2);

printf("Concatenated Linked List: ");
printList(head3);

return 0;

}
