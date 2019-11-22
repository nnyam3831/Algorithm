// ��ģ LIS(JLIS)
// Algospot ID: JLIS

// �Է��� 32��Ʈ ��ȣ�ִ� ������ ��� ���̱� ������ �ּ�ġ�� 64��Ʈ�� 

const long long NEGINF = numeric_limits<long long>::min();
int n, m, A[100], B[100];
int cache[101][101];

// min(A[index],B[index]), max(A[indexA],B[indexB])�� �����ϴ�
// ��ģ ���� �κ� ������ �ִ� ���̸� ����
// indexA == indexB == -1, A[indexA] != B[indexB]

// jlis(indexA,indexB) = A[indexA]�� B[indexB]���� �����ϴ� ��ģ ���� �κ� ������ �ִ� ���� 
int jlis(int indexA, int indexB){
	// �޸������̼�
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
