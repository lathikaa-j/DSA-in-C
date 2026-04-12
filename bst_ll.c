#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node* root = NULL;
struct node* create(int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = NULL;
    return newnode;
}
struct node* insert(struct node* root, int val) {
    if (root == NULL)
        return create(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}
void search(struct node* root, int val) {
    if (root == NULL) {
        printf("Not Found\n");
        return;
    }

    if (root->data == val) {
        printf("Found\n");
        return;
    }

    if (val < root->data)
        search(root->left, val);
    else
        search(root->right, val);
}
struct node* findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}
struct node* findMax(struct node* root) {
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct node* deleteNode(struct node* root, int val) {
    if (root == NULL)
        return root;

    if (val < root->data)
        root->left = deleteNode(root->left, val);

    else if (val > root->data)
        root->right = deleteNode(root->right, val);

    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    int choice, val;

    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n7.Min\n8.Max\n9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                search(root, val);
                break;
            case 4:
                printf("Inorder: ");
                inorder(root);
                break;
            case 5:
                printf("Preorder: ");
                preorder(root);
                break;
            case 6:
                printf("Postorder: ");
                postorder(root);
                break;
            case 7:
                if (root)
                    printf("Min = %d\n", findMin(root)->data);
                else
                    printf("Tree empty\n");
                break;
            case 8:
                if (root)
                    printf("Max = %d\n", findMax(root)->data);
                else
                    printf("Tree empty\n");
                break;
            case 9:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
