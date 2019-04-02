//Implementing 01 KnapSack Dynamic Programming
//Complexity - O(nW)
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,W,i,j;
    printf("\n01 KnapSack Implementation(DP)\n");
    printf("\nEnter number of items : ");
    scanf("%d",&n);
    int wt[n+1],val[n+1];
    for(i = 0; i < n; i++){
        printf("Enter weight & value of item %d : ",i+1);
        scanf("%d %d",&wt[i+1],&val[i+1]);
    }
    printf("\nEnter capacity of KnapSack : ");
    scanf("%d",&W);
    int table[n+1][W+1];
    for(i = 0; i <= n; i++)
        table[i][0] = 0;
    for(j= 0; j <= W; j++)
        table[0][j] = 0;

    for(i = 1; i <= n; i++){
        for(j = 1; j <= W; j++){
            table[i][j]=0;
        }
    }

    for(i = 1; i <= n; i++){
        for(j = 1; j <= W; j++){
            if(wt[i] > j)
                table[i][j] = table[i-1][j];
            else
                table[i][j] = max(val[i]+table[i-1][j-wt[i]] , table[i-1][j]);
        }
    }
    printf("\n\nMax weight : %d\n",table[n][W]);
    printf("\nSelected Items - \n");;
    i = n; j = W;
    while(j>0 && i>0){
        if(table[i][j]!=table[i-1][j]){
            printf("\n%d - %d(%d)\n",i,wt[i],val[i]);
            j = j-wt[i];
        }
        i--;
    }

    printf("\n");
    return 0;
}
