#include <iostream>
#include <string>
#include <vector>
using namespace std;

// �̰� wordDict fisrt��
 
bool wordBreak(string s, vector<string>& wordDict){
	int len = s.length();
	vector<int> cache(len+1, 0);
	cache[0] = 1;
	
	for(int i = 0; i < len; i++){
		if(cache[i] == 0) continue;
		for(auto& word : wordDict){
			int word_len = word.length();
			if(word_len <= len - i && s.substr(i, word_len) == word){
//				 ���࿡ �����ϴ� word�� �ִٸ�?
//				 i + word_len������ ������ �ϼ��� �� �ִ�.
 				cache[i + word_len] = 1;
				 // ��ü���� + 1���� �;� �����ϴ� ��	
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
