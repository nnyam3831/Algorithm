#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1000+1
using namespace std;

// x,y를 우하단으로하는 정사각형 중 가장 작은 거 
int Dp[MAX][MAX];
int main(void){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char c;
			cin >> c;
			Dp[i][j] = c-'0';
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(Dp[i][j]){
				Dp[i][j] = min(Dp[i-1][j-1], min(Dp[i-1][j], Dp[i][j-1])) + 1;
				ans = max(ans, Dp[i][j]);
			}
		}
	}
	cout << ans*ans << "\n";
	return 0;
}
