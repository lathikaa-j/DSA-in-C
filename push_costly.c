#include<stdio.h>
#define MAX 100
int f1=0, r1=-1,f2=0,r2=-1;
int q1[MAX], q2[MAX];
void enqueue1(int x)
{
    r1++;
    q1[r1]= x;
}
void enqueue2(int x)
{
    r2++;
    q2[r2]= x;
}
int dequeue1()
{
    if(f1>r1)
        return -1;
    int x= q1[f1];
    f1++;
    return x;
}
int dequeue2()
{
    if(f2>r2)
        return -1;
    int x= q2[f2];
    f2++;
    return x;
}
void push(int x)
{
    enqueue2(x);
    while(f1<=r1)
        enqueue2(dequeue1());
    f1=0;
    r1=-1;
    for(int i = f2; i<= r2; i++)
    {
        q1[++r1] = q2[i];
    }
    f2=0;
    r2=-1;
}
int pop()
{
    if(f1>r1)
        return -1;
    return dequeue1();
}
void display()
{
    if(f1<=r1)
    {
        for(int i = f1; i<=r1; i++)
            printf("%d  ", q1[i]);
    }
}
int main()
{
    int ch,x;
    printf("Enter 1 for push costly , 2 for pop, 3 for display \n");
    while(1)
    {
        printf("Enter choice \n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: 
                printf("Enter value to push \n");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                int val = pop();
                printf("Popped element is %d\n", val);
                break;
            case 3:
                display();
                break;
        }
    }
}


