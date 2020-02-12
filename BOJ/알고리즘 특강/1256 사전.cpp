#include <iostream>
#include <algorithm>
#define MAX 200 + 1
using namespace std;

int Dp[MAX][MAX];
int N, M, K;

int main(void){
	
	cin >> N >> M >> K;
	for(int i = 0; i <= N+M; i++){
		Dp[i][0] = 1;
	}
	for(int i = 0; i <= N+M; i++){
		for(int j = 1; j <= i; j++){
			Dp[i][j] = min((Dp[i-1][j-1] + Dp[i-1][j]),(int)1e9);
		}
	}
	
	if(Dp[N+M][M] < K) cout << -1 << "\n";
	else{
		int total = N+M;
		for(int i = 0; i < total; i++){
			// N+M번의 출력
			if(Dp[N+M-1][M] < K){
				cout << "z";
				K -= Dp[N+M-1][M];
				M--;
			}else{
				cout << "a";
				N--;
			}
		}
	}
	return 0;
}
