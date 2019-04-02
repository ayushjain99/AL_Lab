#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
typedef struct vertex vertex;
struct vertex{
    int number;
    int colour; // 0 for white, 1 for gray, 2 for black
    int pred; // predecessor attribute
    int d; //distance from source
};
int V; //Number of Vertices
void BFS(vector<vector<int>>, vertex[], int);

int main(void)
{
    int x,y,s;
    printf("\nBFS Implementation\n");
    printf("\nEnter number of vertices : "); scanf("%d",&V);
    vector<vector<int>> adj(V+1);
    printf("\nEnter edge(enter 0 0 to end) : ");
    scanf("%d %d",&x,&y);
    while(x!=0 && y!=0){
        adj[x].push_back(y);
        printf("Enter edge(enter 0 0 to end) : ");
        scanf("%d %d",&x,&y);
    }
    printf("\nEnter source vertex : ");
    scanf("%d",&s);
    vertex Vert[V+1];
    printf("\nBFS traversal is : ");
    BFS(adj,Vert,s);

    printf("\n\n");
    for (int i = 1; i <= V; i++) {
        if(Vert[i].d == -1)
            printf("\nVertex %d cannot be reached from source.",i);
        else
            printf("\nVertex %d is at a distance of %d from source",i,Vert[i].d);
    }
    printf("\n\n");

    return 0;
}

void BFS(vector<vector<int>> adj, vertex Vert[], int s)
{
    int i,u,v;
    for (i = 1; i <= V; i++){
        Vert[i].number = i;
        Vert[i].colour = 0;
        Vert[i].pred = 0; // 0 stands for NIL
        Vert[i].d = -1; //Initially every vertex is at infinite distance from source
    }
    Vert[s].d = 0;
    Vert[s].colour = 1;
    queue <int> q; //We need a first in,first out queue
    q.push(s);

    while(!q.empty()){
        u = q.front(); //DEQUEUE
        q.pop();
        printf("%d ",u);
        for (i = 0; i < adj[u].size(); i++) {
            v = adj[u][i];
            if(Vert[v].colour == 0){
                Vert[v].colour = 1;
                Vert[v].d = Vert[u].d + 1;
                Vert[v].pred = u;
                q.push(v);   //ENQUEUE
            }
        }
        //Adjacency List scanning complete
        Vert[u].colour = 2;
    }
}
