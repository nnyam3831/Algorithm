#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int visited[51];
int max_cost;
vector<vector<pair<int,int>>> board(51);
bool cmp(const pair<int,int> &a, const pair<int,int> &b){
	return a.second < b.second;
}
void DFS(int index, int cost){
	sort(board[index].begin(), board[index].end());
	for(int i = 0; i < board[index].size(); i++){
		int next = board[index][i].first;
		int next_cost = board[index][i].second;
		if(cost + next_cost > max_cost) continue;
		if(visited[next] != 0) {
			if(visited[next] > cost+next_cost){
				visited[next] = cost+next_cost;
				DFS(next,cost+next_cost);
			}
			continue;
		};
		visited[next] = cost+next_cost;
		DFS(next, cost+next_cost);
	}
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
	max_cost = K;
	for(int i = 0; i < road.size(); i++){
	
		board[road[i][0]].push_back(make_pair(road[i][1] ,road[i][2]));	
		board[road[i][1]].push_back(make_pair(road[i][0] ,road[i][2]));	
	}
	visited[1] = 1;
	DFS(1, 0);
 	for(int i = 1; i <= N; i++){
 		if(visited[i] != 0) answer++;s
	}
    return answer;
}

int main(void){
	
//	solution(5, {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}}, 3);
	solution(6, {{1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1}},4);
	return 0;
}
