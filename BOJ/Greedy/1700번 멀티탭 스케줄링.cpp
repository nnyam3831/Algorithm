#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100 + 1;

int N, K;
int schedule[MAX], plug[MAX];

int main(void)
{
	cin >> N >> K;
	
	for(int i = 0; i < K; i++)
	{
		cin >> schedule[i];
	}
	int result = 0;
	
	for(int i = 0; i < K; i++)
	{
		bool pluggedIn = false;
		// 해당 기기 꽂혀있는지 확인임 
		for(int j = 0; j < N; j++)
		{
			if(plug[j] == schedule[i])
			{
				pluggedIn = true;
				break;
			}
		} 
		if(pluggedIn)
			continue;
			
		for(int j = 0; j < N; j++)
		{
			if(!plug[j])
			{
				plug[j] = schedule[i];
				pluggedIn = true;
				break;
			}
		}
		if(pluggedIn)
			continue;
			
		// 가장 나중에 다시 사용되거나 아픙로 사용되지 않는 기기 찾기 
		int idx, deviceIdx = -1;
		for(int j = 0; j < N; j++)
		{
			int lastIdx = 0;
			for(int k = i+1; k < K; k++)
			{
				if(plug[j] == schedule[k])
					break;
				lastIdx++;
			}
			if(lastIdx > deviceIdx)
			{
				idx = j;
				deviceIdx = lastIdx;
			}
		} 
		result++;
		plug[idx] = schedule[i];
	}
	cout << result << endl;
	return 0;
}
