#include <iostream>
#include <vector>

using namespace std;

vector<int> makeTable(string pattern){
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	
	int j = 0;
	for(int i = 1; i < patternSize; i++){
		while(j > 0 && pattern[i] != pattern[j]){
			// 바로 직전까지는 일치했었음 
			j = table[j-1];
		}
		if(pattern[i] == pattern[j]){
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string target, string pattern){
	vector<int> table = makeTable(pattern);
	int targetSize = target.size();
	int patternSize = pattern.size();
	int j = 0;
	for(int i = 0; i < targetSize; i++){
		while(j > 0 && target[i] != pattern[j]){
			j = table[j-1];
		}
		if(target[i] == pattern[j]){
			if(j == patternSize-1){
				cout << i-patternSize+2 << "발견\n";
				j = table[j];
			}else{
				j++;
			}
		}
	} 
}
int main(void){
	
	string target = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	KMP(target, pattern);
	return 0;
}
