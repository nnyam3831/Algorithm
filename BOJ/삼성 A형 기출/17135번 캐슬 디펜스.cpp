/*
�ü��� ���ÿ� �߻� and �ü��� ���� ���� ������ �� �ִ� ��� ������ ���� ���ؼ� �����
���� �ȹٷ� ������ 
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#define MAX 16
using namespace std;

struct position{
	int y, x, distance;
};
int N, M, D, result;	// MAX result ���ϱ�  
int Map[MAX][MAX];
int Copy[MAX][MAX];

int visited[MAX][MAX];
int Archer[MAX];		// �ü� ��ġ �迭 (M) 
const int dy[] = {0, -1, 0};
const int dx[] = {-1, 0, 1};
void Simulation(){
	
	int tempResult = 0;
	for(int i = N-1; i >= 0; i--){
		vector<pair<int,int>> v;
		for(int pos = 0; pos < M; pos++){
			if(Archer[pos] == 0){
				continue;
			}
			// �� �پ� simulation
			// ���� ��ġ i ���� ����
			if(Map[i][pos] == 1){
				v.push_back(make_pair(i, pos));
				continue;
			} 
			// ���� ��� �ƴϸ� ť����
			queue<position> q;
			position start;
			start.y = i;
			start.x = pos;
			start.distance = 1;
			q.push(start);
			while(!q.empty()){
				// ��Ÿ� ������ ����,��, ������ ������ ����
				position cur = q.front();
				q.pop();
				if(D < cur.distance) break;
				if(Map[cur.y][cur.x] == 1){
					v.push_back(make_pair(cur.y,cur.x));
					break;
				}
				for(int dir = 0; dir < 3; dir++){
					int nextY = cur.y + dy[dir];
					int nextX = cur.x + dx[dir];
					if(nextY >= N ||nextY < 0 || nextX >= M || nextX < 0) continue;
					position next;
					next.y = nextY;
					next.x = nextX;
					next.distance = cur.distance+1;
					q.push(next);
				}				
				 
			}
		}
		for(int idx = 0; idx< v.size(); idx++){		
			if(Map[v[idx].first][v[idx].second] == 1){
				Map[v[idx].first][v[idx].second] = 0;
				tempResult++;
			}
		}
		
		
	
	}
	result = max(result, tempResult);
	
}

void DFS(int size,int start){
	if(size == 3){
	
		Simulation();
		for(int y = 0; y < N; y++){
			for(int x = 0; x < M; x++){
				Map[y][x] = Copy[y][x];
			}
		}		
		return;	
	}
	
	for(int i = start; i < M; i++){
		if(Archer[i] == 0){
			Archer[i] = 1;
			DFS(++size, i+1);
			Archer[i] = 0;
			size--;
		}
	
	}

}

int main(void){
	
	cin >> N >> M >> D;
	for(int y = 0; y < N; y++){
		for(int x = 0; x < M; x++){
			cin >> Map[y][x];
			Copy[y][x] = Map[y][x];
		}
	}
	DFS(0,0);
	cout << result << "\n";
	
	return 0;
} 
