#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int arr[10000];

int clockNumber(string number){
	int Min = 1000000;
	for(int i = 0; i < 4; i++){
		string temp = number.substr(1,3);
		temp += number[0];
		number = temp;
		Min = min(Min, stoi(number));
	}
	return Min;
}


int main(void){
	
	int count = 0;
	string input;
	map<int, int> m;
	for(int i = 0; i < 4; i++){
		int x;
		cin >> x;
		input += to_string(x);
	}
	int ans = clockNumber(input);
	
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			for(int k = 1; k <= 9; k++){
				for(int l = 1; l <= 9; l++){
					int number = i*1000+j*100+k*10+l;
					string temp = to_string(number);
					if(arr[clockNumber(temp)] != 1) {
						arr[clockNumber(temp)] = 1;
						count++;
					}
					/*if(m[clockNumber(temp)] != 1) {
						m[clockNumber(temp)] = 1;
						count++;
					}*/
					if(clockNumber(temp) == ans){
						cout << count << "\n";
						return 0;
					}
				}
			}
		}
	}
	return 0;
}
