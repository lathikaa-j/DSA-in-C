#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;
struct node* create(int val)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = newnode->next = NULL;
    return newnode;
}
void insert_end(int val)
{
    struct node *temp = head;
    struct node *newnode = create(val);

    if(head == NULL)
    {
        head = newnode;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}
void display()
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void max_min()
{
    int min, max;
    struct node *temp = head;
    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }
    max = temp->data;
    min = temp->data;
    while(temp!=NULL)
    {
        if(temp->data> max)
            max = temp->data;
        if(temp->data<min)
            min = temp->data;
        temp = temp->next;
    }
    printf("Max is %d and min is %d ", max,min);
}
void palindrome()
{
    struct node *start = head;
    struct node *end = head;
    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }
    while(end->next!=NULL)
        end= end->next;
    while(start!=end && start->prev!= end)
    {
        if(start->data != end->data)
        {
            printf("Not palindrome\n");
            return;
        }
        start= start->next;
        end = end->prev;
    }
    printf("Palindrome\n");
}
void remove_dup()
{
    struct node *temp = head;
    if(head==NULL)
    {
        printf("List empty\n");
        return;
    }
    while(temp!=NULL && temp->next !=NULL)
    {
        if(temp->data == temp->next->data)
        {
            struct node *dup = temp->next;
            temp->next = dup->next;
            if(dup->next!=NULL)
                dup->next->prev = temp;
            free(dup);
        }
        else
            temp = temp->next;
    }
    printf("Duplicates removed\n");
}
void delete_all()
{
    struct node *temp;
    while(head!=NULL)
    {
        temp = head;
        head=head->next;
        free(temp);
    }
    printf("List deleted\n");
}
int main()
{
    int ch, val;
    printf("\n1.Insert\n2.Display\n3.Max&Min\n4.Palindrome\n5.Remove Duplicates\n6.Delete All\n");
    while(1)
    {
        printf("Enter choice ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter value to insert ");
                scanf("%d",&val);
                insert_end(val);
                break;
            case 2:
                display();
                break;
            case 3:
                max_min();
                break;
            case 4:
                palindrome();
                break;
            case 5:
                remove_dup();
                break;
            case 6:
                delete_all();
                break;
        }
    }
}
