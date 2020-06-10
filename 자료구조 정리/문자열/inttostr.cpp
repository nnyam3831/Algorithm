#include <iostream>
using namespace std;

string IntToString(int num){
	string temp = "";
	int size = 0;
	bool isNeg = num < 0;
	if(isNeg) num = -num;
	while(1){
		int mod = num % 10;
		temp += (mod + '0');
		num /= 10;
		size++;
		if(num == 0) break;
	}
	string ret = isNeg ? "-": "";
	for(int i = size - 1; i >= 0; i--){
		ret += temp[i];
	}
	return ret;
}
int main(void){
	
	cout << IntToString(0) << "\n";
	cout << IntToString(1) << "\n";
	cout << IntToString(-1) << "\n";
	cout << IntToString(387) << "\n";
	cout << IntToString(-214783648) << "\n";
	
	return 0;
}
