#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#define MAX 100000 + 1
using namespace std;

long long weight[MAX];
long long parent[MAX];
long long find(int a){
	if(parent[a] == a) return a;
	long long prev = find(parent[a]);
	weight[a] += weight[parent[a]];
	return parent[a] = prev;
}
void Union(int a,int b){
	a = find(a);
	b = find(b);
	if(a > b) parent[a] = b;
	else parent[b] = a;
}

int main(void){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(1){
		int N, M;
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		for(int i = 1; i <= N; i++){
			parent[i] = i;
			weight[i] = 0;
		}
		for(int i = 0; i < M; i++){
			char c;
			long long a, b;
			cin >> c >> a >> b;
			if(c == '!'){
				long long w;
				cin >> w;
				long long l = find(a);
				long long r = find(b);
				// 둘 중 더 작은 게 기준됨
				if(l != r){
					parent[l] = r;
					weight[l] = weight[b] - weight[a] + w;
				}
			}else if(c == '?'){
				if(find(a) != find(b)){
					cout << "UNKNOWN\n";
				}else{
					cout << weight[a]-weight[b] << "\n";
				}
			}
		}
		
	}
	return 0;
} 
