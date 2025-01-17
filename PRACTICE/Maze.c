#include<stdio.h>
#include<stdbool.h>
#define n 4

bool issafe(int maze[n][n],int x,int y){
    return (x>=0 && y>=0 && x<n && y<n && maze[x][y]==1);
}

bool checkmaze(int maze[n][n],int x,int y,int sa[n][n]){
    if(x==n-1 && y==n-1){
        sa[x][y]=1;
        return true;
    }

    if(issafe(maze,x,y)){
        sa[x][y]=1;

        if(checkmaze(maze,x,y+1,sa)){
            return true;
        }
        if(checkmaze(maze,x+1,y,sa)){
            return true;
        }
        sa[x][y]=0;
        return false;
    }
    return false;
}

void printsoln(int sa[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        printf(" %d ",sa[i][j]);
        printf("\n");
    }
}

bool solnarr(int maze[n][n]){
    int sa[n][n]={{0,0,0,0},
                  {0,0,0,0},
                  {0,0,0,0},
                  {0,0,0,0}};
                  
    if(!checkmaze(maze,0,0,sa)){
        printf("Solution Doesn't Exist\n");
        return false;
    }
    printsoln(sa);
    return true;
}

int main()
{
    int maze[n][n];
    printf("Enter Maze\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        scanf("%d",&maze[i][j]);
    }
    solnarr(maze);
    return 0;
}