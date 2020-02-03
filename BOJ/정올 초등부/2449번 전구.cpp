// Dp로 접근
// Dp[i][j] [i,j]구간에 있는 전구의 색을 하나로 만들기 위한 횟수의 최소값
 
#include <iostream>
#include <algorithm>

using namespace std;

int N,K, arr[200], Dp[200][200];
int main(void){
	
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < N; i++){
		for(int j = i; j < N; j++){
			Dp[i][j] = (i==j)? 0 : 1e9;
		}
	}
	for(int l = 2; l < N; l++){
		for(int i = 0; i < N-l+1; i++){
			int j = i + l -1;
			for(int k = i; k < j; k++){
				Dp[i][j] = min(Dp[i][j], Dp[i][k] + Dp[k+1][j] + (arr[i] != arr[k+1]));
			}
		}
	}
	
	cout << Dp[0][N] << "\n";
	return 0;
} 
