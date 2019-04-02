#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct vertex vertex;
struct vertex{
    int number;
    int colour; // 0 for white, 1 for gray, 2 for black
    int d; //discovery time
    int f; //finish time
};
int time_var = 0,v; // Small v denotes number of vertices
vector<int> linked;

void DFS(vector<vector<int>>, vertex[]);
void DFS_VISIT(vector<vector<int>> , vertex[], int);

int main(void)
{
    int x=1,y=1;
    printf("\nTopological Sort\n");
    printf("\nEnter number of vertices : "); scanf("%d",&v);
    vector<vector<int>> adj(v+1);
    printf("\nEnter edge(enter 0 0 to end) : ");
    scanf("%d %d",&x,&y);
    while(x!=0 && y!=0){
        adj[x].push_back(y);
        printf("Enter edge(enter 0 0 to end) : ");
        scanf("%d %d",&x,&y);
    }
    vertex Vert[v+1];
    DFS(adj,Vert);

    printf("\n\nFinishing times are as follows\n");
    for (int i = 1; i <=v; i++)
        printf("Vertex %d -> %d\n",i,Vert[i].f);

    printf("\nTopological Sort Order is : ");
    for (int i = 0; i < linked.size(); i++) {
        printf("%d ",linked[i]);
    }
    printf("\n\n");

    return 0;
}

void DFS(vector<vector<int>> adj, vertex Vert[])
{
    int i;
    for (i = 1; i <= v; i++) {
        Vert[i].number = i;
        Vert[i].colour = 0;
    }

    for (i = 1; i <= v; i++) {
        if(Vert[i].colour == 0)
            DFS_VISIT(adj,Vert,i);
    }
}

void DFS_VISIT(vector<vector<int>> adj , vertex Vert[], int u)
{
    time_var = time_var + 1;
    Vert[u].d = time_var;
    Vert[u].colour = 1 ; //Gray it

    int v;
    for (int i = 0; i < adj[u].size(); i++) {
        v = adj[u][i];
        if(Vert[v].colour == 0){
            DFS_VISIT(adj,Vert,v);
        }
    }

    time_var = time_var + 1;
    Vert[u].f = time_var;    //We have completely examined adj list of u.
    Vert[u].colour = 2;  //So blacken it.
    linked.insert(linked.begin(),u);
}
