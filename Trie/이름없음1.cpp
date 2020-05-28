#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100000 + 1
using namespace std;

long long parent[MAX];
long long weight[MAX];
// parent 기준으로 계속 weight 값을 갱신

long long find(int num){
	if(parent[num] == num) return num;
	long long prev = find(parent[num]);
	weight[num] += weight[parent[num]];
	return parent[num] = prev;
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
			// query
			char c;
			long long a, b;
			cin >> c >> a >> b;
			if(c == '!'){
				long long w;
				cin >> w;
				long long small = find(a);
				long long big = find(b);
				if(a != b){
					parent[big] = small;
					weight[big] = weight[a] - weight[b] + w;
				}
			}
			if(c == '?'){
				if(find(a) != find(b)) cout << "UNKNOWN\n";
				else cout << weight[b] - weight[a] << "\n";
			}
		}	
	}	
	return 0;
}
