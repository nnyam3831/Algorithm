// matrix[a][b] : 1,1부터 a,b까지의 합

#include <iostream>
#include <algorithm>
#define MAX 1024+1
using namespace std;

int matrix[MAX][MAX];
int sum[MAX][MAX];
int N, M, value;
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	
	for(int x = 1; x <= N; x++){
		for(int y = 1; y <= N; y++){
			cin >> value;
			sum[x][y] = sum[x-1][y] + sum[x][y-1] - sum[x-1][y-1] + value;
		}
	}
	
	for(int i = 0; i < M; i++){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] << "\n";
	}
	return 0;
} 
