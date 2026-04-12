#include<stdio.h>
#include<string.h>

int bst[100];
char exp[100];

/* -------- BST FUNCTIONS -------- */

void insert(int x)
{
    int i=1;
    while(bst[i]!=0)
    {
        if(x < bst[i])
            i=2*i;
        else
            i=2*i+1;
    }
    bst[i]=x;
}

void search(int x)
{
    int i=1;
    while(bst[i]!=0)
    {
        if(bst[i]==x)
        {
            printf("Element Found\n");
            return;
        }
        else if(x < bst[i])
            i=2*i;
        else
            i=2*i+1;
    }
    printf("Element Not Found\n");
}

void delete_node(int x)
{
    int i=1;
    while(bst[i]!=0)
    {
        if(bst[i]==x)
        {
            bst[i]=0;
            printf("Deleted\n");
            return;
        }
        else if(x < bst[i])
            i=2*i;
        else
            i=2*i+1;
    }
    printf("Element Not Found\n");
}

void inorder(int i)
{
    if(bst[i]!=0)
    {
        inorder(2*i);
        printf("%d ",bst[i]);
        inorder(2*i+1);
    }
}

/* -------- EXPRESSION TREE -------- */

void create_exp()
{
    char postfix[50];
    int i=1,j;

    printf("Enter postfix expression: ");
    scanf("%s",postfix);

    for(j=0;j<strlen(postfix);j++)
    {
        exp[i]=postfix[j];
        i++;
    }
}

void inorder_exp(int i)
{
    if(exp[i]!=0)
    {
        inorder_exp(2*i);
        printf("%c ",exp[i]);
        inorder_exp(2*i+1);
    }
}

void delete_exp()
{
    int pos;
    printf("Enter position to delete: ");
    scanf("%d",&pos);

    exp[pos]=0;
    printf("Node Deleted\n");
}

/* -------- MAIN -------- */

int main()
{
    int ch,x;

    while(1)
    {
        printf("\n1.Insert BST\n2.Search BST\n3.Delete BST\n4.Inorder BST\n");
        printf("5.Create Expression Tree\n6.Inorder Expression\n7.Delete Expression Node\n8.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&x);
                insert(x);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&x);
                search(x);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d",&x);
                delete_node(x);
                break;

            case 4:
                inorder(1);
                break;

            case 5:
                create_exp();
                break;

            case 6:
                inorder_exp(1);
                break;

            case 7:
                delete_exp();
                break;

            case 8:
                return 0;
        }
    }
}
