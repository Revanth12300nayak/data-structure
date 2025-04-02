#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *back;
};

struct Node *head = NULL;

void display() {
    struct Node *temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertfir() {
    struct Node *nnode;
    nnode = (struct Node*)malloc(sizeof(struct Node));
    if(nnode == NULL) {
        printf("Memory not allocated\n");
        return;
    }
    nnode->next = head;
    nnode->back = NULL;
    printf("Enter the value: ");
    scanf("%d", &nnode->data);
    
    if (head != NULL) {
        head->back = nnode;
    }
    head = nnode;
    display();
}

void insertend() {
    struct Node *nnode, *temp = head;
    nnode = (struct Node*)malloc(sizeof(struct Node));
    if(nnode == NULL) {
        printf("Memory not allocated\n");
        return;
    }
    nnode->next = NULL;

    while(temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }

    if (temp == NULL) {
        head = nnode;
    } else {
        temp->next = nnode;
        nnode->back = temp;
    }
    display();
}

void insertind() {
    struct Node *nnode, *temp = head;
    int pos;
    nnode = (struct Node*)malloc(sizeof(struct Node));
    if(nnode == NULL) {
        printf("Memory not allocated\n");
        return;
    }
    printf("Enter the position to be inserted: ");
    scanf("%d", &pos);
    printf("Enter the value: ");
    scanf("%d", &nnode->data);

    if (pos == 1) {
        nnode->next = head;
        nnode->back = NULL;
        if (head != NULL) {
            head->back = nnode;
        }
        head = nnode;
        display();
        return;
    }

    for(int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(nnode);
        return;
    }

    nnode->next = temp->next;
    nnode->back = temp;
    if (temp->next != NULL) {
        temp->next->back = nnode;
    }
    temp->next = nnode;
    display();
}

int main() {
    struct Node *nnode, *temp;
    int c = 1;

    while(c) {
        nnode = (struct Node*)malloc(sizeof(struct Node));
        if(nnode == NULL) {
            printf("Memory not allocated\n");
            return -1;
        }
        nnode->next = NULL;
        nnode->back = NULL;
        printf("Enter the value: ");
        scanf("%d", &nnode->data);
        
        if(head == NULL) {
            head = nnode;
            temp = nnode;
        } else {
            temp->next = nnode;
            nnode->back = temp;
            temp = nnode;
        }
        
        printf("If you want to continue, enter 1 or 0: ");
        scanf("%d", &c);
    }

    display();
    printf("\n");
    insertfir();
    printf("\n");
    insertend();
    printf("\n");
    insertind();
    
    return 0;
}
