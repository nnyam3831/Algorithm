int n, m;
int cache[MAX_N][2*MAX_N+1];

// �����̰� days���� clibmed���͸� ���ö� �Դٰ� �� ��
// m�� ������ n���͸� ���ö� �� �ִ� ����� ��

int climb(int days, int climbed){
	// ���� : m���� ��� ���� ���
	if(days == m) return climbed >=n ? 1: 0;
	
	// �޸������̼�
	int& ret = cache[days][climbed];
	if(ret != -1) return ret;
	return ret = climb(days+1, climbed+1) + climb(days+1, climbed+2); 
} 
