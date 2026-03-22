#include<stdio.h>
#define MAX 50
int q1[MAX], q2[MAX];
int f1=0, r1=-1;
int f2=0, r2=-1;
void enqueue1(int x)
{
    r1++;
    q1[r1] = x;
}
void enqueue2(int x)
{
    r2++;
    q2[r2] = x;
}
int dequeue1()
{
    int x = q1[f1];
    f1++;
    return x;
}
int dequeue2()
{
    int x = q2[f2];
    f2++;
    return x;
}
int pop()
{
    if(f1>r1) return -1;
    while(f1<r1)
        enqueue2(dequeue1());
    int x = dequeue1();
    f1=0;
    r1=-1;
    for(int i = f2; i<=r2;i++)
        q1[++r1] = q2[i];
    f2=0;
    r2=-1;
    return x;
}
void push(int x){
    enqueue1(x);
}
int main()
{
    push(34);
    push(56);
    push(19);
    push(87);
    printf("Popped element is %d\n", pop());
    printf("Popped element is %d\n", pop());
}
