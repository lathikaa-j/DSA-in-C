#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* head =NULL;
struct node *create(int val)
{
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data= val;
    newnode->next = NULL;
    return newnode;
}
void insert_begin(int val)
{
    struct node* newnode= create(val);
    if(head==NULL)
    {
        head = newnode;
        return;
    }
    newnode->next = head;
    head = newnode;
    printf("Success\n");
}
void insert_pos(int val)
{
    int pos,i;
    struct node *temp;
    struct node* newnode= create(val);
    printf("Enter position :");
    scanf("%d",&pos);
    if(head==NULL)
    {
        head = newnode;
        return;
    }
    if(pos==1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }
    temp = head;
    for(i=1; i<pos-1 && temp!=NULL; i++)
        temp = temp->next;
    if(temp== NULL)
    {
        printf("Invalid position");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    printf("Success\n");
}
void insert_end(int val)
{
    struct node *temp;
    struct node* newnode= create(val);
    if(head==NULL)
    {
        head = newnode;
        return;
    }
    temp = head;
    while(temp->next !=NULL)
        temp = temp->next;
    temp->next = newnode;
    printf("Success\n");
}
void delete_begin()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List empty ");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head= NULL;
        printf("Node Deleted\n");
        return;
    }
    temp = head;
    head = temp->next;
    free(temp);
    printf("Node Deleted\n");
}
void delete_pos()
{
  int pos,i;
    struct node *temp, *prev;
    printf("Enter position :");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("List empty ");
        return;
    }
    if(pos==1)
    {
        temp = head;
        head = temp->next;
        free(temp);
        printf("Node Deleted\n");
        return;
    }
    temp = head;
    for(i=1; i<pos && temp!=NULL; i++)
    {
        prev= temp;
        temp = temp->next;
    }
    if(temp== NULL)
    {
        printf("Invalid position");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Deleted\n");  
}
void delete_end()
{
    struct node *temp, *prev;
    temp=head;
    if(head==NULL)
    {
        printf("List empty ");
        return;
    }
    if(head->next ==NULL)
    {
        free(head);
        head= NULL;
        printf("Deleted\n");
        return;
    }
    while(temp->next !=NULL)
    {
        prev= temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Node deleted\n");
}
void display()
{
    struct node *temp;
    if(head ==NULL)
    {
        printf("List empty\n");
        return;
    }
    printf("List is\n");
    temp = head;
    while(temp!=NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int ch,val;
    printf("Enter \n1.Insert at Begin\n2.Insert at position\n3.Insert at end\n4.Delete at Begin\n5.Delete at position\n6.Delet at end\n7.Display\n");
    while(1)
    {
        printf("Enter choice\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter value to insert ");
                scanf("%d", &val);
                insert_begin(val);
                break;
            case 2:
                printf("Enter value to insert ");
                scanf("%d", &val);
                insert_pos(val);
                break;
            case 3:
                printf("Enter value to insert ");
                scanf("%d", &val);
                insert_end(val);
                break;
            case 4:
                delete_begin();
                break;
            case 5:
                delete_pos();
                break;
            case 6:
                delete_end();
                break;
            case 7:
                display();
                break;
        }
    }
}
