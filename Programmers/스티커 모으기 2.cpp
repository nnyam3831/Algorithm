#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> sticker){
	
	int answer = 0;
	vector<int> Dp(sticker.size(), 0);
	
	if(sticker.size() == 1){
		return sticker[0];
	}else if(sticker.size() == 2){
		return answer = max(sticker[0], sticker[1]);
	}else if(sticker.size() == 3){
		return answer = max(sticker[0] + sticker[2], sticker[1]);
	}
	Dp[0] = sticker[0];
	Dp[1] = Dp[0];
	
	for(int i = 2; i < sticker.size(); i++){
		Dp[i] = max(Dp[i-2] + sticker[i], Dp[i-1]);
	}
	Dp[sticker.size()-1] = max(Dp[sticker.size()-2], Dp[sticker.size()-3]);
	
	answer = Dp[sticker.size()-1];


	 Dp[0] = 0;
	 Dp[1] = sticker[1];
	 for(int i = 2; i < sticker.size(); i++){
		Dp[i] = max(Dp[i-2] + sticker[i], Dp[i-1]);
	}
	answer = max(answer, Dp[sticker.size()-1]);

	return answer;
} 

int main(void){
//	solution({14,6,5,11,3,9,2,10});
	solution({1,3,2,5,4});
	return 0;
}
