#include <iostream>
#include <vector>
#include <math.h>
#define MAX 100000 + 1

using namespace std;

int max_height = (int)floor(log2(MAX));
int Dp[MAX][20];
int depth[MAX];
vector<int> group[MAX];

void DFS(int here, int parent){
	Dp[here][0] = parent;
	depth[here] = depth[parent] + 1;
	
	// update
	for(int i = 1; i <= max_height; i++){
		int temp = Dp[here][i-1];
		Dp[here][i] = Dp[temp][i-1];
	}
	
	for(int i = 0; i < group[here].size(); i++){
		int there = group[here][i];
		if(there == parent) continue;
		DFS(there, here);
	}
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N;
	for(int i = 0; i < N-1; i++){
		int a, b;
		cin >> a >> b;
		group[a].push_back(b);
		group[b].push_back(a);
	}
	depth[0] = -1;
	
	// DFS�� Tree ��ȸ�ϸ鼭 Dp ���� 
	DFS(1, 0);
	cin >> M;
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		if(depth[a] != depth[b]){
			if(depth[a] > depth[b]) swap(a, b);
			for(int i = max_height; i >= 0; i--){
				int temp = Dp[b][i];
				if(depth[temp] >= depth[a]){
				// ������쿡�� ����
					b = temp;  
				}
			}	
		} 
		// ���� ������ 
		int lca = a;
		if(a != b){
			for(int j = max_height; j >= 0; j--){
				if(Dp[a][j] != Dp[b][j]){
					a = Dp[a][j];
					b = Dp[b][j];
				}
				lca = Dp[a][j];
			}
		}
		cout << lca << "\n";
	}
	
	return 0;
}
