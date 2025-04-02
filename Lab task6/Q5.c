#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head,*head1;
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
  printf("Linked List 1:\n");
  while(temp!=NULL)
  {
    printf("%d ", temp->data);
    temp=temp->next;
  }
  printf("\n");
  struct Node *temp1,*nnode1;
  head1=NULL;
  choice=1;
  while(choice)
  {
    nnode1=(struct Node*)malloc(sizeof(struct Node));
    if(nnode1==NULL)
    {
        printf("The memory not alloted");
        return -1;
    }
    printf("Enter the value\n");
    scanf("%d", &nnode1->data);
    nnode1->next=NULL;
    if(head1==NULL)
    {
        temp1=nnode;
        head1=nnode;
    }
    else
    {
        temp1->next=nnode;
        temp1=nnode;
    }
    printf("Do you want to continue(1 or 0)\n");
    scanf("%d", &choice);
  }
  printf("\n");
  temp1=head1;
  printf("Linked List 1:\n");
  while(temp1!=NULL)
  {
    printf("%d ", temp1->data);
    temp1=temp->next;
  }
  return 0;
}
