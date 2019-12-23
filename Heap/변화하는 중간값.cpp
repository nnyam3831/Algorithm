
// runningMedian NlgN

int runningMedian(int n, RNG rng){
	priority_queue<int, vector<int>, less<int>> maxHeap;	// 내림차순
	priority_queue<int, vector<int>, greater<int>> minHeap;		// 오름차순
	int ret = 0;
	// 반복문 불변식
	// 1.maxHeap의 크기는 minHeap의 크기와 같거나 1 더 크다
	// 2.maxHeap.top() <= minHeap.top()
	
	for(int cnt = 1; cnt <= n; cnt++){
		// 우선 1번 불변식부터 만족
		if(maxHeap.size() == minHeap.size()){
			maxHeap.push(rng.next());
		} 
		else
		{
			minHeap.push(rng.next());
		}
		if(!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()){
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}
		ret = (ret + maxHeap.top()) % 20090711;
	} 
	return ret;
}
