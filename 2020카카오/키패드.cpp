#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <vector>
using namespace std;

// O(N)
string solution(vector<int> numbers, string hand){
	string answer = "";
	map<char, pair<int,int>> pos;
	pos['1'] = {0,0};
	pos['2'] = {1,0};
	pos['3'] = {2,0};
	pos['4'] = {0,1};
	pos['5'] = {1,1};
	pos['6'] = {2,1};
	pos['7'] = {0,2};
	pos['8'] = {1,2};
	pos['9'] = {2,2};
	pos['*'] = {0,3};
	pos['0'] = {1,3};
	pos['#'] = {2,3};
	char left = '*', right = '#';
	// simulation (first *, #)
	for(int i = 0; i < numbers.size(); i++){
		if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
			answer += 'L';
			left = numbers[i] + '0';
		}
		if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
			answer += 'R';
			right = numbers[i] + '0';
		}
		if(numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0){
			int index = numbers[i] + '0';
			int leftDist = abs(pos[index].first - pos[left].first) + abs(pos[index].second - pos[left].second);
			int rightDist = abs(pos[index].first - pos[right].first) + abs(pos[index].second - pos[right].second);
			if(leftDist < rightDist){
				answer += "L";
				left = index;
			}else if(leftDist > rightDist){
				answer += "R";
				right = index;
			}else{
				if(hand == "left"){
					answer += "L";
					left = index;
				}else{
					answer += "R";
					right = index;
				}
			}
		}
	}
	return answer;
}
int main(void){
	vector<int> input1 = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
	vector<int> input2 = {7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2};
	vector<int> input3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	cout << solution(input1, "right") << "\n";
	cout << solution(input2, "left") << "\n";
	cout << solution(input3, "right") << "\n";
	return 0;
}
