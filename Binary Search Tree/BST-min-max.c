#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int val;
    struct tree *left, *right;
};

struct tree *create(int val)
{
    struct tree *nn = (struct tree *)malloc(sizeof(struct tree));
    nn->val = val;
    nn->left = nn->right = NULL;
    return nn;
}

struct tree *insert(struct tree *root, int val)
{
    if (root == NULL)
        return create(val);

    if (val < root->val)
        root->left = insert(root->left, val);

    else if (val > root->val)
        root->right = insert(root->right, val);

    return root;
}

void preorder(struct tree *p)
{
    if (p == NULL)
        return;

    printf("%d ", p->val);
    preorder(p->left);
    preorder(p->right);
}

int minvalue(struct tree *p)
{
    struct tree *curr = p;
    while (curr->left != NULL)
        curr = curr->left;
    return curr->val;
}

int maxvalue(struct tree *p)
{
    struct tree *curr = p;
    while (curr->right != NULL)
        curr = curr->right;
    return curr->val;
}

int main()
{
    struct tree *root = NULL;
    int choice = 0, val;

    while (choice != 5)
    {
        printf("\n1. Insert\n2. Display\n3. Mininum value\n4. Maximum value\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            root = insert(root, val);
            break;

        case 2:
            if (root == NULL)
                printf("Tree is Empty!\n");
            else
            {
                printf("Preorder: ");
                preorder(root);
                printf("\n");
            }
            break;

        case 3:
            if (root == NULL)
                printf("Tree is Empty!\n");
            else
                printf("Minimum value: %d\n", minvalue(root));
            break;

        case 4:
            if (root == NULL)
                printf("Tree is Empty!\n");
            else
                printf("Maximum value: %d\n", maxvalue(root));
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice\n");
        }
    }
}