// 백준 2042 인덱스 트리 
#include <iostream>
#include <algorithm>
#define MAX 4000000 + 1
using namespace std;

long long input[1000001];
int N, M, K;
long long tree[MAX];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> K;
	for(int i = 0; i < N; i++){
		cin >> input[i];
	}
	// 트리 만들기
	int startIndex = 1;
	// N보다 큰 가장 작은 2의 제곱수  
	while(startIndex < N){
		startIndex *= 2;
	} 
	for(int i = startIndex; i < startIndex + N; i++){
		// 맨 밑에 깔기 
		tree[i] = input[i-startIndex];
	}
	for(int i = startIndex-1; i >= 1; i--){
		tree[i] = tree[2*i] + tree[2*i+1];
	} 
	
	for(int i = 0; i < M+K; i++){
		long long a, b, c;
		cin >> a >> b >> c;
		if(a == 1){
			// b를 c로 변경(logN으로 다시 갱신) 
			int curIndex = startIndex + b - 1;
			long long before = tree[curIndex];
			while(curIndex > 0){
				tree[curIndex] = tree[curIndex] - before + c;
				curIndex /= 2;
			}
		}else{
			// b부터 c까지 합(logN) 
			int left = startIndex + b - 1;
			int right = startIndex + c - 1;
			if(left > right) swap(left, right);
			long long sum = 0;
			while(left < right){
				if(left % 2 == 1){
					sum += tree[left];
					left++;
					continue;
				}
				if(right % 2 == 0){
					sum += tree[right];
					right--;
					continue;
				}
				left /= 2;
				right /= 2;
			}
			sum += tree[left];
			cout << sum << "\n";
		}
	}
	return 0;
}
