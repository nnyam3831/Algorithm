// 비트마스크  

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, start, W[16][16], cache[16][65536];
const int IMPOSSIBLE = 1000000000;

/*
현재 current 마을, 방문한 마을 집합이 visited 일 때 앞으로 남은 마을을 모두 방문하고 0번 마을로 돌아갈 때 드는 최소비용
*/

int TSP(int current, int visited)
{
	/*
	기저 : 모든 마을을 방문한 경우 (비트마스크 all 1) 
	*/
	if(visited == (1 << N )-1)
	{
		return W[current][start]?W[current][start]:IMPOSSIBLE;
	}
	
	if(cache[current][visited] != -1) return cache[current][visited];
	
	int &ret = cache[current][visited];
	
	ret = IMPOSSIBLE;
	// 방문 안한곳 다 순회함 
	for(int i = 0; i < N; i++)
	{
		if(visited & (1<<i)) continue;
		if(W[current][i] == 0) continue;
		ret = min(ret, TSP(i, visited | (1<<i)) + W[current][i]);
	}
	return ret;
}

int main(void)
{
	scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            scanf("%d", &W[i][j]);
    memset(cache, -1, sizeof(cache));
	
	printf("%d\n", TSP(0,1));
	return 0;
}
