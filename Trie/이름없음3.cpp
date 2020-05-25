#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000 + 1
using namespace std;

// MST 
typedef struct edge{
	int a, b;
	int cost;
}edge;
int parent[MAX];
int find(int num){
	if(parent[num] == num) return num;
	else return find(parent[num]);
}

void Union(int a, int b){
	int pa = find(a);
	int pb = find(b);
	if(pa < pb) parent[pb] = pa;
	else parent[pa] = pb;
}

bool cmp(const edge &a, const edge &b)
{
	return a.cost < b.cost;
}

int main(void){
	
	int N, M;
	cin >> N >> M;
	vector<edge> E;
	for(int i = 1; i <= N; i++){
		parent[i] = i;
	}
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edge temp;
		temp.a = a;
		temp.b = b;
		temp.cost = c;
		E.push_back(temp);
	}
	
	int answer = 0;
	
	sort(E.begin(), E.end(), cmp);
	for(int i = 0; i < E.size(); i++){
		if(find(E[i].a) != find(E[i].b)){
			Union(E[i].a, E[i].b);
			answer += E[i].cost;
		}
	}
	cout << answer << "\n";
	return 0;
}
