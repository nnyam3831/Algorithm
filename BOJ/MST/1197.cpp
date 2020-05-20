#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000+1
using namespace std;

int parent[MAX];

typedef struct edge{
	int from, to, weight;
	edge(int from, int to, int weight){
		this->from = from;
		this->to = to;
		this->weight = weight;
	}
};

bool cmp(const edge &a, const edge &b){
	return a.weight < b.weight;
}
int find(int num){
	if(parent[num] == num) return num;
	return parent[num] = find(parent[num]);
}

void Union(int a, int b){
	int pa = find(a);
	int pb = find(b);
	if(pa < pb){
		parent[pb] = pa;
	}else{
		parent[pa] = pb;
	}
}
int main(void){
	
	int V, E;
	long long answer = 0;
	cin >> V >> E;
	vector<edge> v;
	
	for(int i = 0; i < E; i++){
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(edge(a, b, c));
	}
	
	for(int i = 1; i <= V; i++) parent[i] = i;
	
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i < v.size(); i++){
		if(find(v[i].from) != find(v[i].to)){
			Union(v[i].from, v[i].to);
			answer += v[i].weight;
		}
	}
	
	cout << answer << "\n";
	return 0;
}
