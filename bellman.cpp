//Bellman Ford Implementation, O(VE)
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
int v;

bool Bellman(vector<vector<int>>&, vector<vector<int>>&, vertex*, int);

int main(void){
    int x,y,z,i;
    printf("\nBellman Ford Single Source Shortest Paths\n");
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
    int check = Bellman(adj,weight,Vert,source);

    if(check == 1){
        printf("\nShortest Path Estimates and Predecessors : \n");
        for(i = 1; i <= v; i++)
            printf("\nVertex %d - %d , %d",i,Vert[i].d,Vert[i].pred);
    }else{
        printf("\nThere is a -ve weight cycle reachable from source");
        printf("\nSo, NO Solution");
    }

    printf("\n\n");
    return 0;
}

bool Bellman(vector<vector<int>>&adj, vector<vector<int>>&w, vertex* Vert, int s)
{
    int i,j,k,U,V;
    for(i = 1; i <= v; i++){
        Vert[i].number = i;
        Vert[i].d = INT_MAX; //Infinity
        Vert[i].pred = 0;
    }
    Vert[s].d = 0;

    for (i = 1; i <= v-1; i++){
        //Relax each edge |V|-1 times
        for(j = 1; j <= v; j++){
            U = j;
            for(k = 0; k < adj[j].size(); k++){
                V = adj[j][k];
                if(Vert[U].d == INT_MAX)
                    continue;
                if( Vert[V].d > (Vert[U].d + w[j][k]) ){
                    Vert[V].d = Vert[U].d + w[j][k];
                    Vert[V].pred = U;
                }
            }
        }
    }
    //Check for -ve wt cycle reachable from source
    for(j = 1; j <= v; j++){
        U = j;
        for(k = 0; k < adj[j].size(); k++){
            V = adj[j][k];
            if( Vert[V].d > (Vert[U].d + w[j][k]) ){
                return false;
            }
        }
    }
    
    return true;
}
