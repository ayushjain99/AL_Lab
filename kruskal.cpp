//Implementing Kruskal's MST Algorithm
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
int v; //No. of vertices

bool sortcol(const vector<int>&v1, const vector<int>&v2)
{
  return (v1[2]<v2[2]);
}

int main(void){
  int x,y,z,root,i,j;
  printf("\nMinimum Spanning tree - Kruskal's Algorithm\n");
  printf("\nEnter number of vertices : "); scanf("%d",&v);
  vector<vector<int>> edges;
  vector<int> tmp(3);
  printf("\nEnter edge and its weight(0 0 0 to end) : ");
  scanf("%d %d %d",&x,&y,&z);
  while(x!=0 && y!=0){
      tmp[0] = x; tmp[1] = y; tmp[2] = z;
      edges.push_back(tmp);
      printf("Enter edge and its weight(0 0 0 to end) : ");
      scanf("%d %d %d",&x,&y,&z);
  }

  sort(edges.begin(),edges.end(),sortcol);

  int set[v+1];
  for(i=1 ; i<=v ; i++)
    set[i] = i; //MAKE-SET(v)

  vector<vector<int>> tree;
  vector<int> tmp2(2);
  int ttt,yyy;
  for (i = 0; i < edges.size(); i++){
    x = edges[i][0];
    y = edges[i][1];
    z = edges[i][2];
    if(set[x] != set[y]){
      tmp2[0] = x; tmp2[1] = y;
      tree.push_back(tmp2);
      ttt = set[x]; yyy = set[y];
      for (j = 1; j <= v; j++){
          if(set[j]==ttt || set[j]==yyy)
            set[j]=ttt;
      }
    }
  }

  printf("\nThe edges in MST are : \n");
  for(i = 0; i < tree.size(); i++)
    printf("%d %d\n",tree[i][0],tree[i][1]);

  return 0;
}
