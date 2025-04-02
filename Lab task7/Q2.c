#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *back;
};
struct Node *head=NULL;
void main()
{
   struct Node *nnode,*temp;
    int c=1;
    while(c)
    {
        nnode=(struct Node*)malloc(sizeof(struct Node));
        if(nnode==NULL)
        {
            printf("Memory not alloted");
            return -1;
        }
        nnode->next=NULL;
        nnode->back=NULL;
        printf("Enter the value: ");
        scanf("%d", &nnode->data);
        if(head==NULL)
        {
            head=nnode;
            temp=nnode;
        }
        else
        {
            temp->next=nnode;
            temp->next->back=temp;
            temp=nnode;
        }
        printf("If you want to continue so enter 1 or 0");
        scanf("%d", &c);
    }
    temp=head;
    while(temp!=0)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
}
