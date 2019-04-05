//Longest Common Subsequence, Dynamic Programming
#include "header.h"
int m,n;
int main(void){
    string X,Y;
    clock_t start,stop; double t;
    printf("\nLongest Common Subsequence\n");
    printf("\nEnter sequence X : ");
    cin >> X;
    printf("\nEnter sequence Y : ");
    cin >> Y;

    m = X.length();
    n = Y.length();
    vector<vector<int>> c(m+1,vector<int>(n+1,0));
    vector<vector<int>> b(m+1,vector<int>(n+1,0));

    start = clock();
    LCS(X,Y,c,b);
    stop = clock();
    t = ((double)(stop-start))/CLOCKS_PER_SEC;
    printf("\nC-Table is : \n");
    for (int i = 1; i <= m ; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }

    printf("\nB-Table is : \n");
    for (int i = 1; i <= m ; i++) {
        for (int j = 1; j <= n; j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }

    printf("\nLCS is : ");
    printLCS(X,b,m,n);
    printf("\nTime taken through DP : %lf",t);
    printf("\n\nBy Brute Force");
    start = clock();
    printf("\nLength = %d",brute_force(X,Y,m,n));
    stop = clock();
    t = ((double)(stop-start))/CLOCKS_PER_SEC;
    printf("\nLCS is : ");
    printLCS(X,b,m,n);
    printf("\nTime taken by Brute Force : %lf",t);
    printf("\n\n");

    return 0;
}

void LCS(string X, string Y, vector<vector<int>>&c , vector<vector<int>>&b)
{
    int i,j;
    for(int i = 1; i <= m; i++)
        c[i][0] = 0;

    for(int j = 0; j <= n; j++)
        c[0][j] = 0;

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if(X[i-1] == Y[j-1]){
                c[i][j] = 1 + c[i-1][j-1];
                b[i][j] = 0; //Using 0 for diagonal arrow

            }else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 1; //Using 1 for up arrow

            }else{
                c[i][j] = c[i][j-1];
                b[i][j] = 2; //Using 2 for left arrow
            }
        }
    }
}
