#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head;
struct Node* reverse()
{
    struct Node *curr=head,*next,*prev=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
int main()
{
  struct Node *temp,*nnode;
  head=NULL;
  int choice=1;
  while(choice)
  {
    nnode=(struct Node*)malloc(sizeof(struct Node));
    if(nnode==NULL)
    {
        printf("The memory not alloted");
        return -1;
    }
    printf("Enter the value\n");
    scanf("%d", &nnode->data);
    nnode->next=NULL;
    if(head==NULL)
    {
        temp=nnode;
        head=nnode;
    }
    else
    {
        temp->next=nnode;
        temp=nnode;
    }
    printf("Do you want to continue(1 or 0)\n");
    scanf("%d", &choice);
  }
  temp=head;
  printf("Linked List:\n");
  while(temp!=NULL)
  {
    printf("%d ", temp->data);
    temp=temp->next;
  }
  printf("\n");
  head=reverse();
  printf("Reverse Linked List:\n");
  temp=head;
  while(temp!=NULL)
  {
    printf("%d ", temp->data);
    temp=temp->next;
  }
  return 0;
}
