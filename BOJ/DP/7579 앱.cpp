#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAX = 100;
const int MAX_COST = 10000 + 1;
int n, m;
int memory[MAX];
int cost[MAX];
int dp[MAX][MAX_COST];

int max_memory(int index, int totalCost){
	if(index >= MAX) return 0;
	if(dp[index][totalCost] != -1) return dp[index][totalCost];
	
	int result = max_memory(index + 1, totalCost);
	
	if(cost[index] <= totalCost){
		result = max(result, memory[index] + max_memory(index + 1, totalCost - cost[index]));
	}
	return dp[index][totalCost] = result;
}

int main(void){
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> memory[i];
	for(int i = 0; i < n; i++) cin >> cost[i];
	
	memset(dp, -1, sizeof(dp));
	int result;
	for(int c = 0; c < MAX_COST; c++){
		if(max_memory(0, c) >= m){
			// 메모리 확보 가능?
			result = c;
			break;
		}
	}
	cout << result << "\n";
	return 0;
}
