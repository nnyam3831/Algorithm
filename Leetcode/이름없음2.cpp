#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_SIZE = 500 + 1;
const int INF = 1000000000;
vector<int> v[MAX_SIZE];
int inDegree[MAX_SIZE];
int cost[MAX_SIZE];
int acc[MAX_SIZE];
int n;

bool isAllDone(){
	bool ret = true;
	for(int i = 1; i <= n; i++){
		if (inDegree[i] != -1){
			ret = false;
			break;
		}
	}
	return ret;
}

int main(void){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> cost[i];
		while(1){
			int input;
			cin >> input;
			if(input == -1) break;
			v[input].push_back(i);
			inDegree[i] += 1;
		}
	}
	
	vector<int> result[n+1];
	while(1){
		for(int i = 1; i <= n; i++){
			if(!inDegree[i]){
				acc[i] += cost[i];
				for(int j = 0; j < v[i].size(); j++){
					int next = v[i][j];
					acc[next] = max(acc[next], acc[i]);
					inDegree[next]--;
				}
				inDegree[i] = -1;
			}
		}	
		if(isAllDone())	break;
	}
	for(int i = 1; i <= n; i++) cout << acc[i] << " ";
	cout << "\n";
	return 0;
}
