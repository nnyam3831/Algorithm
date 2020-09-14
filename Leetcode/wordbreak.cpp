#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 이건 wordDict fisrt임
 
bool wordBreak(string s, vector<string>& wordDict){
	int len = s.length();
	vector<int> cache(len+1, 0);
	cache[0] = 1;
	
	for(int i = 0; i < len; i++){
		if(cache[i] == 0) continue;
		for(auto& word : wordDict){
			int word_len = word.length();
			if(word_len <= len - i && s.substr(i, word_len) == word){
//				 만약에 대응하는 word가 있다면?
//				 i + word_len까지는 문장이 완성될 수 있다.
 				cache[i + word_len] = 1;
				 // 전체길이 + 1까지 와야 성공하는 것	
			}
		}
	}
	return cache[len];
}
int main(void){

	string s1 = "leetcode";
	vector<string> wd1 = {"leet", "code"};
	string s2 = "applepenapple";
	vector<string> wd2 = {"apple", "pen"};
	string s3 = "catsandog";
	vector<string> wd3 = {"cats", "dog", "sand", "and", "cat"};
	cout << wordBreak(s1, wd1) << "\n";
	cout << wordBreak(s2, wd2) << "\n";
	cout << wordBreak(s3, wd3) << "\n";
	return 0;
}
