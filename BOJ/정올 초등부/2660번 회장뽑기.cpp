// 플로이드-와샬
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 51
#define INF 100000000

using namespace std;

int n;
int matrix[MAX][MAX];
int score[MAX];

void Floyd(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
			}
		}
	}
} 

int main(void){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			matrix[i][j] = (i==j)? 0: INF;
		}
	}
	
	while(1){
		int a, b;
		cin >> a >> b;
		if(a == -1 && b == -1) break;
		matrix[a][b] = 1;
		matrix[b][a] = 1;
	}
	
	Floyd();
	int selected = -1;
	for(int i = 1; i <= n; i++){
		int max = 0;
		for(int j = 1; j <= n; j++){
			if(matrix[i][j] > max){
				max = matrix[i][j];
			}
		}
		score[i] = max;
		if(selected > max || selected == -1){
			selected = max;
		}
	}
	int count = 0;
	for(int i = 1; i <= n; i++){
		if(score[i] == selected){
			count++;
		}
	}
	cout << selected << " " << count << "\n";
	for(int i = 1; i <= n; i++){
		if(score[i] == selected){
			cout << i << " ";
		}
	}
	cout << "\n";
	return 0;
}
