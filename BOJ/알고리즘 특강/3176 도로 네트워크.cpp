#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define swap(a,b){int t = a; a = b; b = t;}
#define MAX_NODE 100000 + 1

using namespace std;

typedef pair<int,int> pii;

int depth[MAX_NODE];
int ac[MAX_NODE][20];

vector<pii> graph[MAX_NODE];

int max_level = (int)floor(log2(MAX_NODE));
int maxDP[MAX_NODE][20];
int minDP[MAX_NODE][20];

int n;

void make_tree(int here, int parent, int val){
	depth[here] = depth[parent] + 1;
	
	ac[here][0] = parent;
	minDP[here][0] = val;
	maxDP[here][0] = val;
	
	for(int i = 1; i <= max_level; i++){
		// lca update
		int tmp = ac[here][i-1];
		ac[here][i] = ac[tmp][i-1];
	}
	
	for(int i = 0; i < graph[here].size(); i++){
		int there = graph[here][i].first;
		if(there != parent){
			make_tree(there, here, graph[here][i].second);
		}
	}
}

void make_DP(){
	for(int jump = 1; jump <= max_level; jump++){
		for(int here = 1; here <= n; here++){
			int temp = ac[here][jump-1];
			minDP[here][jump] = min(minDP[here][jump-1], minDP[temp][jump-1]);
			maxDP[here][jump] = max(maxDP[here][jump-1], maxDP[temp][jump-1]);
		}
	}	
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n-1; i++){
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(pii(b,c));
		graph[b].push_back(pii(a,c));
	}
	depth[0] = -1;

	make_tree(1, 0, 0);
	make_DP();
	
	int k;
	cin >> k;
	for(int i = 0; i < k; i++){
		int start, end;
		int ansMin = 987654321, ansMax = -1;
		cin >> start >> end;
		if(depth[start] != depth[end]){
			// 같은 높이까지 끌어올리기
			if(depth[start] > depth[end]){
				swap(start, end);
			} 
			for(int i = max_level; i >= 0; i--){
				if(depth[start] <= depth[ac[end][i]]){
					ansMin = min(ansMin, minDP[end][i]);
					ansMax = max(ansMax, maxDP[end][i]);
					end = ac[end][i];
				}
			}
		}
		int lca = start;
		if(start != end){
			for(int i = max_level; i >= 0; i--){
				if(ac[start][i] != ac[end][i]){
					ansMin = min(ansMin, min(minDP[start][i], minDP[end][i]));
					ansMax = max(ansMax, max(maxDP[start][i], maxDP[end][i]));
					end = ac[end][i];
					start = ac[start][i];
				}
				lca = ac[start][i];
			}
		}
		if(start != lca){
			ansMin = min(ansMin, min(minDP[start][0], minDP[end][0]));
			ansMax = max(ansMax, max(maxDP[start][0], maxDP[end][0])); 
		}
		cout << ansMin << " " << ansMax << "\n";
	}
	return 0;
}
