#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <math.h>

using namespace std;

int Map[10][10];
int Check[10][10];
bool visited[10][10];
int Paper[6] = {0, 5, 5, 5, 5, 5};
const int dy[] = {0, 1, 1};
const int dx[] = {1, 1, 0};

void Marking(int startY, int startX){
	memset(visited, 0, sizeof(visited));
	Check[startY][startX] = 1;
	queue<pair<int,int>> q;
	vector<pair<int,int>> v;
	int finalSize = 1;
	v.push_back(make_pair(startY, startX));
	q.push(make_pair(startY, startX));
	cout << "start : " << startY << "," << startX << "\n";
	while(!q.empty()){
		int curY = q.front().first;
		int curX = q.front().second;
		visited[curY][curX] = 1;
		cout << curY << "," << curX << " \n";
		q.pop();
		if(v.size() == 4 || v.size() == 9 || v.size() == 16 || v.size() == 25){
			int size = sqrt(v.size());
			finalSize = size;
			if(size == 5) return;
		}
		for(int dir = 0; dir < 3; dir++){
			int nextY = curY + dy[dir];
			int nextX = curX + dx[dir];
			
			// 이미 검사가 끝났거나 색종이를 둘 수 없는 곳 
			if(Map[nextY][nextX] == 0 || Check[nextY][nextX] != 0 ) return;	
			if(nextY < 0 || nextY >= 10 || nextX < 0 || nextX >= 10 || visited[nextY][nextX] != 0) continue;
			
			v.push_back(make_pair(nextY,nextX));
			q.push(make_pair(nextY,nextX));
		}
	}
	for(int y = startY; y < startY + finalSize; y++){
		for(int x = startX; x < startX + finalSize; x++){
			Check[y][x] = finalSize;
		}
	}
	cout << "--------------\n";
}
int main(void){
	
	int result = 0;
	for(int y = 0; y < 10; y++){
		for(int x = 0; x < 10; x++){
			cin >> Map[y][x];
		}
	}	
	// Marking
	for(int y = 0; y < 10; y++){
		for(int x = 0; x < 10; x++){
			if(Map[y][x] == 1 && Check[y][x] == 0){
				Marking(y, x);
			}
		}
	}
	cout << "\n";
	for(int y = 0; y < 10; y++){
		for(int x = 0; x < 10; x++){
			cout << Check[y][x] << " ";
		}
		cout << "\n";
	}
	for(int y = 0; y < 10; y++){
		for(int x = 0; x < 10; x++){
			if(Check[y][x] != 0 && visited[y][x] == 0){
				int size = Check[y][x];
				for(int i = y; i <= y+size-1; i++){
					for(int j = x; j <= x+size-1; j++){
						visited[i][j] = 1;
						Paper[size]--;
						if(Paper[size] == -1){
							cout << -1 << "\n";
							return 0;
						}else{
							result++;
						}
					}
				}
			}
		}
	}
	cout << result << "\n";
	return 0;
}
