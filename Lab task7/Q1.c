#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void create_list(int n) {
    struct node *newnode, *temp;
    int val;
    
    for (int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &val);
        
        newnode->data = val;
        
        if (head == NULL) {
            head = newnode;
            newnode->next = head;
        } else {
            temp = head;
            while (temp->next != head) 
                temp = temp->next;
            temp->next = newnode;
            newnode->next = head;
        }
    }
}

void insert_beg(int val) {
    struct node newnode = (struct node)malloc(sizeof(struct node));
    newnode->data = val;
    
    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != head) 
            temp = temp->next;
        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
}

void insert_end(int val) {
    struct node newnode = (struct node)malloc(sizeof(struct node));
    newnode->data = val;
    
    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != head) 
            temp = temp->next;
        temp->next = newnode;
        newnode->next = head;
    }
}

void insert_pos(int val, int pos) {
    struct node newnode = (struct node)malloc(sizeof(struct node));
    newnode->data = val;
    
    if (pos == 1) {
        insert_beg(val);
        return;
    }
    
    struct node *temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;
    
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_beg() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node *temp = head, *last = head;
    
    while (last->next != head) 
        last = last->next;
    
    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        head = head->next;
        last->next = head;
        free(temp);
    }
}

void delete_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node *temp = head, *prev = NULL;
    
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    
    if (prev == NULL) {
        free(head);
        head = NULL;
    } else {
        prev->next = head;
        free(temp);
    }
}

void delete_pos(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    if (pos == 1) {
        delete_beg();
        return;
    }
    
    struct node *temp = head, *prev = NULL;
    int i;
    
    for (i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }
    
    if (i != pos) {
        printf("Invalid position\n");
        return;
    }
    
    prev->next = temp->next;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    struct node *temp = head;
    
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("\n");
}

int main() {
    int n, choice, val, pos;

    printf("Enter the number of initial nodes: ");
    scanf("%d", &n);
    
    if (n > 0) {
        create_list(n);
        printf("Initial Circular Linked List: ");
        display();
    } else {
        printf("Empty list created\n");
    }
    
    while (1) {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n4.Delete at Beginning\n5.Delete at End\n6.Delete at Position\n7.Display\n8.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); insert_beg(val); break;
            case 2: printf("Enter value: "); scanf("%d", &val); insert_end(val); break;
            case 3: printf("Enter value and position: "); scanf("%d %d", &val, &pos); insert_pos(val, pos); break;
            case 4: delete_beg(); break;
            case 5: delete_end(); break;
            case 6: printf("Enter position: "); scanf("%d", &pos); delete_pos(pos); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
