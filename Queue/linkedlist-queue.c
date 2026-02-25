#include<stdio.h>
#include<stdlib.h>

struct queue{
    int data;
    struct queue *next;
};

struct queue* create(int d) {
    struct queue* nn = (struct queue*)malloc(sizeof(struct queue));
    nn->data = d;
    nn->next = NULL;
    return nn;
}

void enqueue(struct queue **p,int d)
{
    struct queue *nn=create(d);
    if(*p==NULL)    
    {
        *p=nn;
    }
    else
    {
        nn->next=*p;
        *p=nn;
    }
}

void deqeue(struct queue **p)
{
    if(*p==NULL)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        struct queue *temp=*p,*prev=NULL;
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);   
    }
}

void display(struct queue *p)
{
    if(p==NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        struct queue *temp = p;
        printf("Queue elements: ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("NULL");
    }
}

int main()
{
    struct queue *head=NULL;
    int choice,d;
    while(choice!=4)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d",&d);
                enqueue(&head,d);
                break;
            
            case 2:
                deqeue(&head);
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Existing!\n");
                break;    
        }
    }
    return 0;
}