// 위상정렬의 경우 DFS 를 탐색하면서 역순으로 뒤집으면 위상정렬이 된다.

// 알파벳의 각 글자에 대한 인접 행렬 표현
// 간선 (I,J)는 알파벳 I가 J보다 앞에 와야 함을 나타낸다.
vector<vector<int>> adj;
// 주어진 단어들로부터 알파벳 간의 선후관계 그래프를 생성한다.
void makeGraph(const vector<string>& words){
	adj = vector<vector<int>>(26, vector<int>(26,0));
	for(int j = 1; j < words.size(); j++){
		int i = j - 1, len = min(words[i].size(), words[j].size());
		// word[i]가 word[j]앞에 오는 이유를 찾는다.
		for(int k = 0; k < len; k++){
			if(words[i][k] != words[j][k]){
				int a = words[i][k] - 'a';
				int b = words[j][k] - 'a';
				ajd[a][b] = 1;
				break;
			}
		} 
	}
} 

// dfs로 탐색
vector<int> seen, order;
void dfs(int here){
	seen[here] = 1;
	for(int there = 0; there < adj.size(); there++){
		if(adj[here][there] && !seen[there]){
			dfs(there);
		}
	}
	// 리턴 대신에 push 해서 역순으로 넣음 
	order.push_back(here);
} 

// adj에 주어진 그래프를 위상정렬한 결과를 반환한다.
// 그래프가 DAG가 아니라면 빈 벡터를 반환
vector<int> topologicalSort(){
	int m = adj.size();
	seen = vector<int>(m,0);
	order.clear();
	for(int i = 0; i < m; i++){
		if(!seen[i]) dfs(i);
	}
	reverse(order.begin(), order.end());
	// 만약 그래프가 DAG가 아니라면 정렬 결과에 역방향 간선이 있음
	for(int i = 0; i < m; i++){
		for(int j = i+1; j < m; j++){
			if(adj[order[j][order[i]])
				return vector<int>();
		}
	} 
	return order;
} 
