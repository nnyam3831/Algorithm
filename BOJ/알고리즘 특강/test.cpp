#include <iostream>
#include <queue>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int, vector<int>, less<int>> pq;
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		int data;
		cin >> data;
		if(data == 0){
			pq.empty() ? cout << 0 << "\n" : cout << pq.top() << "\n";
			if(!pq.empty()) pq.pop();
		}else{
			
			pq.push(data);
		}
	}
	return 0;
}
