#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node* create(int d)
{
    struct node* nn=(struct node*)malloc(sizeof(struct node));
    nn->data=d;
    nn->next=NULL;
    return nn;
}

void insertion_beg(struct node**p,int d)
{
    struct node *nn=create(d);
    if(*p==NULL) *p=nn;
    else
    {
        nn->next=*p;
        *p=nn;
    }
}

void reverse(struct node **p)
{
    struct node *prev=NULL, *curr=*p, *next=NULL;
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    (*p)=prev;
}

void display(struct node *p)
{
    struct node *temp=p;
    printf("\nLinked list:");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head=NULL;
    int d,pos,choice=0;
    while(choice!=4)
    {
        printf("\n------MENU------\n1. Insert at Begining\n2. Reverse\n3. Display\n4. Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data:");
            scanf("%d",&d);
            insertion_beg(&head,d);
            break;
        
        case 2:
            reverse(&head);
            break;
        
        case 3:
            display(head);
            break;
        
        case 4:
            printf("\nExisting!\n");
            break;

        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
    return 0;
}

