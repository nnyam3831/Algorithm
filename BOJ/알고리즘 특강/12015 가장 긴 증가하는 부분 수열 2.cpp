#include <iostream>
#include <algorithm>
#define MAX 1000000 + 1
using namespace std;

int LIS[MAX];
int input[MAX];
int N,Pos;

int _lower_bound(int s, int e, int array[], int target){
	// binary search로 logN  
	int mid;
	while(s != e){
		mid = (s+e)/2;
		if(LIS[mid] >= target){
			e = mid;
		}else{
			s = mid + 1;
		}
	}
	return e;
}
int main(void){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> input[i];
	}
	int start = 0;
	for(int i = 0; i < N; i++){
		if(start < input[i]){
			// 넣어줌 
			LIS[Pos++] = input[i];
		}else{
			// lower bound() gogo 
			int index = _lower_bound(0, Pos, LIS, input[i]);
			LIS[index] = input[i];
			// LIS의 길이는 변하지 않음
			// 결국 마지막엔 Pos의 길이가 정답 
		}
		start = LIS[Pos-1];
//		for(int j = 0; j < Pos; j++){
//			cout << LIS[j] << " ";
//		}
//		cout << "\n";
	}
	cout << Pos << "\n";
	return 0;
}


