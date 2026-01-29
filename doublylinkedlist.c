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
    if(pos<1 || pos>c) 
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
        if(temp->next==NULL) insertion_end(p,d);
        else
        {
            nn->prev = temp;
            nn->next = temp->next;
            temp->next=nn;
            nn->next->prev=nn;
        }
    }
}

void deletion_beg(struct node **p)
{
    if(*p==NULL) printf("Deletion not posible\n");
    else
    {
        struct node *temp=*p;
        *p=temp->next;
        if(*p!=NULL)
        {
            (*p)->prev=NULL;
        }
        free(temp);
    }
}

void deletion_end(struct node **p)
{
    if(*p==NULL) printf("Deletion not Possible");
    else
    {
        struct node *temp=*p;
        if(temp->next==NULL)
        {
            (*p)=NULL;
            free(temp);
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->prev->next=NULL;
            free(temp);
        }
    }
}

void deletion_pos(struct node **p,int pos)
{
    if(*p==NULL) printf("Deletion not posible\n");
    else
    {
        int c = count(*p);
        if(pos<1 || pos>c)
        printf("Invalid position\n");
        else if(pos==1) deletion_beg(p);
        else
        {
            struct node *temp=*p;
            int i=1;
            while(i<pos)
            {
                temp=temp->next;
                i++;
            }
            if(temp->next==NULL) deletion_end(p);
            else
            {
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(temp);
            }
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
    while(choice!=8)
    {
        printf("\n------MENU------\n1. Insert at begining\n2. Insert at end\n3. Insert at position\n4. Deletion at begining\n5. Deletion at end\n6. Deletion at position\n7. display\n8. Exit");
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
            deletion_beg(&head);
            break; 

        case 5:
            deletion_end(&head);
            break;

        case 6:
            printf("Enter the position to delete element:");
            scanf("%d",&pos);
            deletion_pos(&head,pos);
            break                                                                    ;

        case 7:
            display(head);
            break;
        
        case 8:
            printf("\nExisting!\n");
            break;

        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
    return 0;
}

