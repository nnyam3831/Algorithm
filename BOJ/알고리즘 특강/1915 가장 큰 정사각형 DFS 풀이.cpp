#include <iostream>
#include <algorithm>
#include <limits.h>
#define MAX 1000+1
using namespace std;
int n, m;
int cache[MAX][MAX];
int map[MAX][MAX];
int ans;
const int dy[] = {0, 1, 1};
const int dx[] = {1, 1, 0};
int DFS(int i, int j){
	if(cache[i][j]) return cache[i][j];
	if(map[i][j] == 0) return 0;
	if(i < 0 || i >= n || j < 0 || j >= m) return 0;
	int ret = INT_MAX;
	for(int dir = 0; dir < 3; dir++){
		ret = min(ret, DFS(i+dy[dir], j+dx[dir]));
	}
	ans = max(ans, ret+1);
	return cache[i][j] = ret + 1;
	
}
int main(void){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			cin >> c;
			map[i][j] = c-'0';
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			DFS(i, j);
		}
	}
	cout << ans*ans << "\n";
	return 0;
}
