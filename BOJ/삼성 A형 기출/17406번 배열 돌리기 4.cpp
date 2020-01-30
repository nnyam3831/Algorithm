//49 X 49개 배열 접근 => 6번
//15000 * 720 => 8000만? 

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 51
using namespace std;

struct op{
	int r, c, s;
};
int N,M,K;
int Map[MAX][MAX];
int Copy[MAX][MAX];
int result = 1000000000;			// minimum
op operation[7];
int seq[6];
void rotate(int r, int c, int s){
	
	for(int i = 1; i <= s; i++){
		int temp = Map[r-i][c-i];		// 좌상단
		// 왼쪽 
		for(int row = r-i; row <= r+i-1; row++){
			Map[row][c-i] = Map[row+1][c-i];
		}  
		// 아래
		for(int col = c-i; col <= c+i-1; col++){
			Map[r+i][col] = Map[r+i][col+1];
		}  
		// 오른쪽
		for(int row = r+i; row >= r-i+1; row--){
			Map[row][c+i] = Map[row-1][c+i];
		}  
		// 위
		for(int col = c+i; col >= c-i+2; col--){
			Map[r-i][col] = Map[r-i][col-1];
		}  
		Map[r-i][c-i+1] = temp;		 
	}
}

int solution(){
	int Min = 10000000000;
	for(int y = 1; y <= N; y++){
		int sum = 0;
		for(int x = 1; x <= M; x++){
			sum += Map[y][x];
		}
		Min = min(Min, sum);
	}
	return Min;
}
// K!
void DFS(int size){
	if(size == K){
		for(int y = 1; y <= N; y++){
			for(int x = 1; x <= M; x++){
				Map[y][x] = Copy[y][x];
			}
		}
		for(int i = 0; i < K; i++){
			rotate(operation[seq[i]].r, operation[seq[i]].c, operation[seq[i]].s);
	 	}
		result = min(result, solution());
		
		return;
	}
	for(int i = 0; i < K; i++){
		if(seq[i] == 0){
			seq[i] = ++size;
			DFS(size);
			seq[i] = 0;
			size--;			
		}
	}
}
int main(void){
	
	cin >> N >> M >> K;
	for(int y = 1; y <= N; y++){
		for(int x = 1; x <= M; x++){
			cin >> Map[y][x];
			Copy[y][x] = Map[y][x];
		}
	}
	for(int i = 1; i <= K; i++){
		cin >> operation[i].r >> operation[i].c >> operation[i].s;
	}
	
	DFS(0);
	cout << result << "\n";	
	return 0;
} 
