#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define MAX 17

using namespace std;

// 방향 변환 7개 
// 가로 2개 세로 2개 대각 3개 
const int dy[] = {0, 1, 1, 1, 0, 1, 1};
const int dx[] = {1, 1, 0, 1, 1, 0, 1};
int Map[MAX][MAX];
int visited[MAX][MAX];
int N;
int nextStartY, nextStartX, nextEndY, nextEndX;
struct Position{
	int startY, startX;
	int endY, endX;
	vector<pair<int,int>> v;
};
Position first;



bool check(int Y,int X){
	if(X <= N && Y <= N){
		if(Map[Y][X] == 0){
			return true;
		}
	}
	return false;
}


int main(void){
	
	int answer = 0;
	cin >> N;
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= N; x++){
			cin >> Map[y][x];
		}
	}
	first.startY = 1, first.startX = 1;
	first.endY = 1, first.endX = 2;
	pair<int,int> firstPair;
	firstPair.first = 1;
	firstPair.second = 2;
	first.v.push_back(firstPair);
	
	queue<Position> q;
	q.push(first);
	
	while(!q.empty()){
		Position cur = q.front(); q.pop();
		Position next;
		vector<pair<int,int>> temp = cur.v;
		if(cur.endY == N && cur.endX == N){
			
			answer++;
			
			continue;
		}
		// 가로
		if(cur.startY == cur.endY){
			next.startY = cur.endY, next.startX = cur.endX;
			next.endY = next.startY +dy[0];
			next.endX = next.startX +dx[0];
			if(check(next.startY, next.startX) && check(next.endY, next.endX)){
				
				q.push(next);
			}
			next.endY = next.startY +dy[1];
			next.endX = next.startX +dx[1];
			if(check(next.startY, next.startX) && check(next.endY, next.endX) &&
			check(next.startY, next.startX-1) && check(next.endY-1, next.endX)){
				
				
				q.push(next);
			}
			
		}
		// 세로
		else if(cur.startX == cur.endX){
			next.startY = cur.endY, next.startX = cur.endX;
			next.endY = next.startY +dy[2];
			next.endX = next.startX +dx[2];
			if(check(next.startY, next.startX) && check(next.endY, next.endX)){
				
				q.push(next);
			}
			next.endY = next.startY +dy[3];
			next.endX = next.startX +dx[3];
			if(check(next.startY, next.startX) && check(next.endY, next.endX) &&
			check(next.startY, next.startX-1) && check(next.endY-1, next.endX)){
				
				q.push(next);
			}
		}
		// 대각
		else{
			next.startY = cur.endY, next.startX = cur.endX;
			next.endY = next.startY +dy[4];
			next.endX = next.startX +dx[4];
			if(check(next.startY, next.startX) && check(next.endY, next.endX)){
				
				q.push(next);
			}
			next.endY = next.startY +dy[5];
			next.endX = next.startX +dx[5];
			if(check(next.startY, next.startX) && check(next.endY, next.endX)){
				
				q.push(next);
			}
			next.endY = next.startY +dy[6];
			next.endX = next.startX +dx[6];
			if(check(next.startY, next.startX) && check(next.endY, next.endX) &&
			check(next.startY, next.startX-1) && check(next.endY-1, next.endX)){
				
				q.push(next);
			}
		} 
	}
	cout << answer << "\n";
	
	return 0;
}
