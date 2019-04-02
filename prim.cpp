#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
typedef struct vertex vertex;
struct vertex{
    int number;
    int key;  //least weight edge that connects this vertex
              // to a vertex which is already in tree
};

class myComparator{
public:
    int operator() (const vertex &v1, const vertex &v2)
    {
        return (v1.key > v2.key);
    }
};
int v; //NUmber of vertices
void mst_prim(vector<vector<int>>&, vector<vector<int>>&, int, vertex[]);

int main(void){
    int x,y,z,root,i,j;
    printf("\nMinimum Spanning tree - Prim's Algorithm\n");
    printf("\nEnter number of vertices : "); scanf("%d",&v);
    vector<vector<int>> adj(v+1);
    vector<vector<int>> weight(v+1);
    printf("\nEnter edge and its weight(0 0 to end) : ");
    scanf("%d %d %d",&x,&y,&z);
    while(x!=0 && y!=0){
        adj[x].push_back(y);
        weight[x].push_back(z);
        printf("Enter edge and its weight(0 0 to end) : ");
        scanf("%d %d %d",&x,&y,&z);
    }

    vector<vector<int>> adj2(adj);
    vector<vector<int>> weight2(weight);
    for(i = 1; i <=v ; i++){
        for (j = 0; j < adj[i].size(); j++) {
            y = adj[i][j];
            z = weight[i][j];
            adj2[y].push_back(i);
            weight2[y].push_back(z);
        }
    }

    printf("\nEnter root vertex : ");
    scanf("%d",&root);
    vertex Vert[v+1];
    printf("\nMST is : ");
    mst_prim(adj2,weight2,root,Vert);
    //Some modifications required

    printf("\n\n");
    return 0;
}

void mst_prim(vector<vector<int>>&adj2, vector<vector<int>>&weight2, int root, vertex Vert[])
{
    int i,j,U,V;
    vertex tmp;
    for(i = 1; i <= v; i++){
        Vert[i].number = i;
        Vert[i].key = INT_MAX; //At infinity initially
    }
    Vert[root].key = 0;
    priority_queue <vertex, vector<vertex>, myComparator> Q; //MIN - HEAP
    int arr[v+1];
    for (i = 1; i <= v; i++)
        arr[i] = 1;
    for(i = 1; i <= v; i++)
        Q.push(Vert[i]);

    while(Q.empty() == false){
        tmp = Q.top(); Q.pop();
        U = tmp.number;
        printf("%d ",U);
        arr[U] = 0;
        for(i = 0; i < adj2[U].size(); i++){
            V = adj2[U][i];
            if( (arr[V]==1) && (weight2[U][i]<Vert[V].key) ){
                Vert[V].key = weight2[U][i];
                priority_queue <vertex, vector<vertex>, myComparator> Q1;
                for(j=1 ; j<=v ; j++){
                    if(arr[j]==1)
                        Q1.push(Vert[j]);
                }
                Q = Q1;
            }
        }
    }
}
