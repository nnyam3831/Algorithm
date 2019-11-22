// 합친 LIS(JLIS)
// Algospot ID: JLIS

// 입력이 32비트 부호있는 정수의 모든 값이기 때문에 최소치는 64비트로 

const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];

// min(A[index],B[index]), max(A[indexA],B[indexB])로 시작하는
// 합친 증가 부분 수열의 최대 길이를 리턴
// indexA == indexB == -1, A[indexA] != B[indexB]

// jlis(indexA,indexB) = A[indexA]와 B[indexB]에서 시작하는 합친 증가 부분 수열의 최대 길이 
int jlis(int indexA, int indexB){
	// 메모이제이션
	int& ret = cache[indexA+1][indexB+1]; 
	if(ret != -1) return ret;
	
	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a,b);
	
	for(int nextA = indexA+1; nextA < n; nextA++){
		if(maxElement < A[nextA]){
			ret = max(ret, jlis(nextA, indexB) + 1);
		}
	}
	for(int nextB = indexB+1; nextB < n; nextB++){
		if(maxElement < B[nextB]){
			ret = max(ret, jlis(indexA, nextB) + 1);
		}
	}
	return ret;
} 
