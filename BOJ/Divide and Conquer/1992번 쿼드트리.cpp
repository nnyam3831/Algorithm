#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const int MAX_SIZE = 64;

char Map[MAX_SIZE][MAX_SIZE];

char check(int y, int x, int size){
	bool flag = true;
	if(size == 1) return Map[y][x];
	char c = Map[y][x]; 
	for(int i = y; i < y+size; i++){
		
		for(int j = x; j < x+size; j++){
			if(c != Map[i][j]) flag = false;
		}
	}
	if(flag) return c;
	return 'z';
}

void quadTree(int y, int x, int size){
	

	if(check(y, x, size) == '1'){
		cout << "1";
		return;
	}
	else if(check(y,x, size) == '0'){
		cout << "0";
		return;
	}
	else{
		size = size / 2;
		
		cout << "(";
		quadTree(y, x, size);
		quadTree(y, x+size, size);
		quadTree(y+size, x, size);
		quadTree(y+size, x+size, size);
		cout << ")";
	}
	

}
int main(void){
	
	int N;
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> Map[i][j];
		}
	}
	quadTree(0, 0, N);
	return 0;
}
