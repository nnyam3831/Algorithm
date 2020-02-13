#include <iostream>
#include <algorithm>
#define MAX 500 + 1
using namespace std;

// yÃþ x¹øÂ° 
int Dp[MAX][MAX];
int value[MAX][MAX];
int main(void){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cin >> value[i][j];
		}
	}
	Dp[1][1] = value[1][1];
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= i; j++){
			Dp[i][j] = max(Dp[i-1][j] + value[i][j], Dp[i-1][j-1] + value[i][j]);
		}
	}
	
	int Max = Dp[n][1];
	for(int i = 1; i <= n; i++){
		Max = max(Max, Dp[n][i]);
	}
	cout << Max << "\n";
	return 0;
}
