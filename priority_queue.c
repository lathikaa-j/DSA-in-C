#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    int priority;
    struct node* next;
};
struct node* head = NULL;
struct node* createNode(int data, int priority) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}
void enqueue(int data, int priority) {
    struct node* newNode = createNode(data, priority);

    if (head == NULL) {
        head = newNode;
        return;
    }
    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void dequeue() {
    if (head == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = head, *prev = NULL;
    struct node *highest = head, *highestPrev = NULL;
    while (temp != NULL) {
        if (temp->priority < highest->priority) {
            highest = temp;
            highestPrev = prev;
        }
        prev = temp;
        temp = temp->next;
    }
    if (highestPrev == NULL)
        head = head->next;
    else
        highestPrev->next = highest->next;
    printf("Dequeued: %d (Priority: %d)\n", highest->data, highest->priority);
    free(highest);
}
void display() {
    struct node* temp = head;

    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d(%d) -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    int choice, data, priority;

    while (1) {
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &priority);
                enqueue(data, priority);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
