#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 최대 힙에 작은 값들  
priority_queue<int, vector<int>, less<int>> Max_Q; 
// 최소 힙에 큰 값들 
priority_queue<int, vector<int>, greater<int>> Min_Q;
int N;

int main(void){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	
	for(int i = 0; i < N; i++){
		int num;
		cin >> num;
		if(Max_Q.size() == Min_Q.size()){
			Max_Q.push(num);
		}else{
			Min_Q.push(num);
		}
		if(!Max_Q.empty() && !Min_Q.empty() &&(Max_Q.top() > Min_Q.top())){
			int temp1 = Max_Q.top();
			int temp2 = Min_Q.top();
			Max_Q.pop();
			Min_Q.pop();
			Max_Q.push(temp2);
			Min_Q.push(temp1);
		}
		cout << Max_Q.top() << "\n";
	}	
	return 0;
}
