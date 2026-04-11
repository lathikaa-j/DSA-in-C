#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int adjM[MAX][MAX], visited[MAX];
int n;
struct node 
{
    int v;
    struct node *next;
};
struct node *adjL[MAX];
struct node* create(int val)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->v= val;
    newnode->next = NULL;
    return newnode;
}
void addEdge(int s, int d)
{
    adjM[s][d]= adjM[d][s]=1;
    struct node *newnode = create(d);
    newnode->next = adjL[s];
    adjL[s] = newnode;
    
    newnode = create(s);
    newnode->next = adjL[d];
    adjL[d] = newnode;
}
void DFS(int v)
{
    printf("%d  ", v);
    visited[v]=1;
    for(int i=0;i<n;i++)
    {
        if(adjM[v][i] && !visited[i])
            DFS(i);
    }
}
void BFS(int start)
{
    int q[MAX], f=0,r=0;
    q[r++]= start;
    visited[start]=1;
    
    while(f<r)
    {
        int v= q[f++];
        printf("%d  ", v);
        
        struct node* temp = adjL[v];
        while(temp!=NULL)
        {
            if(!visited[temp->v])
            {
                q[r++]= temp->v;
                visited[temp->v]= 1;
            }
            temp= temp->next;
        }
    }
}
void reset()
{
    for(int i=0;i<n;i++)
        visited[i]=0;
}
void pMatrix()
{
    for (int i=0; i<n;i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d  ", adjM[i][j]);
        }
        printf("\n");
    }
}
void pList()
{
    printf("Adjacency List\n");
    for(int i=0;i<n;i++)
    {
        printf("%d-> ", i);
        struct node *temp = adjL[i];
        while(temp!=NULL)
        {
            printf("%d-> ", temp->v);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    int ch, s,d,start;
    printf("Enter the number of vertices \n");
    scanf("%d", &n);
    
    for(int i=0;i<n;i++)
    {
        adjL[i]=NULL;
        for(int j=0; j<n;j++)
            adjM[i][j]=0;
    }
    printf("Enter 1 for add edge , 2 for DFS, 3 for BFS, 4 for display\n");
    while(1)
    {
        printf("Enter choice ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter edge (src, dest) ");
                scanf("%d %d", &s,&d);
                addEdge(s,d);
                break;
            case 2:
                reset();
                printf("Enter starting vertex ");
                scanf("%d", &start);
                printf("DFS\n");
                DFS(start);
                break;
            case 3:
                reset();
                printf("Enter starting vertex ");
                scanf("%d", &start);
                printf("BFS\n");
                BFS(start);
                break;
            case 4:
                printf("Adjacency Matrix\n");
                pMatrix();
                pList();
        }
    }
}
