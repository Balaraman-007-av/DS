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

void insertion_end(struct node**p,int d)
{
    struct node *nn=create(d);
    if(*p==NULL) *p=nn;
    else
    {
        struct node *temp=*p;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;
    }
}

void insertion_pos(struct node **p,int pos, int d)
{
    struct node *nn=create(d);
    struct node *temp=*p;
    if(temp==NULL) temp=nn;
    else
    {
        int i=1;
        while(i!=pos-1)
        {
            temp=temp->next;
            i++;
        }
        nn->next = temp->next;
        temp->next = nn;
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

void count(struct node *p)
{
    int count=0;
    struct node *temp=p;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    printf("\nNumber of nodes: %d\n",count);
}
int main()
{
    struct node *head=NULL;
    int d,pos,choice=0;
    while(choice!=7)
    {
        printf("\n------MENU------\n1. Create node\n2. Insert at begining\n3. Insert at end\n4. Insert at position\n5. display\n6. Number of nodes\n7. Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data to create a node:");
            scanf("%d",&d);
            create(d);
            break;

        case 2:
            printf("\nEnter data to insert at beginning:");
            scanf("%d",&d);
            insertion_beg(&head,d);
            break;
            
        case 3:
            printf("\nEnter data to insert at end:");
            scanf("%d",&d);
            insertion_end(&head,d);
            break;

        case 4:
            printf("\nEnter position to insert data:");
            scanf("%d",&pos);
            printf("\nEnter data to insert:");
            scanf("%d",&d);   
            insertion_pos(&head,pos,d);
            break;
        
        case 5:
            display(head);
            break;

        case 6:
            count(head);
            break;
        
        case 7:
            printf("\nExisting!\n");
            break;

        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
    return 0;
}

