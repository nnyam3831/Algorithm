#include <iostream>

using namespace std;

void fail(int k){
	while(--k){
		cout << 'x';
	}
	cout << "\n";
	exit(EXIT_SUCCESS);
}

int main(void){
	
	string lines[1005];
	string top = "";
	string bottom = "";
	string ans = "";
	int k, n, q;
	cin >> k >> n;
	cin >> bottom;
	
	for(int i = 0; i < k; i++){
		top += ('A'+i);
	}
	for(int i = 0; i < n; i++){
		cin >> lines[i];
		if(lines[i][0] == '?') q = i;
	}
	for(int i = 0; i < q; i++){
		for(int j = 0; j < lines[i].length(); j++){
			char ch = lines[i][j];
			if(ch == '-'){
				swap(top[j], top[j+1]);
			}
		}
	}
	for(int i = n-1; i > q; i--){
		for(int j = 0; j < lines[i].length(); j++){
			char ch = lines[i][j];
			if(ch == '-'){
				swap(bottom[j], bottom[j+1]);
			}
		}
	}
	
	//check
	for(int i = 0; i < k-1; i++){
		char up = top[i];
		char down = bottom[i];
		if(up != down){
			ans += "-";
			if(i+2 < k){
				ans += "*";
				i++;
			}
			
		}else{
			ans += "*";
		}
	}
	for(int i = 0; i < ans.length(); i++){
		if(ans[i] == '-'){
			swap(top[i], top[i+1]);
		}
	}
	if(top != bottom) fail(k);
	cout << ans << "\n";
	return 0;
}
