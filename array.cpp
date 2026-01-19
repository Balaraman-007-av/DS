#include <stdio.h>

int arr[100];

void insertion(int *n, int val, int pos)
{
    if(pos < 1 || pos > *n + 1)
    {
        printf("Invalid position!\n");
        return;
    }
    for (int i = *n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = val;
    (*n)++;
}

void deletion(int *n, int pos)
{
    if(pos < 1 || pos > *n)
    {
        printf("Invalid position!\n");
        return;
    }
    for (int i = pos - 1; i < *n - 1; i++)
        arr[i] = arr[i + 1];
    (*n)--;
}

void searching(int key, int *n)
{
    int found = -1;
    for(int i = 0; i < *n; i++)
    {
        if(arr[i] == key)
        {
            found = i;
            break;
        }
    }
    if(found != -1)
        printf("Element %d found at index %d\n", key, found);
    else
        printf("Element %d not found!\n", key);
}

void display(int *n)
{
    printf("The elements of the array are: ");
    for(int i = 0; i < *n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n, i, choice = 0, pos, val, key;

    printf("Enter the number of array elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    while (choice != 5)
    {
        printf("\n1. Insertion\n2. Deletion\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertion(&n, val, pos);
                break;

            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deletion(&n, pos);
                break;

            case 3:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                searching(key, &n);
                break;

            case 4:
                display(&n);
                break;

            case 5:
                printf("Exiting program!\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}