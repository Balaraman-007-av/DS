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

void insertion_end(struct node**p,int d)
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
    }
}

void insertion_pos(struct node **p,int pos, int d)
{
    int c=cound(*p);
    struct node *nn=create(d);
    struct node *temp=*p;
    if(*p==NULL) 
    {
        *p=nn;
        nn->next=*p;
    }
    else if(pos<0 || pos>c) 
    {
        printf("Invalid position\n");
        return;
    }
    else if(pos==1) insertion_beg(p,d);
    else
    {
        int i=1;
        while(i!=pos-1)
        {
            temp=temp->next;
            i++;
        }
        if(temp->next==*p) insertion_end(p,d);
        else
        {
            nn->next = temp->next;
            temp->next = nn;
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
    while(choice!=7)
    {
        printf("\n------MENU------\n1. Create node\n2. Insert at begining\n3. Insert at end\n4. Insert at position\n5. display\n6. Exit");
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
            printf("\nExisting!\n");
            break;

        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
    return 0;
}

