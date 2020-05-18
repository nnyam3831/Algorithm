#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
struct info{
	int time;
	int type;	
	int y, x;
};
info map[51][51];
int visited[51][51];
int N, R, M, C, L, T;
void BFS(){
	queue<info> q;
	map[R][C].time = 1;
	q.push(map[R][C]);
	while(!q.empty()){
		info cur = q.front(); q.pop();
		visited[cur.y][cur.x] = 1;
		int type = cur.type;
		int time = cur.time;
		if(time > L) break;
		if(type == 1){			
			if(map[cur.y-1][cur.x].type == 1 || map[cur.y-1][cur.x].type == 2 || map[cur.y-1][cur.x].type == 5 || map[cur.y-1][cur.x].type == 6 && visited[cur.y-1][cur.x] == 0){
				map[cur.y-1][cur.x].time = time+1;
				q.push(map[cur.y-1][cur.x]);
			}
			if(map[cur.y+1][cur.x].type == 1 || map[cur.y+1][cur.x].type == 2 || map[cur.y+1][cur.x].type == 4 || map[cur.y+1][cur.x].type == 7&& visited[cur.y+1][cur.x] == 0){
				map[cur.y+1][cur.x].time = time+1;
				q.push(map[cur.y+1][cur.x]);
			}
			if(map[cur.y][cur.x+1].type == 1 || map[cur.y][cur.x+1].type == 3 || map[cur.y][cur.x+1].type == 6 || map[cur.y][cur.x+1].type == 7&& visited[cur.y][cur.x+1] == 0){
				map[cur.y][cur.x+1].time = time+1;
				q.push(map[cur.y][cur.x+1]);
			}
			if(map[cur.y][cur.x-1].type == 1 || map[cur.y][cur.x-1].type == 3 || map[cur.y][cur.x-1].type == 4 || map[cur.y][cur.x-1].type == 5&& visited[cur.y][cur.x-1] == 0){
				map[cur.y][cur.x-1].time = time+1;
				q.push(map[cur.y][cur.x-1]);
			}
		}else if(type == 2){
			if(map[cur.y-1][cur.x].type == 1 || map[cur.y-1][cur.x].type == 2 || map[cur.y-1][cur.x].type == 5 || map[cur.y-1][cur.x].type == 6&& visited[cur.y-1][cur.x] == 0){
				map[cur.y-1][cur.x].time = time+1;
				q.push(map[cur.y-1][cur.x]);
			}
			if(map[cur.y+1][cur.x].type == 1 || map[cur.y+1][cur.x].type == 2 || map[cur.y+1][cur.x].type == 4 || map[cur.y+1][cur.x].type == 7&& visited[cur.y+1][cur.x] == 0){
				map[cur.y+1][cur.x].time = time+1;
				q.push(map[cur.y+1][cur.x]);
			}
		}else if(type == 3){
			if(map[cur.y][cur.x+1].type == 1 || map[cur.y][cur.x+1].type == 6 || map[cur.y][cur.x+1].type == 7&& visited[cur.y][cur.x+1] == 0){
				map[cur.y][cur.x+1].time = time+1;
				q.push(map[cur.y][cur.x+1]);
			}
			if(map[cur.y][cur.x-1].type == 1 || map[cur.y][cur.x-1].type == 4 || map[cur.y][cur.x-1].type == 5&& visited[cur.y][cur.x-1] == 0){
				map[cur.y][cur.x-1].time = time+1;
				q.push(map[cur.y][cur.x-1]);
			}
		}else if(type == 4){
			if(map[cur.y-1][cur.x].type == 1 || map[cur.y-1][cur.x].type == 2 || map[cur.y-1][cur.x].type == 5 || map[cur.y-1][cur.x].type == 6&& visited[cur.y-1][cur.x] == 0){
				map[cur.y-1][cur.x].time = time+1;
				q.push(map[cur.y-1][cur.x]);
			}
			if(map[cur.y][cur.x+1].type == 1 || map[cur.y][cur.x+1].type == 3 || map[cur.y][cur.x+1].type == 6 || map[cur.y][cur.x+1].type == 7&& visited[cur.y][cur.x+1] == 0){
				map[cur.y][cur.x+1].time = time+1;
				q.push(map[cur.y][cur.x+1]);
			}
		}else if(type == 5){
			if(map[cur.y+1][cur.x].type == 1 || map[cur.y+1][cur.x].type == 2 || map[cur.y+1][cur.x].type == 4 || map[cur.y+1][cur.x].type == 7&& visited[cur.y+1][cur.x] == 0){
				map[cur.y+1][cur.x].time = time+1;
				q.push(map[cur.y+1][cur.x]);
			}
			if(map[cur.y][cur.x+1].type == 1 || map[cur.y][cur.x+1].type == 3 || map[cur.y][cur.x+1].type == 6 || map[cur.y][cur.x+1].type == 7&& visited[cur.y][cur.x+1] == 0){
				map[cur.y][cur.x+1].time = time+1;
				q.push(map[cur.y][cur.x+1]);
			}
		}else if(type == 6){
			if(map[cur.y+1][cur.x].type == 1 || map[cur.y+1][cur.x].type == 2 || map[cur.y+1][cur.x].type == 4 || map[cur.y+1][cur.x].type == 7&& visited[cur.y+1][cur.x] == 0){
				map[cur.y+1][cur.x].time = time+1;
				q.push(map[cur.y+1][cur.x]);
			}
			if(map[cur.y][cur.x-1].type == 1 || map[cur.y][cur.x-1].type == 3 || map[cur.y][cur.x-1].type == 4 || map[cur.y][cur.x-1].type == 5&& visited[cur.y][cur.x-1] == 0){
				map[cur.y][cur.x-1].time = time+1;
				q.push(map[cur.y][cur.x-1]);
			}
		}else if(type == 7){
			if(map[cur.y-1][cur.x].type == 1 || map[cur.y-1][cur.x].type == 2 || map[cur.y-1][cur.x].type == 5 || map[cur.y-1][cur.x].type == 6&& visited[cur.y-1][cur.x] == 0){
				map[cur.y-1][cur.x].time = time+1;
				q.push(map[cur.y-1][cur.x]);
			}
			if(map[cur.y][cur.x-1].type == 1 || map[cur.y][cur.x-1].type == 3 || map[cur.y][cur.x-1].type == 4 || map[cur.y][cur.x-1].type == 5&& visited[cur.y][cur.x-1] == 0){
				map[cur.y][cur.x-1].time = time+1;
				q.push(map[cur.y][cur.x-1]);
			}
		}else{
			// type == 0
			continue;
		}
	}
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for(int test = 1; test <= T; test++){
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		cin >> N >> M >> R >> C >> L;
		for(int y = 0; y < N; y++){
			for(int x = 0; x < M; x++){
				cin >> map[y][x].type;
				map[y][x].y = y; map[y][x].x = x;
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
