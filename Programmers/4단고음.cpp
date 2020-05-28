#include <cmath>
#include <iostream>

using namespace std;

int find(int n, int plusCount){
	int result = 0;
	
	if(n < 1 || 2*log(n)/log(3) < plusCount){
		return 0;
	} else if(n == 3 && plusCount == 2){
		return 1;
	}else if(n == 3 && plusCount == 3){
		return 0;
	}
	
	if(n % 3 == 0 && plusCount >= 2){
		result += find(n/3, plusCount-2);
	}
	
	result += find(n-1, plusCount+1);
	
	return result;
}
int solution(int n){
	int answer = 0;
	return find(n-2, 2);	
}

int main(void){
	cout << solution(15) << "\n";
	cout << solution(24) << "\n";
	cout << solution(41) << "\n";
	cout << solution(2147483647) << "\n";
	return 0;
}
