#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int graph[MAX][MAX] = {0};
int visit[MAX] = {0};

struct queue {
    int fr;
    int rr;
    int a[MAX];
};

int queueempty(struct queue *q) {
    return (q->fr == -1 || q->fr > q->rr);
}

void enqueue(struct queue *q, int node) {
    if (q->rr == MAX - 1) {
        printf("Overflow\n");
        return;
    }

    q->rr++;
    q->a[q->rr] = node;
}

int dequeue(struct queue *q) {
    int node;
    if (queueempty(q)) {
        printf("Underflow\n");
        return 0;
    }
    node = q->a[q->fr];
    q->fr++;
    return node;
}

void bfs(int start, int vertex) {
    struct queue q;
    q.fr = 0;
    q.rr = -1;
    int cn,i;
    visit[start]=1;
    enqueue(&q,start);

    while(!queueempty(&q)){
        cn=dequeue(&q);
        printf("%d\t",cn);

        for(i=1;i<=vertex;i++){
            if(visit[i]==0 && graph[cn][i]==1 ){
            enqueue(&q,i);
            visit[i]=1;
            }
        }
    }
}

int main() {
    int e, v, v1, v2, start;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (v1 v2):\n");
    for (int i = 1; i <= e; i++) {
        scanf("%d %d", &v1, &v2);
        graph[v1][v2] = graph[v2][v1] = 1;
    }
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    bfs(start, v);
    return 0;
}
