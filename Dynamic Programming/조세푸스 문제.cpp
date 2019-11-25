/*
AlgoSpot(ID: JOSPHUS)
���� ����Ʈ  
N�� ���ؼ� k�� �Ű���
O(NK) 
*/

void josephus(int n, int k){
	// ����Ʈ
	list<int> survivors;
	for(int i = 1; i <= n; i++) survoviors.push_back(i);
	// �̹��� ���� ����� ��Ÿ���� ������
	list<int>::iterator kill = survivors.begin();
	while(n > 2){
		// ù ��° ����� �ڻ�. erase()�� ���� ������ ���� ���Ҹ� ������
		kill = survivors.erase(kill);
		// ���̸� ó������ ���ư�(���� ����) 
		if(kill == survivors.end()) kill = survivors.begin();
		--n;
		// k-1�� ���� ������� �ű�
		for(int i = 0; i < k-1; i++){
			++kill;
			if(kill == survivors.end()) kill = survivors.begin();
		} 
	} 
	cout << survivors.front() << " " << survivors.back() << "\n";
} 
