#include <stdio.h>
#include <stdlib.h>
struct Node {
    int row, col, value;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int r, int c, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = r;
    newNode->col = c;
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}
void insert(int r, int c, int val) {
    struct Node* newNode = createNode(r, c, val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void display() {
    struct Node* temp = head;
    printf("\nSparse Matrix (row, col, value):\n");
    while (temp != NULL) {
        printf("%d %d %d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}
int main() {
    int i, r, c, val,n;
    printf("Enter number of non-zero elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter row, column and value: ");
        scanf("%d %d %d", &r, &c, &val);
        insert(r, c, val);
    }
    display();
}
