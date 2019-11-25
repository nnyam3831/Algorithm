// Algospot (ID: POLY)
// ���� Ž���� ��� �κй����� O(n^2) , �� �� ����ϴµ� O(n)�̹Ƿ� ��ü �ð����⵵ O(n^3)

const int MOD = 10*1000*1000;
int cache[101][101];
// n���� ���簢������ ���� �� �ִ� poly�� ����, �׸��� ù ��° ���� first

int poly(int n, int first){
	// ���� n == fisrt
	if(n == first) return 1;
	// �޸������̼�
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
