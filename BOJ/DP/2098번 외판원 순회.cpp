// ��Ʈ����ũ  

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N, start, W[16][16], cache[16][65536];
const int IMPOSSIBLE = 1000000000;

/*
���� current ����, �湮�� ���� ������ visited �� �� ������ ���� ������ ��� �湮�ϰ� 0�� ������ ���ư� �� ��� �ּҺ��
*/

int TSP(int current, int visited)
{
	/*
	���� : ��� ������ �湮�� ��� (��Ʈ����ũ all 1) 
	*/
	if(visited == (1 << N )-1)
	{
		return W[current][start]?W[current][start]:IMPOSSIBLE;
	}
	
	if(cache[current][visited] != -1) return cache[current][visited];
	
	int &ret = cache[current][visited];
	
	ret = IMPOSSIBLE;
	// �湮 ���Ѱ� �� ��ȸ�� 
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
