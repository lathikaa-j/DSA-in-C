#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct node {
    char data;
    struct node *left, *right;
};

struct node* stack[100];
int top = -1;

void push(struct node* n) {
    stack[++top] = n;
}
struct node* pop() {
    return stack[top--];
}
struct node* createNode(char val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* constructTree(char postfix[]) {
    int i;
    for(i = 0; postfix[i] != '\0'; i++) {
        
        if(isalnum(postfix[i])) {
            push(createNode(postfix[i]));
        }
     
        else {
            struct node* right = pop();
            struct node* left = pop();

            struct node* newNode = createNode(postfix[i]);
            newNode->left = left;
            newNode->right = right;

            push(newNode);
        }
    }
    return pop();
}

void inorder(struct node* root) {
    if(root != NULL) {
        if(root->left != NULL) printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if(root->right != NULL) printf(")");
    }
}

void preorder(struct node* root) {
    if(root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    struct node* root = constructTree(postfix);

    printf("\nInfix expression: ");
    inorder(root);

    printf("\nPrefix expression: ");
    preorder(root);

    return 0;
}
