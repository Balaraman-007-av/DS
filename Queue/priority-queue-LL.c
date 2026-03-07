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
    }
    else
    {
        nn->next = *p;
        *p = nn;
    }
}

void deqeue(struct queue **p)
{
    if (*p == NULL)
    {
        printf("Queue is Empty!\n");
        return;
    }

    struct queue *temp = *p, *prev = NULL, *maxNode = *p, *maxPrev = NULL;

    while (temp != NULL)
    {
        if (temp->data > maxNode->data)
        {
            maxNode = temp;
            maxPrev = prev;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Dequeued: %d\n", maxNode->data);
    if (maxPrev == NULL)
        *p = maxNode->next;
    else
        maxPrev->next = maxNode->next;
    free(maxNode);
}

void display(struct queue *p)
{
    if (p == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        struct queue *temp = p;
        printf("Queue elements: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
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