#include <iostream>
#include <string>
using namespace std;

void findString(string target, string pattern){
	int targetSize = target.size();
	int patternSize = pattern.size();
	int targetHash = 0, patternHash = 0, power = 1;
	
	for(int i = 0; i <= targetSize - patternSize; i++){
		if(i == 0){
			// 첫번째면 hash값 다 만들기(길이 patternSize만큼)
			for(int j = 0; j < patternSize; j++){
				targetHash = targetHash + power * target[patternSize-j-1];
				patternHash = patternHash + power * pattern[patternSize-j-1];
				if(j < patternSize-1) power *= 2;
			} 
		}else{
			targetHash = 2*(targetHash - target[i-1] * power) + target[i+patternSize-1];
		}
		if(targetHash == patternHash){
			cout << "찾았다 target: " << target.substr(i, patternSize) << "\n";
			cout << "index는  " << i << "\n";
		}
	}	

}

int main(void){
	string target = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	findString(target, pattern);
	return 0;
}
