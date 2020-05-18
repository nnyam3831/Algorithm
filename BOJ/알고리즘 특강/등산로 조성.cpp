#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#define INF 987654321
using namespace std;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int map[9][9];
int visited[9][9];
int K, T, N;
// DFS Simulation
int DFS(int y, int x){
	if(y < 1 || y > N || x < 1 || x > N) return 0;
//	cout << y << " " << x << "\n";
	visited[y][x] = 1;
	int ret = 1;
	for(int dir = 0; dir < 4; dir++){
		int nextY = y + dy[dir];
		int nextX = x + dx[dir];
		if(visited[nextY][nextX] == 0 && map[y][x] > map[nextY][nextX]){
			ret = max(ret, DFS(nextY, nextX) + 1);
		}
	}
	visited[y][x] = 0;
	return ret;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for(int test = 1; test <= T; test++){
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		cin >> N >> K;
		int max_h = 0;
		for(int y = 1; y <= N; y++){
			for(int x = 1; x <= N; x++){
				cin >> map[y][x];
				max_h = max(max_h, map[y][x]);
			}
		}
		vector<pair<int,int>> start;
		for(int y = 1; y <= N; y++){
			for(int x = 1; x <= N; x++){
				if(map[y][x] == max_h){
					start.push_back(make_pair(y, x));	
				}
			}
		}
		int result = 0;
		for(int i = 0; i < start.size(); i++){
			for(int offset = 1; offset <= K; offset++){
				for(int y = 1; y <= N; y++){
					for(int x =1; x <= N; x++){
						if(map[y][x] >= offset){
							map[y][x] -= offset;
							result = max(result,DFS(start[i].first, start[i].second));
							map[y][x] += offset;
						}
					}
				}
			}
		}
		cout << "#" << test << " " << result << "\n";
	}
	return 0;
}
