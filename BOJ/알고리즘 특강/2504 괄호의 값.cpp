#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(void){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string input;
	cin >> input;
	stack<char> s;
	
	long long result = 0;
	int temp = 1;
	bool flag = true;
	for(int i = 0; i < input.length(); i++){
		if(input[i] == '('){
			temp *= 2;
			s.push(input[i]);
		}else if(input[i] == '['){
			temp *= 3;
			s.push('[');
		}else if (input[i] == ')' && (s.empty() || s.top() != '(')){
			flag = false;
			break;
		}else if (input[i] == ']' && (s.empty() || s.top() != '[')){
			flag = false;
			break;
		}
		else if(input[i] == ')'){
			if(input[i-1] == '('){
				// 매칭 되는 경우만 값을 더해주고 갱신해주면 된다.
				result += temp; 
			}
			s.pop();
			temp /= 2;
		}else if(input[i] == ']'){
			if(input[i-1] == '['){
				result += temp;
			}
			s.pop();
			temp /= 3;
		}
	}
	if(!s.empty() || !flag) cout << 0 << "\n";
	else cout << result << "\n";
	return 0;
}
