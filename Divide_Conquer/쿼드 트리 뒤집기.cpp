#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
시간복잡도 : O(n) 
*/

string solve(string::iterator& it){
	char head = *it;
	it++;
	
	if(head == 'w' || head == 'b'){
		return string(1, head);
	}
	vector<string> arr(4);
	for(int i = 0; i < 4; i++){
		arr[i] = solve(it);
	}
	
	return 'x' + arr[2] + arr[3] + arr[0] + arr[1];
}

int main(void){
	
	int N;
	cin >> N;
	while(N--){
		string input;
		cin >> input;
		string::iterator it = input.begin();
		cout << solve(it) << endl;
	}
	return 0;
}
