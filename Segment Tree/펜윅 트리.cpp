// ���� Ʈ���� ������ ������ ���ϱ� O(logN)
// ������ �迭 A[]�� �κ� ���� ������ ������ �� �ֵ��� ����
struct FenwickTree{
	vector<int> tree;
	FenwickTree(int n) : tree(n+1){
		
	}
	int sum(int pos){
		// �ε����� 1���� �����Ѵٰ� ��������.
		++pos;
		int ret = 0;
		while(pos > 0){
			ret += tree[pos];
			// ���� ������ ã�� ���� ���� ��Ʈ�� �����.
			pos &= (pos-1); 
		} 
		return ret;
	}
	//A[pos]�� val�� ���Ѵ�.
	void add(int pos, int val){
		++pos;
		while(pos < tree.size()){
			tree[pos] += val;
			pos += (pos & -pos);
		}
	} 
}; 
