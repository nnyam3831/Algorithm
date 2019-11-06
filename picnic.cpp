// recursive

#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

int n, m;
bool Friend[10][10];
bool taken[10];

int countPairings(bool taken[10]){
	int first = -1;
	for(int i = 0; i < n; i++){
		if(!taken[i]){
			first = i;
			break;
		}
	}
	// 모든 학생이 짝을 가진 한 가지 방법 
	if(first == -1)	return 1;
	int ret = 0;
	for(int pair = first + 1; pair < n; pair++){
		if(Friend[first][pair] && !taken[pair]){
			taken[first] = true;
			taken[pair] = true;
			ret += countPairings(taken);
			taken[first] = false;
			taken[pair] = false;
		}	
	}
	return ret;
	
}
int main(void){
	
	int Test;
	cin >> Test;
	for(int T = 0; T < Test; T++){
		cin >> n >> m;
		memset(Friend,0,sizeof(Friend));
		memset(taken,0,sizeof(taken));
		for(int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			Friend[a][b] = 1;
			Friend[b][a] = 1;
		}
		
		int answer = countPairings(taken);
		cout << answer << endl;
	}
	return 0;
}
