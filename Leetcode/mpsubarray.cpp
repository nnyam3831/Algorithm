#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nusm.size(), ret = nums[0], left = 0, right = 0;
        for(int i = 0; i < size; i++){
        	left = (left ? left : 1) * nums[i];
        	right = (right ? right : 1) * nums[n-i-1];
        	ret = max(ret, max(left, right));
		}
		return ret;
    }
};
