//Given a key (or data) to be inserted, your task is to complete the function insertAtBeginning() which inserts the data in front of the linked list and insertAtEnd() which appends the data at the end of the linked list.
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
    //n->next=tail;
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
    //struct node *temp=(struct node*)malloc(sizeof(struct node));
    //temp=NULL;
    n=head;
    while(n->data!=value)
    {
        previous=n;
        n=n->next;
    }
    printf("ami akhane");
    //free(n);
    printf("%d %d\n",previous->data,n->data);
    previous->next=n->next;

    //temp->data=value;
    //temp->next=n->next;
}

int main()
{
    //struct node *first=NULL;
    //struct node *second=NULL;
    //struct node *third=NULL;
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

    /*
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d",&m);
        for(j=0; j<m; j++)
        {
            scanf("%d%d",&value,&position);
            if(position==0)
                insertAtBeginning(value);
            else
                insertAtEnd(value);
        }
        printAll(head);
        //  head=NULL;
        free(head);

        head=(struct node*)malloc(sizeof(struct node));
        head=NULL;
    }

    /*

    struct node *first=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));

    //first=NULL;


    first->data=1;
    first->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    head=first;
    tail=third;

    printAll(head);

    insertAtBeginning(5);

    printAll(head);

    insertAtEnd(7);

    printAll(head);
    */
}
