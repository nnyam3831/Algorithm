#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>
#define MAX 100

using namespace std;

int map[MAX][MAX];
int visited[MAX][MAX];
int state[MAX][MAX];
int minRain = 2e9;
int maxRain = -1;
int result = 0;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int main(void){
	
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> map[i][j];
			minRain = min(minRain, map[i][j]);
			maxRain = max(maxRain, map[i][j]);
		}
	}
	
	// minRain ~ maxRain 반복문
	for(int h = minRain-1; h <= maxRain; h++){
		memset(visited,0, sizeof(visited));
		int index = 0;
		for(int y = 0; y < N; y++){
			for(int x = 0; x < N; x++){
				if(map[y][x] <= h){
					visited[y][x] = -1;
				} 
			}
		}
		// BFS로 index mapping
		for(int y = 0; y < N; y++){
			for(int x = 0; x < N; x++){
				if(visited[y][x] != 0) continue;
				if(visited[y][x] == 0){
					index++;
					visited[y][x] = index;
				}
				queue<pair<int,int>> q;
				q.push(make_pair(y,x));
				while(!q.empty()){
					int curY = q.front().first;
					int curX = q.front().second;
					
					q.pop();
					for(int dir = 0; dir < 4; dir++){
						int nextY = curY + dy[dir];
						int nextX = curX + dx[dir];
						if(nextY >= N || nextY < 0 || nextX >= N || nextX < 0) continue;
						if(visited[nextY][nextX] == 0){
							visited[nextY][nextX] = index;
							q.push(make_pair(nextY,nextX));
						}
					}
				}
			}
		}
		if(result < index) result = index;
	} 
	 
	cout << result << "\n";
	
	return 0;
}
