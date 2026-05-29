#include <stdio.h>
#include <stdlib.h>

struct vehicle
{
    int vehicleNumber;
    char ownerName[50];
    struct vehicle *left;
    struct vehicle *right;
};

typedef struct vehicle NODE;

// Function Declarations
NODE* insert(NODE*, int, char[]);
void inorder(NODE*);
void preorder(NODE*);
void postorder(NODE*);
NODE* deleteVehicle(NODE*, int);

// Insert Function
NODE* insert(NODE* root, int vehicleNumber, char ownerName[])
{
    NODE *newnode, *curr, *parent;

    newnode = (NODE*)malloc(sizeof(NODE));

    if(newnode == NULL)
    {
        printf("Memory Allocation Failed\n");
        return root;
    }

    newnode->vehicleNumber = vehicleNumber;

    int i = 0;
    while(ownerName[i] != '\0')
    {
        newnode->ownerName[i] = ownerName[i];
        i++;
    }
    newnode->ownerName[i] = '\0';

    newnode->left = NULL;
    newnode->right = NULL;

    if(root == NULL)
    {
        printf("First Vehicle Record Added\n");
        return newnode;
    }

    curr = root;
    parent = NULL;

    while(curr != NULL)
    {
        parent = curr;

        if(vehicleNumber < curr->vehicleNumber)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(vehicleNumber < parent->vehicleNumber)
        parent->left = newnode;
    else
        parent->right = newnode;

    printf("Vehicle Record Added Successfully\n");

    return root;
}

// Inorder Traversal
void inorder(NODE* root)
{
    if(root != NULL)
    {
        inorder(root->left);

        printf("Vehicle No: %d | Owner: %s\n",
               root->vehicleNumber,
               root->ownerName);

        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(NODE* root)
{
    if(root != NULL)
    {
        printf("%d ", root->vehicleNumber);

        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(NODE* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);

        printf("%d ", root->vehicleNumber);
    }
}

// Delete Function
NODE* deleteVehicle(NODE* root, int vehicleNumber)
{
    NODE *curr, *parent, *successor, *p;

    curr = root;
    parent = NULL;

    if(root == NULL)
    {
        printf("No Vehicle Records Available\n");
        return root;
    }

    while(curr != NULL && curr->vehicleNumber != vehicleNumber)
    {
        parent = curr;

        if(vehicleNumber < curr->vehicleNumber)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(curr == NULL)
    {
        printf("Vehicle Record Not Found\n");
        return root;
    }

    if(curr->left == NULL)
        p = curr->right;

    else if(curr->right == NULL)
        p = curr->left;

    else
    {
        successor = curr->right;

        while(successor->left != NULL)
            successor = successor->left;

        successor->left = curr->left;

        p = curr->right;
    }

    if(parent == NULL)
    {
        free(curr);
        return p;
    }

    if(curr == parent->left)
        parent->left = p;
    else
        parent->right = p;

    free(curr);

    printf("Vehicle Record Deleted Successfully\n");

    return root;
}

// Main Function
int main()
{
    NODE *root = NULL;

    int choice;
    int vehicleNumber;

    char ownerName[50];

    while(1)
    {
        printf("\n--- VEHICLE REGISTRATION SYSTEM ---\n");

        printf("1. Add Vehicle\n");
        printf("2. Display Vehicles (Sorted)\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Delete Vehicle\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                printf("Enter Vehicle Number: ");
                scanf("%d", &vehicleNumber);

                printf("Enter Owner Name: ");
                scanf("%s", ownerName);

                root = insert(root, vehicleNumber, ownerName);

                break;

            case 2:

                printf("\n--- Vehicle Records ---\n");

                inorder(root);

                break;

            case 3:

                printf("\nPreorder Traversal:\n");

                preorder(root);

                printf("\n");

                break;

            case 4:

                printf("\nPostorder Traversal:\n");

                postorder(root);

                printf("\n");

                break;

            case 5:

                printf("Enter Vehicle Number to Delete: ");
                scanf("%d", &vehicleNumber);

                root = deleteVehicle(root, vehicleNumber);

                break;

            case 6:

                exit(0);

            default:

                printf("Invalid Choice\n");
        }
    }

    return 0;
}
