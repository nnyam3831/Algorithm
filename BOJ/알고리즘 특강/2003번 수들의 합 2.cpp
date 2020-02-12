// while문 끝나는 조건 index 조심  

#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

int array[MAX];
int main(void){
	
	int N, M;
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		cin >> array[i];
	}
	
	int start = 0;
	int end = 0;
	int sum = array[start];
	int result = 0;
	while(1){
		if(start > N-1 || end > N-1) break;
		
		if(sum < M){
			end++;
			sum += array[end];
		}else if(sum > M){
			sum -= array[start];
			start++;
		}else{
			result++;
			sum -= array[start];
			start++;
			end++;
			sum += array[end];
		}
	}
	cout << result << "\n";
	return 0;
}
