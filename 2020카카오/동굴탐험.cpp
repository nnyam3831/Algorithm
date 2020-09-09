#include <string>
#include <vector>
#include <iostream>
#include <map>

// O(N) DFS, Tree 
using namespace std;

const int MAX_SIZE = 200000 + 1;
int visited[MAX_SIZE];

void dfs(int index, vector<int> tree[], vector<int> &hang, map<int,int> &required){
	visited[index] = 1;
	if(hang[index] != 0) dfs(hang[index], tree, hang, required);
	for(int i = 0; i < tree[index].size(); i++){
		int child = tree[index][i];
		if(visited[child]) continue;
		int prev = required[child];
		if(visited[prev] == 0 && prev != 0){
			hang[prev] = child;
			continue;
		}
		dfs(child, tree, hang, required);
	}
}
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
	// make tree
	vector<int> tree[n];
	vector<int> hang(n);
	map<int, int> required;
	
	for(int i = 0; i < path.size(); i++){
		int first = path[i][0], second = path[i][1];
		tree[first].push_back(second);
		tree[second].push_back(first);
	}
	for(int i = 0; i < order.size(); i++){
		int next = order[i][0], prev = order[i][1];
		required[prev] = next;
	}
	if(required[0] != 0) return false;
	dfs(0, tree, hang, required);
	
	for(int i = 0; i < n; i++){
		if(visited[i] == 0){
			answer = false;
			break;
		}
	}
    return answer;
}
int main(void){
	return 0;
}
