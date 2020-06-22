#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        int size = s.length();
        map<char,int> dict;
        int start = 0, end = 0, counter = 0;
        for(int end = 0; end < size;){
        	char c = s[end];
        	dict[c] = dict[c] + 1;	end++;
        	if(dict[c] > 1){
        		counter += 1;
			}
			while(counter > 0){
				char tempc = s[start];
				if(dict[tempc] > 1){
					counter--;
				}
				dict[tempc]--;
				start++;
			}
			ret = max(ret, end - start);
		}
		return ret;
    }
};


int main(void){
	
	Solution sol;
	cout << sol.lengthOfLongestSubstring("abcabcbb") << "\n";
	cout << sol.lengthOfLongestSubstring("bbbbb") << "\n";
	cout << sol.lengthOfLongestSubstring("pwwkew") << "\n";
	return 0;
}
