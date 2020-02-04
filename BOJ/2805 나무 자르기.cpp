#include <iostream>
#include <algorithm>

using namespace std;

long long array[1000001];

int main(void){
	
	int N, M;
	long long high = 0;
	long long result = 0;
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> array[i];
		high = max(high, array[i]);
	}
	long long low = 0;
	
	while(low <= high){
		long long total = 0;
		long long mid = (low + high) / 2;
		for(int i = 0; i < N; i++){
			if(array[i]-mid > 0){
				total += array[i]-mid;
			}
		}
		if(total >= M){
			// ´õ Ä¿µµµÊ 
			low = mid + 1;
			result = max(result, mid);
		}else{
			// ´õ ÀÛ¾Æ¾ßµÊ 
			high = mid - 1; 
		}
	}

	cout << result << "\n";
	return 0;
} 
