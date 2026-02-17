#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create(int d) {
    struct node* nn = (struct node*)malloc(sizeof(struct node));
    nn->data = d;
    nn->next = NULL;
    return nn;
}

void insertion_beg(struct node** head, int d) {
    struct node *nn = create(d);
    nn->next = *head;
    *head = nn;
}

void insertion_mid(struct node** head, int d) {
    if (*head == NULL) {
        // If list is empty, just insert at beginning
        insertion_beg(head, d);
        return;
    }

    struct node *slow = *head, *fast = *head;
    struct node *prev = NULL;

    // Floyd’s (tortoise & hare) to find middle
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow now points to middle node
    struct node *nn = create(d);

    if (prev == NULL) {
        // Only one node previously
        nn->next = *head;
        *head = nn;
    } else {
        nn->next = slow;
        prev->next = nn;
    }
}

void display(struct node *head) {
    struct node *temp = head;
    printf("\nLinked list: ");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    int choice, d;

    while (1) {
        printf("\n------MENU------\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Middle\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &d);
                insertion_beg(&head, d);
                break;

            case 2:
                printf("Enter data to insert at middle: ");
                scanf("%d", &d);
                insertion_mid(&head, d);
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
