#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};

struct queue *create(int d)
{
    struct queue *nn = (struct queue *)malloc(sizeof(struct queue));
    nn->data = d;
    nn->next = NULL;
    return nn;
}

void enqueue(struct queue **p, int d)
{
    struct queue *nn = create(d);

    if (*p == NULL)
    {
        *p = nn;
        nn->next = *p;
    }
    else
    {
        struct queue *temp = *p;

        while (temp->next != *p)
        {
            temp = temp->next;
        }

        nn->next = *p;
        temp->next = nn;
    }
}

void dequeue(struct queue **p)
{
    if (*p == NULL)
    {
        printf("Queue is Empty!\n");
        return;
    }

    if ((*p)->next == *p)
    {
        free(*p);
        *p = NULL;
        return;
    }

    struct queue *temp = *p, *prev = NULL;

    while (temp->next != *p)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *p;
    free(temp);
}

void display(struct queue *p)
{
    if (p == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    struct queue *temp = p;

    printf("Queue elements: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != p);

    printf("(back to head)\n");
}

int main()
{
    struct queue *head = NULL;
    int choice = 0, d;

    while (choice != 4)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &d);
            enqueue(&head, d);
            break;

        case 2:
            dequeue(&head);
            break;

        case 3:
            display(head);
            break;

        case 4:
            printf("Exiting!\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}