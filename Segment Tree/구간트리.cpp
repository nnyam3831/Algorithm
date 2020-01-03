

// ���� Ʈ�� ����, �ʱ�ȭ, ���� �ּ� ���� O(n)
struct RMQ{
	// �迭�� ����
	int n;
	// �� ������ �ּ�ġ
	vector<int> rangeMin;
	RMQ(const vector<int>& array){
		n = array.size();
		rangeMin.resize(n*4);			// or n �ø� * 2 
		init(array, 0, n-1, 1);
	} 
	// node ��尡 array[left..right]�迭�� ǥ���� ��
	// node�� ��Ʈ�� �ϴ� ����Ʈ���� �ʱ�ȭ�ϰ�, �� ������ �ּ�ġ�� ��ȯ�Ѵ�.
	int init(const vector<int>& array, int left, int right, int node){
		if(left == right)
			return rangeMin[node] = array[left];
		int mid = (left+right) / 2;
		int leftMin = init(array, left, mid, node*2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return rangeMin[node] = min(leftMin, rightMin);
	} 
}; 


// Query ���� ���� O(lgn)
const int INT_MAX = numeric_limits<int>::max();
struct RMQ{
	//node�� ǥ���ϴ� ���� array[nodeleft, noderight] �� �־��� ��
	//�� ������ array[left,right]�� �������� �ּ�ġ�� ���Ѵ�.
	int query(int left, int right, int node, int nodeleft, int nodeRight){
		// �� ������ ��ġ�� ������ ���� ū �� ����
		if(right < node Left || nodeRight < left) return INT_MAX;
		if(left <= nodeLeft && nodeRight <= right)
			return rangeMin[node];
		// �� �ܿ��� ���ʱ����� �ٽ� ���
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node*2, nodeLeft, mid), query(left, right, node*2+1, mid+1, nodeRight)); 
	} 
	int query(int left, int right){
		return query(left, right, 1, 0, n-1);
	}
}; 
