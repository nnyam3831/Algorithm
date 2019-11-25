/*
AlgoSpot(ID: JOSPHUS)
연결 리스트  
N명에 대해서 k번 옮겨짐
O(NK) 
*/

void josephus(int n, int k){
	// 리스트
	list<int> survivors;
	for(int i = 1; i <= n; i++) survoviors.push_back(i);
	// 이번에 죽을 사람을 나타내는 포인터
	list<int>::iterator kill = survivors.begin();
	while(n > 2){
		// 첫 번째 사람이 자살. erase()는 지운 원소의 다음 원소를 리턴함
		kill = survivors.erase(kill);
		// 끝이면 처음으로 돌아감(원형 구현) 
		if(kill == survivors.end()) kill = survivors.begin();
		--n;
		// k-1번 다음 사람으로 옮김
		for(int i = 0; i < k-1; i++){
			++kill;
			if(kill == survivors.end()) kill = survivors.begin();
		} 
	} 
	cout << survivors.front() << " " << survivors.back() << "\n";
} 
