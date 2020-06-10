#include <iostream>
#include <algorithm>
#define MAX 100000 + 1
using namespace std;

int heap[MAX];
int size;

void push(int data){
	heap[++size] = data;
	// heapify
	int index = size;
	while(1){
		if(heap[index] > heap[index/2]) break;
		if(index < 1) break;
		swap(heap[index] ,heap[index/2]);
		index /= 2;
	}
}

int pop(){
	int ret = heap[1];
	heap[1] = heap[size--];
	int index = 1;
	while(1){
		if(2*index > size) break;
		// 더 작은 쪽으로 
		if(heap[index] < heap[2*index] && heap[index] < heap[2*index+1]) break;
		if(heap[2*index] > heap[2*index+1]){
			swap(heap[index], heap[2*index+1]);
			index = index*2 + 1;
		}else{
			swap(heap[index], heap[2*index]);
			index = index*2;
		}
	}
	return ret;
}
int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		int data;
		cin >> data;
		if(data == 0){
			size == 0 ? cout << 0 << "\n" : cout << pop() << "\n";
		}else{
			push(data);
		}
	}
	return 0;
}
