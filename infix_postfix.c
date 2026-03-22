#include<stdio.h>
#include<ctype.h>
#define MAX 100
int top=-1;
char stack[MAX];
void push(char x)
{
    top++;
    stack[top] = x;
}
char pop()
{
    char x;
    x= stack[top];
    top--;
    return x;
}
int priority(char ch)
{
    if(ch== '+' || ch== '-' ) return 1;
    if(ch== '*' || ch== '/' ) return 2;
    if(ch== '^') return 3;
    return 0;
}
int main()
{
    char infix[MAX], postfix[MAX];
    int i =0, j=0;
    char ch;
    printf("Enter infix expression ");
    scanf("%s", infix);
    while((ch=infix[i++])!='\0')
    {
        if(isalnum(ch))
            postfix[j++]= ch;
        else if(ch =='(')
            push(ch);
        else if(ch== ')')
        {
            while(top != -1 && stack[top]!='(')
                postfix[j++]= pop();
            pop();
        }
        else
        {
            while(top!=-1 && priority(stack[top])>= priority(ch))
                postfix[j++]= pop();
            push(ch);
        }
    }
    while(top!=-1)
        postfix[j++] = pop();
    postfix[j]='\0';
    printf("Postfix expression is %s", postfix);
}
