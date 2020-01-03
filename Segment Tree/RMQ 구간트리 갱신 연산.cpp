struct RMQ{
	// ����....
	//array[index] = newValue�� �ٲ���� �� node�� ��Ʈ�� �ϴ� ����Ʈ���� �����ϰ� ��尡 ǥ���ϴ�
	// ������ �ּ�ġ�� ����
	int update(int index, int newValue, int node, int nodeLeft, int nodeRight){
		//index�� ��尡 ǥ���ϴ� ������ ������� ���� ��� ����
		if(index < nodeLeft || nodeRight < index)
			return rangeMin[node];
		// Ʈ���� �������� ������ ���
		if(nodeLeft == nodeRight) return rangeMin[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeMin[node] = min(update(index, newValue, node*2, nodeLeft, mid),
		update(index, newValue, node*2+1, mid+1, nodeRight)); 
	} 
	
	int update(int index, int newValue){
		return update(index, newValue, 1, 0, n-1);
	}
};
