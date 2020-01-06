// ���������� ��� DFS �� Ž���ϸ鼭 �������� �������� ���������� �ȴ�.

// ���ĺ��� �� ���ڿ� ���� ���� ��� ǥ��
// ���� (I,J)�� ���ĺ� I�� J���� �տ� �;� ���� ��Ÿ����.
vector<vector<int>> adj;
// �־��� �ܾ��κ��� ���ĺ� ���� ���İ��� �׷����� �����Ѵ�.
void makeGraph(const vector<string>& words){
	adj = vector<vector<int>>(26, vector<int>(26,0));
	for(int j = 1; j < words.size(); j++){
		int i = j - 1, len = min(words[i].size(), words[j].size());
		// word[i]�� word[j]�տ� ���� ������ ã�´�.
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

// dfs�� Ž��
vector<int> seen, order;
void dfs(int here){
	seen[here] = 1;
	for(int there = 0; there < adj.size(); there++){
		if(adj[here][there] && !seen[there]){
			dfs(there);
		}
	}
	// ���� ��ſ� push �ؼ� �������� ���� 
	order.push_back(here);
} 

// adj�� �־��� �׷����� ���������� ����� ��ȯ�Ѵ�.
// �׷����� DAG�� �ƴ϶�� �� ���͸� ��ȯ
vector<int> topologicalSort(){
	int m = adj.size();
	seen = vector<int>(m,0);
	order.clear();
	for(int i = 0; i < m; i++){
		if(!seen[i]) dfs(i);
	}
	reverse(order.begin(), order.end());
	// ���� �׷����� DAG�� �ƴ϶�� ���� ����� ������ ������ ����
	for(int i = 0; i < m; i++){
		for(int j = i+1; j < m; j++){
			if(adj[order[j][order[i]])
				return vector<int>();
		}
	} 
	return order;
} 
