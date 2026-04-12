#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
    int height;
};

struct node* root=NULL;

/* height */
int height(struct node *n)
{
    if(n==NULL)
        return -1;
    return n->height;
}

/* max */
int max(int a,int b)
{
    return (a>b)?a:b;
}

/* create node */
struct node* create(int val)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=newnode->right=NULL;
    newnode->height=0;
    return newnode;
}

/* balance factor */
int getBalance(struct node *n)
{
    if(n==NULL)
        return 0;
    return height(n->left)-height(n->right);
}

/* right rotate */
struct node* rightRotate(struct node *y)
{
    struct node *x=y->left;
    struct node *t2=x->right;

    x->right=y;
    y->left=t2;

    y->height=1+max(height(y->left),height(y->right));
    x->height=1+max(height(x->left),height(x->right));

    return x;
}

/* left rotate */
struct node* leftRotate(struct node *x)
{
    struct node *y=x->right;
    struct node *t2=y->left;

    y->left=x;
    x->right=t2;

    x->height=1+max(height(x->left),height(x->right));
    y->height=1+max(height(y->left),height(y->right));

    return y;
}

/* insert */
struct node* insert(struct node* rootNode,int val)
{
    if(rootNode==NULL)
        return create(val);

    if(val<rootNode->data)
        rootNode->left=insert(rootNode->left,val);
    else if(val>rootNode->data)
        rootNode->right=insert(rootNode->right,val);
    else
        return rootNode;

    rootNode->height=1+max(height(rootNode->left),height(rootNode->right));

    int balance=getBalance(rootNode);

    /* LL */
    if(balance>1 && val<rootNode->left->data)
        return rightRotate(rootNode);

    /* RR */
    if(balance<-1 && val>rootNode->right->data)
        return leftRotate(rootNode);

    /* LR */
    if(balance>1 && val>rootNode->left->data)
    {
        rootNode->left=leftRotate(rootNode->left);
        return rightRotate(rootNode);
    }

    /* RL */
    if(balance<-1 && val<rootNode->right->data)
    {
        rootNode->right=rightRotate(rootNode->right);
        return leftRotate(rootNode);
    }

    return rootNode;
}

/* find minimum */
struct node* minValue(struct node* rootNode)
{
    struct node* current=rootNode;
    while(current->left!=NULL)
        current=current->left;
    return current;
}

/* delete */
struct node* deleteNode(struct node* rootNode,int val)
{
    if(rootNode==NULL)
        return rootNode;

    if(val<rootNode->data)
        rootNode->left=deleteNode(rootNode->left,val);
    else if(val>rootNode->data)
        rootNode->right=deleteNode(rootNode->right,val);
    else
    {
        if(rootNode->left==NULL || rootNode->right==NULL)
        {
            struct node* temp = rootNode->left ? rootNode->left : rootNode->right;

            if(temp==NULL)
            {
                temp=rootNode;
                rootNode=NULL;
            }
            else
                *rootNode=*temp;

            free(temp);
        }
        else
        {
            struct node* temp=minValue(rootNode->right);
            rootNode->data=temp->data;
            rootNode->right=deleteNode(rootNode->right,temp->data);
        }
    }

    if(rootNode==NULL)
        return rootNode;

    rootNode->height=1+max(height(rootNode->left),height(rootNode->right));

    int balance=getBalance(rootNode);

    /* LL */
    if(balance>1 && getBalance(rootNode->left)>=0)
        return rightRotate(rootNode);

    /* LR */
    if(balance>1 && getBalance(rootNode->left)<0)
    {
        rootNode->left=leftRotate(rootNode->left);
        return rightRotate(rootNode);
    }

    /* RR */
    if(balance<-1 && getBalance(rootNode->right)<=0)
        return leftRotate(rootNode);

    /* RL */
    if(balance<-1 && getBalance(rootNode->right)>0)
    {
        rootNode->right=rightRotate(rootNode->right);
        return leftRotate(rootNode);
    }

    return rootNode;
}

/* search */
void search(struct node* rootNode,int val)
{
    if(rootNode==NULL)
    {
        printf("Not Found\n");
        return;
    }

    if(val==rootNode->data)
        printf("Element Found\n");
    else if(val<rootNode->data)
        search(rootNode->left,val);
    else
        search(rootNode->right,val);
}

/* traversals */
void inorder(struct node* rootNode)
{
    if(rootNode!=NULL)
    {
        inorder(rootNode->left);
        printf("%d ",rootNode->data);
        inorder(rootNode->right);
    }
}

void preorder(struct node* rootNode)
{
    if(rootNode!=NULL)
    {
        printf("%d ",rootNode->data);
        preorder(rootNode->left);
        preorder(rootNode->right);
    }
}

void postorder(struct node* rootNode)
{
    if(rootNode!=NULL)
    {
        postorder(rootNode->left);
        postorder(rootNode->right);
        printf("%d ",rootNode->data);
    }
}

/* main */
int main()
{
    int ch,x;

    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Inorder\n5.Preorder\n6.Postorder\n7.Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&x);
                root=insert(root,x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&x);
                root=deleteNode(root,x);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d",&x);
                search(root,x);
                break;

            case 4:
                inorder(root);
                break;

            case 5:
                preorder(root);
                break;

            case 6:
                postorder(root);
                break;

            case 7:
                exit(0);
        }
    }
}
