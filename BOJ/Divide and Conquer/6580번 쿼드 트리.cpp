#include <iostream>
#include <math.h>
using namespace std;

const int MAX_SIZE = 512;

int Map[MAX_SIZE][MAX_SIZE];
string quadtree[MAX_SIZE];

int main(void){
	int N = 0;
	int index = 0;
	int k = 0;
	string temp = "";
	while(1){
		cin >> temp;
		index++;
		if(index == 3){
			for(int i = 0; i < temp.length(); i++){
				N += (temp[i]-'0')*pow(10,temp.length()-i-1);
			}
		}
		int length = temp.length();
		if(temp[0] == '0'){
			// 저장
			cin >> quadtree[k];
			cout << "확인 " << quadtree[k] << endl;
			k++;
		}
		if(temp[0] == '}') break;
	}
	
	for(int i = 0; i < N; i++){
		cout << quadtree[i] << endl;
	}
	return 0;
}
