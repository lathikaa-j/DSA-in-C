#include<stdio.h>
#include<string.h>
#define MAX 100
char q[MAX][20];
int f=0,r=0;
void enqueue(char str[])
{
    strcpy(q[r], str);
    r++;
}
char *dequeue(){
    return q[f++];
}
int main()
{
    int n,i;
    printf("Enter the value of n ");
    scanf("%d", &n);
    enqueue("1");
    for(int i =1;i<=n;i++)
    {
        char curr[20];
        strcpy(curr, dequeue());
        printf("%s ",curr);
        char next1[20], next2[20];
        strcpy(next1, curr);
        strcat(next1, "0");
        enqueue(next1);
        
        strcpy(next2, curr);
        strcat(next2, "1");
        enqueue(next2);
        
    }
}
    
