#include <iostream>
#include <algorithm>

using namespace std;

int Crain[52];
int Box[10002];
int Buff[52];
int zeroCount;
bool cmp(const int A, const int B)
{
	return A > B;
}
int main(void)
{
	int N, M;
	int result = 0;
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> Crain[i];
	cin >> M;
	for(int i = 1; i <= M; i++) cin >> Box[i];
	
	sort(Crain+1, Crain+(N+1), cmp);
	sort(Box+1, Box+(M+1), cmp);
	int temp = 0;
	int index = 1;
	if(Crain[1] < Box[1]) cout << -1 << endl;
	else
	{
	int i = 1;
	int total = 0;
	while(1)
	{
		if(Crain[index] >= Box[i] && Box[i] > Crain[index+1])
		{
			Buff[index]++;
			total++;
			i++;
		}
		else
		{
			index++;
		}
		if(i == M+1) break;
	}

	// Buff에 낮은 무게 가능한 크레인 순서대로 할당량이 들어가 있음

	int time = 0;
	while(1)
	{
		bool flag = true;
		zeroCount = 0;
		for(int i = 1; i <= N; i++)
		{
			if(Buff[i])
			{
				flag = false;
				if(Buff[i] > zeroCount+1)
				{
					Buff[i] = Buff[i] - zeroCount - 1;
					zeroCount = 0;
				}
				else
				{
					zeroCount = zeroCount+2-(Buff[i]);
					Buff[i] = 0;
				}
			}
			else	// Buff[i] = 0이면
			{
				zeroCount++;
			}
		
		}
		
		if(flag) break;
		time++;
		
	} 
	
	cout << time << endl;
} 
	return 0;
}
