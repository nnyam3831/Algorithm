// leetcode no.17 Letter Combinations of a Phone Number

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dial = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> store = {""};
		for(int i = 0; i < digits.length(); i++){
        	int index = digits[i] - '0';
        	vector<string> temp;
			temp.assign(store.begin(), store.end());
			store.clear();
			for(auto& elem : temp){
				for(int j = 0; j < dial[index].length(); j++){
					string c = dial[index].substr(j, 1);
					store.push_back(elem + c);
				}
			}
		}
		return store;
    }
};

int main(void){
	string input = "23";
	Solution sol;
	vector<string> result = sol.letterCombinations(input);
	for(auto& elem: result){
		cout << elem << " ";
	}
	cout << "\n";
	return 0;
}
