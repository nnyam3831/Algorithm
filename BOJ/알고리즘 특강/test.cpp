#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
struct info{
	int time;
	int y, x;
};
int map[51][51];
bool visited[51][51];
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int N, R, M, C, L, T;
void BFS(){
	queue<info> q;
	info start;
	start.time = 1;
	start.y = R;
	start.x = C;
	visited[R][C] = true;
	q.push(start);
	while(!q.empty()){
		info cur = q.front(); q.pop();
		cout << cur.y << " " << cur.x << "\n";
		if(cur.time > L) {
			break;
		}
		for(int dir = 0; dir < 4; dir++){
			int nextY = cur.y + dy[dir];
			int nextX = cur.x + dx[dir];
			info next;
			if(dir == 3) cout << nextY << " " << nextX << " " << visited[nextY][nextX] << " !@#!@# \n";
			if(nextY >= N || nextY < 0 || nextX >= M || nextX < 0) continue;
			if(visited[nextY][nextX]) continue;
			
			if(dir == 0){
				// ╩С 
				if(map[nextY][nextX] == 1 || map[nextY][nextX] == 2 || map[nextY][nextX] == 5 || map[nextY][nextX] == 6){
					if(map[cur.y][cur.x] == 1 || map[cur.y][cur.x] == 2 || map[cur.y][cur.x] == 4 || map[cur.y][cur.x] == 7){
						next.y = nextY; next.x = nextX;
						next.time = cur.time + 1;
						visited[nextY][nextY] = true;
						q.push(next);
					}
				}
			}else if(dir == 1){
				// го 
				if(map[nextY][nextX] == 1 || map[nextY][nextX] == 2 || map[nextY][nextX] == 4 || map[nextY][nextX] == 7){
					if(map[cur.y][cur.x] == 1 || map[cur.y][cur.x] == 2 || map[cur.y][cur.x] == 5 || map[cur.y][cur.x] == 6){
						next.y = nextY; next.x = nextX;
						next.time = cur.time + 1;
						q.push(next);
						visited[nextY][nextY] = true;
					}
				}
			}else if(dir == 2){
				// аб
				if(map[nextY][nextX] == 1 || map[nextY][nextX] == 3 || map[nextY][nextX] == 4 || map[nextY][nextX] == 5){
					if(map[cur.y][cur.x] == 1 || map[cur.y][cur.x] == 3 || map[cur.y][cur.x] == 6 || map[cur.y][cur.x] == 7){
						next.y = nextY; next.x = nextX;
						next.time = cur.time + 1;
						q.push(next);
						visited[nextY][nextY] = true;
					}
				}
			}else{
				// ©Л
				cout << " !"; 
				if(map[nextY][nextX] == 1 || map[nextY][nextX] == 3 || map[nextY][nextX] == 6 || map[nextY][nextX] == 7){
					if(map[cur.y][cur.x] == 1 || map[cur.y][cur.x] == 3 || map[cur.y][cur.x] == 4 || map[cur.y][cur.x] == 5){
						next.y = nextY; next.x = nextX;
						next.time = cur.time + 1;
						q.push(next);
						visited[nextY][nextY] = true;
					}
				}
			}
		}
	}
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for(int test = 1; test <= T; test++){
		cout << test << "\n";
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		cin >> N >> M >> R >> C >> L;
		for(int y = 0; y < N; y++){
			for(int x = 0; x < M; x++){
				cin >> map[y][x];
			}
		}
		// BFS ~until time > L
		BFS();
		//
		int result = 0;
		for(int y = 0; y < N; y++){
			for(int x = 0; x < M; x++){
				if(visited[y][x] == 1){
					result++;
				}
			}
		}
		cout << "#" << test << " " << result << "\n";
	}
	return 0;
}
