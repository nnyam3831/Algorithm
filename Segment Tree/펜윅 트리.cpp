// 구간 트리로 구간합 빠르게 구하기 O(logN)
// 가상의 배열 A[]의 부분 합을 빠르게 구현할 수 있도록 해줌
struct FenwickTree{
	vector<int> tree;
	FenwickTree(int n) : tree(n+1){
		
	}
	int sum(int pos){
		// 인덱스가 1부터 시작한다고 생각하자.
		++pos;
		int ret = 0;
		while(pos > 0){
			ret += tree[pos];
			// 다음 구간을 찾기 위해 최종 비트를 지운다.
			pos &= (pos-1); 
		} 
		return ret;
	}
	//A[pos]에 val을 더한다.
	void add(int pos, int val){
		++pos;
		while(pos < tree.size()){
			tree[pos] += val;
			pos += (pos & -pos);
		}
	} 
}; 
