#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
};

int count(struct node *p)
{
    struct node *temp=p;
    int c=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    return c;
}

struct node *create(int d)
{
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->prev=NULL;
    nn->data=d;
    nn->next=NULL;
    return nn;
}

void insertion_beg(struct node **p,int d)
{
    struct node *nn = create(d);
    if(*p==NULL) *p=nn;
    else
    {
        nn->next=*p;
        (*p)->prev=nn;
        *p=nn;
    }
}

void insertion_end(struct node **p,int d)
{
    struct node *nn = create(d);
    if(*p==NULL) *p=nn;
    else
    {
        struct node *temp = *p;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;
        nn->prev=temp;
    }
}

void insertion_pos(struct node **p,int pos,int d)
{
    struct node *nn = create(d);
    int c=count(*p);
    int i = 1;
    if(pos<1 || pos>c+1) 
    {
        printf("Invalid Position!\n");
        return;
    }
    else if(pos==1) insertion_beg(p,d);
    else
    {
        struct node *temp = *p;
        while(i!=pos-1)
        {
            temp=temp->next;
            i++;
        }
        if(temp->next==NULL) insertion_end(*p,d);
        else
        {
            nn->prev = temp;
            nn->next = temp->next;
            temp->next=nn;
            nn->next->prev=nn;
        }
    }
}

void display(struct node *p)
{
    struct node *temp  = p;
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
    while(choice!=5)
    {
        printf("\n------MENU------\n1. Insert at begining\n2. Insert at end\n3. Insert at position\n4. display\n5. Exit");
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
            printf("\nEnter data to insert at end:");
            scanf("%d",&d);
            insertion_end(&head,d);
            break;

        case 3:
            printf("\nEnter position to insert data:");    
            scanf("%d",&pos);
            printf("\nEnter data to insert:");
            scanf("%d",&d);   
            insertion_pos(&head,pos,d);
            break;
        
        case 4:
            display(head);
            break;
        
        case 5:
            printf("\nExisting!\n");
            break;

        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
    return 0;
}

