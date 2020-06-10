#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#define MAX 100000 + 1

using namespace std;
int heap[MAX];
int size;


void push(int value){
	heap[++size] = value;
	for(int i = size; i > 1; i /= 2){
		if(heap[i] > heap[i/2]){
			swap(heap[i], heap[i/2]);
		}else{
			break;
		}
	}
}
int pop(){
	int ret = heap[1];
	heap[1] = heap[size];
	heap[size--] = 0;

	for(int i = 1; i*2 <= size;){
		if(heap[i] > heap[i*2] && heap[i] > heap[i*2 + 1]){
			break;
		}else if(heap[i*2] > heap[i*2 + 1]){
			swap(heap[i], heap[i*2]);
			i = i*2;
		}else{
			swap(heap[i], heap[i*2 + 1]);
			i = i * 2 + 1;
		}
	}
	return ret;
}

int main(void){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		int input;
		cin >> input;
		if(input == 0){
			size == 0 ? cout << 0 << "\n" : cout << pop() << "\n";
		}else{
			push(input);
		}
	}
	return 0;
}
