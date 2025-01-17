#include <stdio.h>
#include <stdlib.h>

int graph[10][10];
int visit[10];

void dfs(int node, int vertex)
{ 
    printf("%d\t", node);
    visit[node] = 1;
    for (int i = 1; i <= vertex; i++)
    {
        if (visit[i] == 0 && graph[node][i] == 1)
            dfs(i, vertex);
    }
}

void main()
{
    int e, v, v1, v2 , node;
    printf("Enter Number of vertex");
    scanf("%d", &v);
    printf("Enter Number of Edges");
    scanf("%d", &e);
    printf("Enter Edges");
    for (int i = 1; i <= e; i++)
    {
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = graph[v2][v1] = 1;
    }
    printf("Enter Starting Vertex");
    scanf("%d", &node);
    dfs(node, v);
}