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

void deletion_beg(struct node**p)
{
    if(*p==NULL) printf("\nDeletion Not possible\n");
    else
    {
        struct node *temp = *p;
        *p=temp->next;
        free(temp);
    }
}

void deletion_end(struct node**p)
{
    if(*p==NULL) printf("\nDeletion Not possible\n");
    else
    {
        struct node *temp = *p,*prev=NULL;
        while(temp->next!=NULL)                                                              
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
    }
}

void deletion_pos(struct node**p,int pos)
{
    if(*p==NULL) printf("\nDeletion Not possible\n");
    else
    {
        struct node *temp = *p,*prev=NULL;
        for(int i=1;i<pos;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
    }
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
    while(choice!=6)
    {
        printf("\n------MENU------\n1. Insert at begining\n2. Delete at beginning\n3. Delete at end\n4. Delete at position\n5. Display\n6. Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data to insert at beginning:");
            scanf("%d",&d);
            insertion_beg(&head,d);
            break;
  
        case 2:
            deletion_beg(&head);
            break;
        
        case 3:
            deletion_end(&head);
            break;    

        case 4:
            printf("\nEnter position to delete data:");    
            scanf("%d",&pos);   
            deletion_pos(&head,pos);
            break;
        
        case 5:
            display(head);
            break;

        case 6:
            printf("\nExisting!\n");
            break;

        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
    return 0;
}

