#include<stdio.h>
#include<stdlib.h>

int *arr, front=-1, rear=-1, max;

void enqueue(int d)
{
    if(rear == max-1)
    {
        printf("Queue is full\n");
        return;
    }
    if(front == -1)
        front = 0;

    rear++;
    arr[rear] = d;
}

int dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else if(front == rear)
    {
        int del = arr[front];
        front = rear = -1;
        return del;
    }
    else
    {
        int del = arr[front];
        front++;
        return del;
    }
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for(int i = front; i <= rear; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int choice = 0, d;

    printf("Enter the size of Queue: ");
    scanf("%d", &max);

    arr = (int *)malloc(sizeof(int) * max);

    while(choice != 4)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &d);
                enqueue(d);
                break;

            case 2:
            {
                int val = dequeue();
                if(val != -1)
                    printf("Dequeued: %d\n", val);
                break;
            }

            case 3:
                display();
                break;

            case 4:
                printf("Exiting!\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    free(arr);
    return 0;
}