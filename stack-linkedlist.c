#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack *next;
};

struct stack *create(int d) {
    struct stack *nn = (struct stack*) malloc(sizeof(struct stack));
    nn->data = d;
    nn->next = NULL;
    return nn;
}

void push(struct stack **p, int d) {
    struct stack *nn = create(d);
    nn->next = *p;
    *p = nn;
}

void pop(struct stack **p) {
    if (*p == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    struct stack *temp = *p;
    printf("%d : Popped\n", temp->data);
    *p = (*p)->next;
    free(temp);
}

int peek(struct stack *p) {
    if (p == NULL) {
        printf("Stack is Empty\n");
        return -1;
    }
    return p->data;
}

int isEmpty(struct stack *p) {
    return p == NULL;
}

int size(struct stack *p) {
    int c = 0;
    while (p != NULL) {
        p = p->next;
        c++;
    }
    return c;
}

void display(struct stack *p) {
    if (p == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    printf("Stack elements: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int choice = 0, val;
    struct stack *head = NULL;

    while (choice != 7) {
        printf("\n-----------MENU----------\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Size\n6. Display\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(&head, val);
                break;
            case 2:
                pop(&head);
                break;
            case 3:
                printf("The value at peek: %d\n", peek(head));
                break;
            case 4:
                isEmpty(head) ? printf("Stack is empty\n") : printf("Stack is not empty\n");
                break;
            case 5:
                printf("Size of the stack: %d\n", size(head));
                break;
            case 6:
                display(head);
                break;
            case 7:
                printf("Exiting!\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
