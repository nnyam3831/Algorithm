// Algo Spot ID : MESURETIME
// ���Ұ� ������ �� ĭ�̳� ���������� �˱� ���ؼ��� �� ������ ���� ������ 
// ���Һ��� ū ���ڰ� ��� �ִ����� �˸� �ȴ�.
// ����Ʈ�� !!
// �� ������ ���� Ƚ���� �����ϴ� ���� Ʈ��
long long countMoves(const vector<int> &A){
	FenwickTree tree(1000000);
	long long ret = 0;
	for(int i = 0; i < A.size(); i++){
		ret += tree.sum(999999)-tree.sum(A[i]);
	}
} 
 
