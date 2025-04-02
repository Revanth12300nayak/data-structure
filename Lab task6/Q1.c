#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head;
void main()
{
  struct Node *temp,*nnode;
  head=NULL;
  int choice=1,count=0;
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
    count++;
  }
  printf("\n");
  printf("The length pf linked list is %d", count);
}
