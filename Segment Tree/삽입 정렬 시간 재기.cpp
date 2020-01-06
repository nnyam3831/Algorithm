// Algo Spot ID : MESURETIME
// 원소가 옆으로 몇 칸이나 움직일지를 알기 위해서는 이 원소의 왼쪽 구간에 
// 원소보다 큰 숫자가 몇개가 있는지를 알면 된다.
// 펜윅트리 !!
// 각 숫자의 출현 횟수를 저장하는 펜윅 트리
long long countMoves(const vector<int> &A){
	FenwickTree tree(1000000);
	long long ret = 0;
	for(int i = 0; i < A.size(); i++){
		ret += tree.sum(999999)-tree.sum(A[i]);
	}
} 
 
