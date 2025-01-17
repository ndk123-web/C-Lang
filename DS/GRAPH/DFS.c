#include<stdio.h>
#include<stdlib.h>

int adj[10][10];
int visit[10];

int dfs(int node,int v)
{
    int i;
    visit[node]=1;
    printf("%d\t",node);
    for(i=1;i<=v;i++)
    {
        if(adj[node][i]==1 && visit[i]==0)
        dfs(i,v);
    }
}

void main()
{
    int v,e,v1,v2,node;
    printf("Enter Number of vertex\n");
    scanf("%d",&v);
    printf("Enter number of edges\n");
    scanf("%d",&e);
    
    printf("Enter edges\n");
    for( int i=1;i<=e;i++)
    {
        scanf("%d %d",&v1,&v2);
        adj[v1][v2]=adj[v2][v1]=1;
    }
    printf("Enter starting vertex\n");
    scanf("%d",&node);
    dfs(node,v);
}