// 0 index부터 n index까지의 구간합
#include <iostream>
#include <algorithm>
#define MAX 100000+1
using namespace std; 

int Sum[MAX];
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		int x;
		cin >> x;
		Sum[i] = Sum[i-1] + x;
	}
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		if(a > b) swap(a,b);
		cout << Sum[b]-Sum[a-1] << "\n";
	}
	return 0;
}
