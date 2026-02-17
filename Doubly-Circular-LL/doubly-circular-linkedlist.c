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
    do
    {
        temp=temp->next;
        c++;
    }while(temp!=p);
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
    if(*p==NULL) 
    {
        *p=nn;
        nn->next=nn;
        nn->prev=nn;
    }
    else
    {
        (*p)->prev->next=nn;
        nn->prev=(*p)->prev;
        nn->next=*p;
        (*p)->prev=nn;
        *p=nn;
    }
}
    
void insertion_end(struct node **p, int d)
{
    struct node *nn = create(d);

    if (*p == NULL)
    {
        *p = nn;
        nn->next = nn;
        nn->prev = nn;
    }
    else
    {
        (*p)->prev->next = nn;  
        nn->prev = (*p)->prev;  
        nn->next = *p;          
        (*p)->prev = nn;       
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
    else if(pos==c+1) insertion_end(p,d);
    else
    {
        struct node *temp = *p;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        nn->prev = temp;
        nn->next = temp->next;
        temp->next=nn;
        nn->next->prev=nn;
    }
}

void deletion_beg(struct node **p)
{
    struct node *temp=*p;
    if(*p==NULL) printf("Deletion not posible\n");
    else if((*p)==temp->next) 
    {
        free(temp);
        *p=NULL;
        return;
    }
    else
    {
        (*p)->prev->next=temp->next;
        temp->next->prev=(*p)->prev;
        (*p)=temp->next;
        free(temp);
    }
} 

void deletion_end(struct node **p)
{
    if(*p==NULL) printf("Deletion not Possible");
    else
    {
        struct node *temp;
        if(temp->next==*p)
        {
            (*p)=NULL;
            free(temp);
        }
        else
        {
            temp=(*p)->prev;
            temp->prev->next=*p;
            (*p)->prev=temp->prev;
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
        {
            printf("Invalid position\n");
            return;
        }
        else if(pos==1) deletion_beg(p);
        else if(pos==c) deletion_end(p);
        else
        {
            struct node *temp=*p;
            int i=1;
            while(i<pos)
            {
                temp=temp->next;
                i++;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
        }
    }
}

void display(struct node *p)
{
    if (p == NULL) 
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = p;
    do
    {
        printf("%d->", temp->data);
        temp = temp->next;
    } while (temp != p);

    printf("(back to head)\n");
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
            break;                                                     

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

