#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
void LCS(string, string, vector<vector<int>>&, vector<vector<int>>&);
void printLCS(string, vector<vector<int>>&, int, int);
int brute_force(string, string, int, int);
