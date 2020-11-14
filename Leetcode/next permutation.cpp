#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      	int size = nums.size();
      	int targetIndex = 0;
		for(int i = size-1; i > 0; i--){
			if(nums[i-1] < nums[i]){
				targetIndex = i-1;
				break;
			}
		}
		reverse(nums.begin() + targetIndex + 1, nums.end());
		if(targetIndex != -1){
			int target = nums[targetIndex];
			for(int i = targetIndex + 1; i < size; i++){
				if(target < nums[i]){
					swap(nums[targetIndex], nums[i]);
					break;
				}
			}
		} 
    } 
};

int main(void){
	Solution s;
	vector<int> input1 = {1,2,3};
	vector<int> input2 = {5,4,3,2,1};
	vector<int> input3 = {3,2,1};
	vector<int> input4 = {1,1,5};
	vector<int> input5 = {3,5,4,2,1};
	
	s.nextPermutation(input1);
	s.nextPermutation(input2);
	s.nextPermutation(input3);
	s.nextPermutation(input4);
	s.nextPermutation(input5);
	
	return 0;
}
