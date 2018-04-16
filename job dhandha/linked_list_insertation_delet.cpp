#include<bits/stdc++.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head=(struct node*)malloc(sizeof(struct node));
struct node *tail=(struct node*)malloc(sizeof(struct node));

void printAll(struct node *n)
{
    int key=0;
    while(n!=NULL)
    {
        if(key==0)
        {
            key=1;
        }
        else
        {
            printf(" ");
        }
        printf("%d",n->data);
        n=n->next;
    }
    printf("\n");
}

void insertAtBeginning(int value)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=head;

    head=temp;
}

void insertAtEnd(int value)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *last=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
        return;
    }
    else
    {
        last=head;

        while(last->next!=NULL)
            last=last->next;

        last->next=temp;

    }
}

void insertAtMiddle(int value)
{
  struct node *temp=(struct node *)malloc(sizeof(struct node));

  struct node *n=head;
  while(n->data!=value)
  {
    n=n->next;
  }
  temp->data=value+1;
  temp->next=n->next;

  n->next=temp;
}

void deleteAtMiddle(int value)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    struct node *previous=(struct node*)malloc(sizeof(struct node));
    n=head;
    while(n->data!=value)
    {
        previous=n;
        n=n->next;
    }
    previous->next=n->next;
}

int main()
{
    int n,m,i,j,value,position;

    head=NULL;
    tail=NULL;


    insertAtBeginning(5);
    insertAtBeginning(7);
    insertAtEnd(9);
    insertAtBeginning(11);
    insertAtEnd(13);
    insertAtMiddle(9);
    printAll(head);
    deleteAtMiddle(7);
    printAll(head);
}
