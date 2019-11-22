#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

int Dp[101];
int list[101];
int N;

bool cmp(const pair<int,int>& x, const pair<int,int>& y){
	return x.first < y.first;
}

int lis(int start){
	if(Dp[start] != -1) return Dp[start];
	int& ret = Dp[start];
	ret = 1;
	
	for(int next = start+1; next < N; next++){
		if(list[start] < list[next]){
			ret = max(ret, lis(next) + 1);
		}
	}
	return ret;
}
int main(void){
	
	cin >> N;
	vector<pair<int,int>> v;
	for(int i = 0; i < N; i++){
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i = 0; i < N; i++){
		list[i] = v[i].second;
	
	}
	
	int ans = 0;
	for(int i = 0; i < N; i++){
		memset(Dp, -1, sizeof(Dp));
		ans = max(ans, lis(i));
	}
	
	cout << N-ans << "\n";
	return 0;
}
