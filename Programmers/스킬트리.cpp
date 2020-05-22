// N * logN * 20

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int curIndex = 0;
 	for(int i = 0; i < skill_trees.size(); i++){
 		int curIndex = 0;
 		bool flag = true;
 		for(int j = 0; j < skill_trees[i].size(); j++){
 			char s = skill_trees[i][j];
			if(skill.find(s) == curIndex){
				curIndex++;
			}else if(skill.find(s) >= skill.size()){
				continue;
			}else{
				flag = false;
				break;
			}
		}
		
		if(flag) {
			answer++;
		}
	}
    return answer;
}

int main(void){
	solution("CBD", {"BACDE", "CBADF", "AECB", "BDA"});
	return 0;
}
