#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100000 + 1;
int parent[MAX];
long long weight[MAX];

int find(int num){
	if(parent[num] == num) return num;
	long long prev = find(parent[num]);
	weight[num] += weight[parent[num]];
	return parent[num] = prev;
}

void setWeight(int a, int b, int w){
	int small = find(a);
	int big = find(b);
	parent[big] = small;
	weight[big] = weight[a] - weight[b] + w;
}

int main(void){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(1){
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0) break;
		
		for(int i = 1; i <= n; i++){
			parent[i] = i;
			weight[i] = 0;
		}
		
		for(int i = 0; i < m; i++){
			char c;
			cin >> c;
			if(c == '!'){
				int a, b, w;
				cin >> a >> b >> w;
				setWeight(a, b, w);
			}else{
				int a, b;
				cin >> a >> b;
				if(find(a) != find(b)){
					cout << "UNKNOWN\n";
				}else{
					cout << weight[b] - weight[a] << "\n";
				}
			}
		}
	}
	return 0;
}
