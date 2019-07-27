//Longest Common Subsequence
//Dynamic Programming
#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int LCS(string A, string B, vector<vector<int>>& v);
void printLCS(vector<vector<int>>& v, string s1, int i, int j);

int main(void) {
	int t,A,B,ans;
	string s1,s2;
	cin >> t;
	while(t--){
	   cin >> A >> B;
	   cin >> ws;
       getline(cin,s1); cin >> ws;
       getline(cin,s2);
       vector<vector<int>> v(A+1,vector<int>(B+1,0));
       ans = LCS(s1,s2,v);
       std::cout << "Length of LCS : " << ans << '\n';
       std::cout << "LCS is : ";
       printLCS(v,s1,A,B);
       std::cout << '\n';
	}

	return 0;
}

int LCS(string A, string B, vector<vector<int>>& v){
    int m = A.length();
    int n = B.length();
    // std::cout << m << " " << n << '\n';
    int dp[m+1][n+1];

    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;

    for (int j = 0; j<= n; j++)
        dp[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(A[i-1] == B[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                v[i][j] = 0;    // 0 for diagonal arrow
            }else if( dp[i-1][j] >= dp[i][j-1] ){
                dp[i][j] = dp[i-1][j];
                v[i][j] = 1; // 1 for up arrow
            }else{
                dp[i][j] = dp[i][j-1];
                v[i][j] = 2; // 2 for left arrow
            }
        }
    }

    return dp[m][n];
}

void printLCS(vector<vector<int>>& v, string s1, int i, int j){
    if(i==0 || j==0)
        return;

    if(v[i][j] == 0){
        printLCS(v,s1,i-1,j-1);
        printf("%c",s1[i-1]);
    }else if(v[i][j] == 1){
        printLCS(v,s1,i-1,j);
    }else{
        printLCS(v,s1,i,j-1);
    }
}
