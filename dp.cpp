#include "header.h"
void printLCS(string X, vector<vector<int>>&b, int i, int j)
{
    if(i==0 || j==0)
        return;
    else if(b[i][j]==0){
        printLCS(X,b,i-1,j-1);
        printf("%c",X[i-1]);
    }else if(b[i][j]==1){
        printLCS(X,b,i-1,j);
    }else{
        printLCS(X,b,i,j-1);
    }
}
