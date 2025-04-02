#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head;
struct Node* rearrange()
{
    struct Node *temp = head,*prev=NULL,*temp1;
    while (temp != NULL) {
        temp1=temp->next;
        prev=temp;
        while(temp1!= NULL){
        if (temp->data == temp1->data) {
            prev->next=temp1->next;
            free(temp1);
            temp1=prev->next;
        }
       else{ prev=temp1;
        temp1=temp1->next;
    }
}
        temp=temp->next;
}
}
void reoccur(int count) {
    struct Node *temp = head;
    struct Node *temp1;
    int i = 0, j;

    while (temp != NULL) {
        temp1 = temp->next;
        j = 0;
        while (temp1 != NULL) {
            if (temp->data == temp1->data) {
                j++;
            }
            temp1 = temp1->next;
        }
        if (j >= 0) {
            printf("The number %d has %d occurrences\n", temp->data, j + 1); // Include the current node
        }
        temp = temp->next;
    }
}

int main() {
    struct Node *temp, *nnode;
    head = NULL;
    int choice = 1, count = 0;

    while (choice) {
        nnode = (struct Node*) malloc(sizeof(struct Node));
        if (nnode == NULL) {
            printf("Memory not allocated\n");
            return -1;
        }
        printf("Enter the value: ");
        scanf("%d", &nnode->data);
        nnode->next = NULL;

        if (head == NULL) {
            head = nnode;
        } else {
            temp->next = nnode;
        }
        temp = nnode;

        printf("Do you want to continue (1 or 0): ");
        scanf("%d", &choice);
    }

    // Display the linked list
    temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\n");

    // Call reoccur function
    reoccur(count);
    rearrange();
    temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
    return 0;
}
