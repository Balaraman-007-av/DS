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
    if(*p==NULL) 
    {
        *p=nn;
        nn->next=*p;
    }
    else
    {
        struct node *temp=*p;
        while(temp->next!=*p)
        {
            temp=temp->next;
        }
        temp->next=nn;
        nn->next=*p;
        *p=nn;
    }
}

void deletion_beg(struct node**p)
{
    if(*p==NULL) 
    {
        printf("\nDeletion Not possible\n");
        return;
    } 
    else
    {
        struct node *temp = *p;
        if(temp->next==*p) 
        {
            *p=NULL;
            free(temp);
            return;
        }
        else
        {
            while(temp->next!=*p)
            {
                temp=temp->next;
            }
            temp->next=(*p)->next;
            free(*p);
            *p=temp->next;
        }
    }
}

void deletion_end(struct node**p)
{
    if(*p==NULL) 
    {
        printf("\nDeletion Not possible\n");
        return;
    } 
    else
    {
        struct node *temp = *p,*prev=NULL;
        if(temp->next==*p)
        {
            *p=NULL;
            free(temp);
            return;
        }
        else
        {
            while(temp->next!=*p)                                                              
            {
                prev=temp;
                temp=temp->next;
            }
            prev->next=*p;
            free(temp);
        }
    }
}

void deletion_pos(struct node**p,int pos)
{
    int c=count(*p);
    if(*p==NULL) 
    {
        printf("\nDeletion Not possible\n");
        return;
    }
    else if(pos<0 || pos>c)
    {
        printf("Invalid position\n");
        return;
    }
    else if(pos==1) deletion_beg(p);
    else
    {
        struct node *temp = *p,*prev=NULL;
        for(int i=1;i<pos;i++)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp->next==*p) 
        {
            deletion_end(p);
            return;
        }
        else
        {
            prev->next=temp->next;
            free(temp);
        }
    }
}

void display(struct node *p) {
    if (p == NULL) {
        printf("\nLinked list: empty\n");
        return;
    }
    struct node *temp = p;
    printf("\nLinked list: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != p);
    printf("(%d back to head)\n", (p)->data);  
}

int count(struct node *p)
{
    int count=0;
    struct node *temp=p;
    do
    {
        count++;
        temp=temp->next;
    }
    while(temp!=p);
    return count;
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

