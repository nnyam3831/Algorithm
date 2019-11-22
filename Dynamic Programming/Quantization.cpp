
const int INF = 987654321;

// A[] : 양자화 해야될 수열 정렬상태
// pSum[] : A[]의 부분합 저장
// pSqSum[] : A[]제곱의 부분합 저ㅏㅇ

int n;
int A[101], pSum[101], pSqSum[101];

void precalc(){
	sort(A, A+n);
	pSum[0] = A[0];
	pSqSum[0] = A[0] * A[0];
	for(int i = 1; i < n; i++){
		pSum[i] = pSum[i-1] + A[i];
		pSqSum[i] = pSqSum[i-1] + A[i] * A[i];
	}
} 

int minError(int lo, int hi){
	
	// 부분합을 이용해 A[lo]~A[hi] 구함
	int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
	int sqSum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
	
	// 평균의 반올림값
	int m = int(0.5 + (double)sum / (hi-lo+1));
	
	int ret = sqSum - 2*m*sum + m*m*(hi-lo-1);
	return ret; 
}

int cache[101][11];
int quantize(int from, int parts){
	// 기저: 모든 숫자를 다 양자화
	if(from == n) return 0;
	// 기저: 숫자는 남았는데 더 묶을 수 없을때
	if(parts == 0) return INF;
	int& ret = cache[from][parts];
	
	if(ret != -1) return ret;
	ret = INF;
	// 조각 길이 변화시키면서 최소값 찾음
	for(int partSize = 1; from+partSize <= n; partSize++){
		ret = min(ret, minError(from, from+partSize-1) + quantize(from+partSize, parts-1));
	} 
	return ret;
}
