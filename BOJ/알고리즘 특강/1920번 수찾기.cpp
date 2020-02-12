#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int array[MAX];
int check[MAX];
int N, M;

bool isExist(int number){
	
	int high = N;
	int low = 0;
	while(1){
		if(high == low) break;
		
		int mid = (high + low) / 2;
		if(number > array[mid]){
			low = mid+1;
		}else if(number < array[mid]){
			high = mid;
		}else if(number == array[mid]){
			return true;
		}
		
	}
	return false;
}
int main(void){
	
	cin >> N;
	for(int i = 0; i < N; i++) cin >> array[i];
	cin >> M;
	for(int i = 0; i < M; i++) cin >> check[i];
	
	sort(array, array+N);
	for(int i = 0; i < M; i++){
		if(isExist(check[i])) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}
