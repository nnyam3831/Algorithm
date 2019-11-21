// ���ִ� ������ ������ ������ �����Ƿ� �̰��� �� �й��ϸ� ��

#include <cstdio>
#include <algorithm>

using namespace std;

int M, N;
int candy[100001];
int main(void)
{
	scanf("%d%d", &M, &N);
	long long sum = -M;
	for(int i = 0; i < N; i++){
		scanf("%d", &candy[i]);
		sum += (long long)candy[i];
	}
	// ���� sum ���� ���ִ� ���� ����
	sort(candy, candy+N);
	
	long long ans = 0;
	for(int i = 0; i < N; i++){
		long long w = min((long long)candy[i], sum / (N-i));
		ans += w*w;
		sum -= w;
	
	} 
	
	printf("%lld\n", ans);
	
	return 0; 
} 
