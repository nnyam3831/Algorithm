#include <iostream>
#include <algorithm>

using namespace std;

int array[100001];

int main(void){
	
	int N, K;
	cin >> N >> K;
	for(int i = 0; i < N; i++){
		cin >> array[i];
	}
	
	int sum = 0;
	for(int i = 0; i < K; i++){
		sum += array[i];
	}
	int result = sum;
	for(int i = 1; i <= N-K; i++){
		sum = sum - array[i-1]+array[i+K-1];
		result = max(result, sum);
	}
	
	cout << result << "\n";
	
	return 0;
} 
