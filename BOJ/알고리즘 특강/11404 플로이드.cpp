#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100+1
#define INF 987654321
using namespace std;

typedef pair<int,int> pii;
int city[MAX][MAX];

int main(void){
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			city[i][j] = INF;
			if(i == j) city[i][j] = 0;
		}
	}
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		city[a][b] = min(city[a][b],c);
	}
	
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			city[i][j] == INF ? cout << "0 " : cout << city[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
