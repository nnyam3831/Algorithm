#include <iostream>
#include <vector>
#define MAX 100+1

using namespace std;

bool cycle[MAX];
bool visited[MAX];
int node[MAX];
int N, cnt;

bool DFS(int startNode, int currentNode){
	// ����
	if(visited[currentNode]) 
		return false;
		
	visited[currentNode] = true;
	
	// ����Ŭ ����  
	if(startNode == currentNode || DFS(startNode, node[currentNode])){
		cnt++;
		cycle[currentNode] = true;
		return true;
	}
	return false;
}
int main(void){
	
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> node[i];
	}
	// DFS�����鼭 ����Ŭ Ȯ����
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			visited[j] = cycle[j];
		}
		DFS(i, node[i]);
	} 
	
	cout << cnt << "\n";
	
	for(int i = 1; i <= N; i++){
		if(cycle[i]) cout << i << "\n";
	}
	return 0;
}
