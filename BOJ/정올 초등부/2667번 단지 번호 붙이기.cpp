#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 30

using namespace std;

int visited[MAX][MAX];
char map[MAX][MAX];

int index, N;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
void BFS(int y, int x){
	if(visited[y][x] != 0 || map[y][x] == '0'){
		return;
	}
	index++;
	visited[y][x] = index;
	queue<pair<int,int>> q;
	q.push(make_pair(y, x));
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		// 4¹æÇâ Å½»ö 
		for(int dir = 0; dir < 4; dir++){
			
			int nextY = y + dy[dir];
			int nextX = x + dx[dir];
			if(nextY >= N || nextY < 0 || nextX >= N || nextX < 0) continue;
			if(visited[nextY][nextX] != 0) continue;
			if(map[nextY][nextX] == '1' && visited[nextY][nextX] == 0){
				visited[nextY][nextX] = index;
				pair<int,int> next;
				next.first = nextY;
				next.second = nextX;
				q.push(next);
			}
			
		}
		
	}
}
int main(void){
		
	
	cin >> N;
	for(int y = 0; y < N; y++){
		cin >> map[y];
	}
	
	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			BFS(y, x);
		}
	}
	
	
	vector<int> v(index);
	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			if(visited[y][x] != 0){
				v[visited[y][x]-1]++;
			}
		}
	}	
	sort(v.begin(), v.end());
	
	cout << index << "\n";
	for(int i = 0; i < index; i++){
		cout << v[i] << "\n";
	}
	return 0;
}
