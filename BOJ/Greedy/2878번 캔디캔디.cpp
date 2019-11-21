// 못주는 사탕의 개수가 정해져 있으므로 이것을 잘 분배하면 됨

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
	// 지금 sum 에는 못주는 사탕 개수
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
