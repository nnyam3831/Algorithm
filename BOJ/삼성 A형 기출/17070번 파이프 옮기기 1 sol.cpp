#include <iostream>
#define MAX 17
using namespace std;

typedef struct{
	int y, x;
}dir;


// 가로, 세로, 대각선 
dir moveDir[3] = {{0, 1}, {1, 0}, {1,1}};

int N;
int result;
int map[MAX][MAX];

void DFS(int y, int x, int state){
	// 탐색완료
	if(y == N-1 && x == N-1){
		result++;
		return;
	} 
	
	// 가지치기 
	for(int i = 0; i < 3; i++){
		if((i == 0 && state == 1) || (i == 1 && state == 0)){
			continue;
		}
		int nextY = y + moveDir[i].y;
		int nextX = x + moveDir[i].x;
		if(nextY >= N || nextX >= N || map[nextY][nextX] == 1){
			continue;
		}
		if(i == 2 && (map[y][x+1] == 1 || map[y+1][x] == 1)){
			continue;
		}
		DFS(nextY,nextX, i);
	}
} 

int main(void){
	
	cin >> N;
	for(int y = 0; y < N; y++){
		for(int x = 0; x < N; x++){
			cin >> map[y][x];
		}
	}
	
	// (1,2) 가로 
	DFS(0, 1, 0);
	cout << result << "\n";	
	return 0;
}
