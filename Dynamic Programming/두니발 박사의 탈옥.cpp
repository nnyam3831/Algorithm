// AlgoSpot(ID: NUMB3RS)


/*
1��: �ð����⵵ O(n^2dt), search2(here, days) = �δϹ� �ڻ簡 days�� ���� here�� ������ �������� ��
, ������ ���� q�� ������ ���� ���Ǻ� Ȯ�� 
*/

int n, d, p, q;
double cache[51][101];
// connected[i][j] ���� i, j�� ����Ǿ� �ִ°�
// deg[i] = ���� i�� ����� ������ ����

int connected[51][51], deg[51];

double search2(int here, int days){
	// ����: ������ ��
	if(days == d) return (here == q ? 1.0 : 0.0);
	// �޸������̼�
	double& ret = cache[here][days];
	if(ret > -0.5) return ret;
	ret = 0.0;
	for(int there = 0; there < n; there++){
		if(connected[here][there]){
			ret += search2(there, days+1) / deg[here];
		}
	}
	return ret;
} 


/*
�ݴ� �������� Ǯ��: �ð����⵵ O(n^2d)
search3(here, days) = Ż�� �� days�� °�� �δϹ� �ڻ簡 here�� ������ �������� Ȯ�� 
*/

double search3(int here, int days){
	// ����: 0��°
	if(days == 0) return (here == p ? 1.0 : 0.0);
	// �޸������̼�
	double& ret = cache[here][days];
	if(ret > -0.5) return ret;
	ret = 0.0;
	for(int there = 0; there < n; there++){
		if(connected[here][there]){
			ret += search3(there,days-1) / deg[there];
		}
	} 
	return ret;
}
