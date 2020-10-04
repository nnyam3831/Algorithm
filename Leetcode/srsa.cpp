#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        while (lo <= hi){
        	int mid = (lo + hi) / 2;
        	// check same side 
        	double num = (nums[mid] < nums[0]) == (target < nums[0])
        				? nums[mid]
        				: target < nums[0] ? -INF : INF;
        				
        	if (num < target) lo = mid + 1;
        	else if (num > target) hi = mid - 1;
        	else return mid;
		}
		return -1;
    }
};

int main(void){
	vector<int> input1 = {4,5,6,7,0,1,2};
	vector<int> input2 = {1};
	vector<int> input3 = {4,5,6,7,8,0,1,2};
	Solution s;
	cout << s.search(input1, 0) << "\n";
	cout << s.search(input1, 3) << "\n";
	cout << s.search(input2, 0) << "\n";
	cout << s.search(input3, 2) << "\n";
	return 0;
}
