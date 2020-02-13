#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000+1
using namespace std;

vector<int> LIS;
int input[MAX];
int main(void){
	int N;
	cin >> N;
	int start = 0;
	for(int i = 0; i < N; i++){
		int num;
		cin >> num;
		if(num > start){
			// 크면 넣어주면 됨.. 증가 수열  
			LIS.push_back(num);
		}else{
			// 그게 아니면 처음부터 끝까지 찾음
			int size = LIS.size();
			int index = 0;
			for(int j = 0; j < size; j++){
				if(num <= LIS[j]){
					// 처음으로 작거나 같아지는 곳에 넣음 
					LIS[j] = num;
					break;
				}
			} 
		}
		start = LIS[LIS.size()-1];
//		for(int k = 0; k < LIS.size(); k++){
//			cout << LIS[k] << " ";
//		}
//		cout << "\n";
	}
	
	cout << LIS.size() << "\n";
	
	return 0;
}
