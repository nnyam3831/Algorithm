#include <iostream>
#include <math.h>
using namespace std;

// 최대공약수 구하기 
long long gcd(int a, int b){
	if(!b) return a;
	if(a > b) return gcd(b, a%b);
	return gcd(a, b % a);
}

int main(void){
	
	long long G, L;
	long long result = 1000000000;
	cin >> G >> L;
	long long num = L / G;
	long long A, B;
	
	for(int i = 1; i <= sqrt(num); i++){
		if(num % i != 0) continue;
		if(gcd(i, num/i) == 1){
			if(result > i + num/i){
				result = i + num/i;
				A = G * i;
				B = G * num/i;
			}
		}
	}
	
	cout << A << " " << B << "\n";
	return 0;
}
