//Dijkstra Implementation, O(ElogV)
//Ayush Jain
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
typedef struct vertex vertex;
struct vertex{
    int number;
    int d; //Shortest Path Estimate
    int pred; //Predecessor Attribute
};

class myComparator{
public:
    int operator() (const vertex &v1, const vertex &v2)
    {
        return (v1.d > v2.d);
    }
};

int v;
void dijkstra(vector<vector<int>>&, vector<vector<int>>&, vertex*, int);

int main(void){
    int x,y,z,i;
    printf("\nDijkstra Single Source Shortest Paths\n");
    printf("\nEnter number of vertices : "); scanf("%d",&v);
    vector<vector<int>> adj(v+1);
    vector<vector<int>> weight(v+1);
    printf("\nEnter edge and its weight(0 0 0 to end) : ");
    scanf("%d %d %d",&x,&y,&z);
    while(x!=0 && y!=0){
        adj[x].push_back(y);
        weight[x].push_back(z);
        printf("Enter edge and its weight(0 0 0 to end) : ");
        scanf("%d %d %d",&x,&y,&z);
    }

    int source;
    printf("\nEnter source vertex : ");
    scanf("%d",&source);
    vertex Vert[v+1];
    dijkstra(adj,weight,Vert,source);

    printf("\nShortest Path Estimates and Predecessors : \n");
    for(i = 1; i <= v; i++)
        printf("\nVertex %d - %d , %d",i,Vert[i].d,Vert[i].pred);


    printf("\n\n");
    return 0;
}

void dijkstra(vector<vector<int>>&adj, vector<vector<int>>&w, vertex* Vert, int s)
{
    int i,j,k,U,V;
    vertex tmp;
    for(i = 1; i <= v; i++){
        Vert[i].number = i;
        Vert[i].d = INT_MAX; //Infinity
        Vert[i].pred = 0;
    }
    Vert[s].d = 0;
    priority_queue <vertex, vector<vertex>, myComparator> Q; //MIN - HEAP

    for(i = 1; i <= v; i++)
        Q.push(Vert[i]);

    while(Q.empty() == false){
        tmp = Q.top(); Q.pop();
        U = tmp.number;
        for(i = 0; i < adj[U].size(); i++){
            V = adj[U][i];
            if(Vert[U].d == INT_MAX)
                continue;
            //printf("\n%d %d %d %d %d",U,V,Vert[U].d,Vert[V].d,w[U][i]);
            if( Vert[V].d > (Vert[U].d + w[U][i]) ){
                Vert[V].d = Vert[U].d + w[U][i];
                Vert[V].pred = U;
            }
        }
    }
}
