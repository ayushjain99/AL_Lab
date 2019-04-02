#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
void matrix_chain_order(vector<int>&, vector<vector<int>>&, vector<vector<int>>&);
void matrix_chain_multiply(vector<vector<int>>&, int, int);

int main(void){
    int n,x,y;
    printf("\nMATRIX CHAIN MULTIPLICATION\n");
    printf("\nEnter number of matrices : ");
    scanf("%d",&n);
    std::vector<int> p(n+1);
    printf("Enter dimensions of matrix %d : ",1);
    scanf("%d %d",&x,&y);
    p[0]=x; p[1]=y;
    for (int i = 2; i <= n; i++) {
        printf("Enter dimensions of matrix %d : ",i);
        scanf("%d %d",&x,&y);
        if(x != p[i-1]){
            printf("\nIncompatible for multiplication..Try Again\n");
            exit(1);
        }
        p[i] = y;
    }
    std::vector<std::vector<int>> m(n+1,std::vector<int>(n+1));
    std::vector<std::vector<int>> s(n+1,std::vector<int>(n+1));
    matrix_chain_order(p,m,s);
    printf("\nMinimum scalar multiplications necessary are : %d\n",m[1][n]);
    printf("\nOrder of multiplication is : ");
    matrix_chain_multiply(s,1,n);

    printf("\n\n");
    return 0;
}

void matrix_chain_order(vector<int>&p, vector<vector<int>>&m, vector<vector<int>>&s)
{
    int n = p.size()-1;
    for(int i = 1; i <= n; i++)
        m[i][i]=0;

    int i,j,l,k,q;
    for(l = 2; l <= n ; l++){
        for (i = 1; i <= n-l+1; i++) {
            j = i+l-1;
            m[i][j] = INT_MAX;
            for(k = i; k <= j-1; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void matrix_chain_multiply(vector<vector<int>>&s, int i, int j)
{
    if(i==j){
        printf("A%d",i);
        return;
    }
    printf("(");
    matrix_chain_multiply(s,i,s[i][j]);
    printf("*");
    matrix_chain_multiply(s,s[i][j]+1,j);
    printf(")");
}
