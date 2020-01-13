// 그리디하게 투포인트 옮겨가면서 실행가능, O(N)
// 정렬이 되어있기 때문에

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	
	int N;
	cin >> N;
	vector<int> v(N);
	
	for(int i = 0; i < N; i++){
		cin >> v[i];
	}
	
	int i = 0, j = v.size()-1;
	int sum = 2e9;
	pair<int,int> result;
	
	while(i < j){
		int a = v[i];
		int b = v[j];
		if(abs(a+b) < sum){
			sum = abs(a+b);
			result.first = a;
			result.second = b;
		}
		if(a+b < 0){
			i++;
		}else if(a+b == 0){
			break;
		}else{
			j--;
		}
	}
	
	cout << result.first << " " << result.second << "\n";
	return 0;
} 
 
