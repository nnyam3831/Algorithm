// Algospot (ID: POLY)
// 완전 탐색의 경우 부분문제는 O(n^2) , 한 번 계산하는데 O(n)이므로 전체 시간복잡도 O(n^3)

const int MOD = 10*1000*1000;
int cache[101][101];
// n개의 정사각형으로 만들 수 있는 poly의 개수, 그리고 첫 번째 줄을 first

int poly(int n, int first){
	// 기저 n == fisrt
	if(n == first) return 1;
	// 메모이제이션
	int& ret = cache[n][first];
	if(ret != -1) return ret;
	ret = 0;
	for(int second = 1; second <= n-first; second++){
		int add = second + first - 1;
		add *= poly(n-first, second);
		add %= MOD;
		ret += add;
		ret %= MOD;
	} 
	
	return ret;
} 
