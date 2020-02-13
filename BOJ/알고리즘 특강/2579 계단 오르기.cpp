#include <iostream>
#include <algorithm>
#define MAX 300 + 1
using namespace std;

int Dp[MAX];
int step[MAX];
int main(void){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> step[i];
	}
	
	if(N == 1){
		Dp[N] = step[1];
	}else if(N == 2){
		Dp[N] = step[1] + step[2];
	}
	else{
		Dp[1] = step[1];
		Dp[2] = step[1] + step[2];
		for(int i = 3; i <= N; i++){
			Dp[i] = max(Dp[i-2] + step[i], Dp[i-3] + step[i-1]+step[i]);
		}
	}
//	for(int i = 1; i <= N; i++){
//		cout << "#" << i << " " << Dp[i] << "\n";
//	}
	cout << Dp[N] << "\n";
	
	return 0;
}
