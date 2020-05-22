#include <iostream>
#include <vector>
using namespace std;


int solution(int n, vector<int> stations, int w)
{
	int length = 2*w + 1;
	int ans= 0;
	int index = 0;
	for(int i = 0; i < stations.size(); i++){
		if(stations[i] - w - 1 > index){
			ans = ans + 1 + (stations[i]-w-2-index)/length;
		}
		if(i == stations.size()-1){
			if(n-stations[i]-w > 0){
				// 남아 있음
				ans = ans + 1 +(n-stations[i]-w-1)/length; 
			}
		}
		index = stations[i] + w + 1;
	}
	return ans;
}

int main(void){
	cout << solution(11, {4, 11}, 1) << "\n";
	cout << solution(16, {9}, 2) << "\n";
	return 0;
} 
