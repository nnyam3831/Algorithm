#include <iostream>
#include <string>
#include <math.h>
using namespace std;

const int MAX_SIZE = 512;
const char Hex[17] = "0123456789abcdef";
int Map[MAX_SIZE][MAX_SIZE];
string temp="";

string ToHex(int y, int x){
	int first = 0;
	int second = 0;
	for(int i = x; i < x+4; i++){
		first += pow(2,i-x)*Map[y][i];
	}
	for(int i = x+4; i < x+8; i++){
		second += (pow(2, i-x-4)*Map[y][i]);
	}
	first = Hex[first];
	second = Hex[second];
	string ret = "0x";
	ret += second;
	ret += first;
	
	return 	ret;
}

void fillMap(int y, int x, int size, int type){
	for(int i = y; i < y+size; i++){
		for(int j = x; j < x+size; j++){
			Map[i][j] = type;
		}
	}
}
void solve(int y, int x, int size){

	if(temp[0] == 'W'){
		
		fillMap(y, x, size, 0);
		temp.erase(0,1);
		return;
	}else if(temp[0] == 'B'){
	
		fillMap(y, x, size, 1);	
		temp.erase(0,1);
		return;
		
	}else{
		size = size/2;
		temp.erase(0,1);
		solve(y, x, size);
		solve(y, x+size, size);
		solve(y+size, x, size);
		solve(y+size, x+size, size);
	}
}
int main(void)
{
	int N;
	cin >> N;
	cin >> temp;
	solve(0, 0, N);
	
	printf("#define quadtree_width %d\n", N);
	printf("#define quadtree_height %d\n", N);
	printf("static char quadtree_bits[] = {\n");
	for(int y = 0; y < N; y++){
		int index = 0;
		for(int x = 0; x < N/8; x ++){
			cout << ToHex(y, x*8);
			cout << ",";
		}
		cout << "\n";
	}
	
	printf("};");
	return 0;
}
