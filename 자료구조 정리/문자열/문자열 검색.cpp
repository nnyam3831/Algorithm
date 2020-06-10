// 첫 번째로 중복되지 않는 값을 찾는다고 생각하자
 
#include <iostream>
#include <string>
using namespace std;

int table[27];
int main(void){
	
	string parent = "aldksjaldksjdlasjdlasjfnanwnesbdbqasez";
	cout << 
	// table 구성
	for(int i = 0; i < parent.length(); i++){
		table[parent[i]-'a']++;
	}	
	for(int i = 0; i < parent.length(); i++){
		char key = parent[i];
		if(table[key-'a'] == 1){
			cout << key << "값이 처음으로 반복되지 않은 character !!, index: " << i << "\n"; 
		}
	}
	return 0;
}
