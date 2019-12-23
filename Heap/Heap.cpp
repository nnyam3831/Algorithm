void push_heap(vector<int>& heap, int newValue){
	heap.push_back(newValue);
	
	int index = heap.size() - 1;
	while(index > 0 && (index-1)/2 < heap[index]){
		swap(heap[index], heap[(index-1)/2]);
		index = (index-1)/2;
	}
}

// 힙에서 최대 원소 삭제하기

void pop_heap(vector<int>& heap){
	// 힙의 맨 끝 값을 루트에다가 넣어줌
	heap[0] = heap.back();
	heap.pop_back();
	int here = 0; 			// 루트에서부터 시작해서 내려감
	while(1){
		int left = here*2 + 1, right = here*2+2;
		
		// 리프에 도달한 경우  
		if(left >= heap.size()) break;
		// heap[here]가 내려갈 위치를 찾는다.
		int next = here;
		if(heap[next] < heap[left]){
			next = left;
		} 
		if(right < heap.size() && heap[next] < heap[right]){
			next = right;
		}
		
		// next가 자식보다 크므로 더이상 안내려가도 됨  
		if(next == here) break;
		swap(heap[here], heap[next]);
		here = next;
	} 
} 
