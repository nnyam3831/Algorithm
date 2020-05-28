#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 50005;
const int MAX_LEVEL = 20;
vector<pair<int,int>> graph[MAX_SIZE];
vector<pair<int,int>> tree[MAX_SIZE];
int level[MAX_SIZE];
int par[MAX_HEIGHT][MAX_SIZE];
int dst[MAX_HEIGHT][MAX_SIZE];
int dst_2[MAX_HEIGHT][MAX_SIZE];
int prim_dst[MAX_SIZE];
int vst[MAX_SIZE];
int prim_vst[MAX_SIZE];
int n;
void dfs(int x, int w, int parent, int level){
	vst[x] = 1;
	par[0][x] = parent;
	dst[0][x] = w;
	level[x] = level;
	for(auto nxt: tree[x]){
		if(vst[nxt.first] == 1) continue;
		
	}
}
bool myf(int x, int y){
	return x > y;
}


int main(void){
	return 0;
} 
