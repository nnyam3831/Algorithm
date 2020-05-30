#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>

#define HEAP_SIZE 256
#define ARRAY_SIZE 20

using namespace std;

int heap[HEAP_SIZE];
int heap_count = 0;

void init(){
	heap_count = 0;
}

void push(int data){
	heap[++heap_count] = data;
	int child = heap_count;
	int parent = child / 2;
	// index 1번부터
	while(child > 1 && heap[parent] < heap[child]){
		swap(heap[child], heap[parent]);
		child = parent;
		parent = child / 2;
	} 
}

int pop(){
	int result = heap[1];
	swap(heap[1], heap[heap_count]);
	heap_count--;
	// 다시 heapify 
	int parent = 1;
	int child = parent * 2;
	// children 2개 보다 모두 커야 되기 때문에 큰 쪽으로 바꿔가면서 heapify  
	if(child + 1 <= heap_count){
		child = (heap[child] > heap[child + 1]) ? child: child + 1;
	}
	while(child <= heap_count && heap[parent] < heap[child]){
		swap(heap[parent], heap[child]);
		
		parent = child;
		child = parent * 2;
		if(child + 1 <= heap_count){
			child = (heap[child] > heap[child+1]) ? child : child + 1;
		}
	}
	return result;
}
int main(void){
	
	int arr[ARRAY_SIZE];
	int ans_arr[ARRAY_SIZE];
	
	srand(time(NULL));
	
	for(int i = 0; i < ARRAY_SIZE; i++){
		arr[i] = rand() % 100 + 1;
		ans_arr[i] = arr[i];
	}
	
	for(int i = 0; i < ARRAY_SIZE; i++){
		push(arr[i]);
	}

	vector<int> result;
	for(int i = 0; i < ARRAY_SIZE; i++){
		result.push_back(pop()); 
	}
	// max heap
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << " ";
	}
	cout << "\n";
	return 0;
}
