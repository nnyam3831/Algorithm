void push_heap(vector<int>& heap, int newValue){
	heap.push_back(newValue);
	
	int index = heap.size() - 1;
	while(index > 0 && (index-1)/2 < heap[index]){
		swap(heap[index], heap[(index-1)/2]);
		index = (index-1)/2;
	}
}

// ������ �ִ� ���� �����ϱ�

void pop_heap(vector<int>& heap){
	// ���� �� �� ���� ��Ʈ���ٰ� �־���
	heap[0] = heap.back();
	heap.pop_back();
	int here = 0; 			// ��Ʈ�������� �����ؼ� ������
	while(1){
		int left = here*2 + 1, right = here*2+2;
		
		// ������ ������ ���  
		if(left >= heap.size()) break;
		// heap[here]�� ������ ��ġ�� ã�´�.
		int next = here;
		if(heap[next] < heap[left]){
			next = left;
		} 
		if(right < heap.size() && heap[next] < heap[right]){
			next = right;
		}
		
		// next�� �ڽĺ��� ũ�Ƿ� ���̻� �ȳ������� ��  
		if(next == here) break;
		swap(heap[here], heap[next]);
		here = next;
	} 
} 
