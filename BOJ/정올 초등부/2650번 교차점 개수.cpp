#include <iostream>
#include <vector>
#include <queue>
#define MAX 52

using namespace std;

int Length;
int N;
int A[MAX];
int T[MAX];
int V[MAX];
int Min = 10000000;

void DFS(int n, int sum){
	// n 이 N이면 종료
	if(n >= N+1){
		if(sum < Min) Min = sum;
		return;
	} 
	// 현재까지 구한시간이 더 크면 종료함
	if(sum > Min) return;
	
	for(int i = 1; i <= N+1; i++){
		if(V[i] == 1) continue;
		if(A[i] - A[n] <= Length){
			V[i] = 1;
			DFS(i, sum+T[i]);
			V[i] = 0;
		}
	} 
}

int main(void){
	
	cin >> Length;
	cin >> N;
	for(int i = 1; i <= N+1; i++){
		int temp;
		cin >> temp;
		A[i] += (A[i-1]+temp);
	}
	for(int i = 1; i <= N; i++){
		cin >> T[i];
	}
	DFS(0,0);
	cout << Min << "\n";
	return 0;
}
