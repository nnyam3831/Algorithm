#include <iostream>
#include <vector>
#define MAX 102

using namespace std;

int L, N;
int A[MAX],T[MAX],D[MAX];
int INF = 10000000;
int Dynamic(){
	D[0] = 0;
	for(int i = 1; i <= N+1; i++){
		for(int j = i-1; j >= 0; j--){
			if(A[i]-A[j] <= L){
				if(D[j] + T[i] < D[i]){
					D[i] = D[j] + T[i];
				}
			}
		}
	}
}
int main(void){
	
	return 0;
}
