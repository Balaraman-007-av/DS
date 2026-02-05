#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;
int max;

void push(int value)
{
    if (top == max - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

void pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("%d : Popped\n", stack[top--]);
}

int peek()
{
    if (top == -1) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack[top];
}

int isEmpty()
{
    return top == -1;
}

int isFull()
{
    return top == max - 1;
}

int size()
{
    return top + 1;
}

void display()
{
    if (top == -1)
        printf("Stack is Empty\n");
    else {
        printf("Element of Stack: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    int choice = 0, val;

    printf("Enter the size of the stack: ");
    scanf("%d", &max);

    stack = (int *)malloc(sizeof(int) * max);
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    while (choice != 8)
    {
        printf("\n-----------MENU----------\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. isFull\n6. Size\n7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &val);
            push(val);
            break;

        case 2:
            pop();
            break;

        case 3:
            val=peek();
            if(val!=-1)
            printf("The value at peek: %d\n", val);
            break;

        case 4:
            isEmpty() ? printf("Stack is empty\n") : printf("Stack is not empty\n");
            break;

        case 5:
            isFull() ? printf("Stack is Full\n") : printf("Stack is not Full\n");
            break;

        case 6:
            printf("Size of the stack: %d\n", size());
            break;

        case 7:
            display();
            break;

        case 8:
            printf("Exiting!\n");
            break;

        default:
            printf("Invalid Choice\n");
        }
    }

    free(stack);
    return 0;
}
