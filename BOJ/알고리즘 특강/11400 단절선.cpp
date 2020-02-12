#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000+1
using namespace std;

int discover[MAX];
vector<int> node[MAX];
vector<pair<int,int>> result;
int V,E,cnt;
int DFS(int index, int parent){
	discover[index] = ++cnt;
	int ret = discover[index];
	
	for(int j = 0; j < node[index].size(); j++){
		int next = node[index][j];
		if(parent == next) continue;
		if(discover[next]){
			ret = min(ret, discover[next]);
			continue;
		}
		int prev = DFS(next, index);
		if(prev > discover[index]){
			// 얘가 단절선임
			result.push_back(make_pair(min(index, next), max(index, next)));
		}
		ret = min(ret, prev);
	}
	return ret;
}
int main(void){
	cin >> V >> E;
	for(int i = 0; i < E; i++){
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}
	for(int i = 1; i <= V; i++){
		if(!discover[i]) DFS(i, 0);
	}
	sort(result.begin(), result.end());
	cout << result.size() << "\n";
	for(int i = 0; i < result.size(); i++){
		cout << result[i].first << " " << result[i].second << "\n";
	}
	return 0;
}
