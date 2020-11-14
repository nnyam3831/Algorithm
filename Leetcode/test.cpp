#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int n = 5;
	vector<char> s(n);
	s[0] = 'A';
	s[1] = 'A' + 1;
	for(auto& elem: s){
		cout << elem << " ";
	}
	return 0;
}
