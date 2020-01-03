#include <iostream>
#include <vector>

using namespace std;

int array[20000];

int main(void){
	
	for(int i = 0; i < 4; i++){
		int a, b, x, y;
		cin >> x >> y >> a >> b;
		for(int col = x; col < a; col++){
			for(int row = y; row < b; row++){
				array[100*row + col] = 1;
			}
		}
	}
	int count = 0;
	for(int i = 0; i < 10010; i++){
		if(array[i] == 1) count++;
	}
	cout << count << "\n";
	return 0;
} 
