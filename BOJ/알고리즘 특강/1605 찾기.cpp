#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


bool isAnagram(string s1, string s2){
	map<char, int> m;
	for(char str : s1){
		if(m.find(str) == m.end()){
			m[str] = 1;
		}else{
			m[str]++;
		}
	}
	bool flag = true;
	for(char str : s2){
		if(m.find(str) == m.end()){
			flag = false;
			break;
		}
		m[str]--;
		if(m[str] < 0){
			flag = false;
			break;
		}
	}
	for(auto iter = m.begin(); iter != m.end(); iter++){
		if(iter->second != 0){
			flag = false;
			break;
		}
	}
	return flag;
}
bool isRotated(string s1, string s2){
	if(s1.length() != s2.length()) return false;
	
	int len = s2.length();
	string temp = s2;
	for(int i = 0; i < len; i++){
		temp = temp.substr(1, len-1) + temp.substr(0,1);
		
		if(temp == s1){
			return true;
		}
	}
	return false;
	
}
int main(void){
	
	string s1, s2;
	cin >> s1 >> s2;
//	if(isAnagram(s1, s2)){
//		cout << "anagram\n";
//	}else{
//		cout << "no\n";
//	}
	if(isRotated(s1, s2)){
		cout << "rotated\n";
	}else{
		cout << "no\n";
	}
	string test = "0123456789";
	cout << test.substr(0, 2) << "\n";
	cout << test.substr(1, 8) << "\n";
	cout << test.substr(9,20).length() << "\n";
	cout << test << "\n";
	return 0;
}
