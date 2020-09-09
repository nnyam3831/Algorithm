#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
// sliding window, O(N)
using namespace std;

vector<int> solution(vector<string> gems){
	vector<int> answer;
	vector<string> required;
	set<string> filter;
	map<string, int> count;
	
	for(auto& gem : gems){
		filter.insert(gem);
		count[gem] = 0;
	}
	required.assign(filter.begin(), filter.end());
	int start = 0, end = 0, total = 1;
	count[gems[0]] = 1;
	
	answer.push_back(-1);
	answer.push_back(1000000);
	while(end < gems.size() && start <= end)
	{
		if(total == required.size()){
			if(end-start < answer[1]-answer[0]){
				answer = {start+1, end+1};
			}
			if(--count[gems[start++]] == 0) total--;
		}else{
			end++;
			if(end >= gems.size()) break;
			if(++count[gems[end]] == 1) total++;
		}
	}
	return answer;
}

int main(void){
	
	vector<string> input1 = {"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"};
	vector<string> input2 = {"AA", "AB", "AC", "AA", "AC"};
	vector<string> input3 = {"XYZ", "XYZ", "XYZ"};
	vector<string> input4 = {"ZZZ", "YYY", "NNNN", "YYY", "BBB"};
	
	cout << solution(input1)[0] << " " << solution(input1)[1] << "\n";
	cout << solution(input2)[0] << " " << solution(input2)[1] << "\n";
	cout << solution(input3)[0] << " " << solution(input3)[1] << "\n";
	cout << solution(input4)[0] << " " << solution(input4)[1] << "\n";
	return 0;
}
