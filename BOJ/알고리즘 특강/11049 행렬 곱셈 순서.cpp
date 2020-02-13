#include <iostream>
#include <algorithm>
#include <memory.h>
#include <limits.h>
#define MAX 500 + 1
using namespace std;
int Mat[MAX][2];
int Dp[MAX][MAX];
int DFS(int start, int end){
	if(Dp[start][end] != -1) return Dp[start][end];
	Dp[start][end] = INT_MAX;
	
	for(int i = start; i < end; i++){
		Dp[start][end] = min(Dp[start][end], (DFS(start, i) + DFS(i+1, end) + Mat[start][0]*Mat[i][1]*Mat[end][1]));
	}
	return Dp[start][end];
}
int main(void){
	int N;
	cin >> N;
	
	memset(Dp, -1, sizeof(Dp));
	for(int i = 1; i <= N; i++){
		cin >> Mat[i][0] >> Mat[i][1];
		Dp[i][i] = 0;
	}
	
	
	cout << DFS(1, N) << "\n";
	return 0;
}
