#include <iostream>
#include <algorithm>

using namespace std;

struct Station{
	int distance;
	int energy;
};

bool cmp(const Station &A, const Station &B)
{
	if(A.distance == B.distance) return A.energy < B.energy;
	return A.distance < B.distance;
}

bool cmp2(const Station &A, const Station &B)
{
	return A.energy > B.energy;
}
Station Arr[10002];
int main(void)
{
	int N;
	int desti;
	int cnt = 0;
	Station Current;
	Current.distance = 0;
	
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		cin >> Arr[i].distance >> Arr[i].energy;
	}
	cin >> desti >> Current.energy;
	
	Arr[N+1].distance = desti;
	sort(Arr+1, Arr+(N+1), cmp);

	for(int i = 1; i <= N+1; i++)
	{
		while(1)
		{
			if(Arr[i].distance <= Current.energy) break;
			
			sort(Arr+1, Arr+i, cmp2);
			if(Arr[1].energy == 0) // 제일 큰 게 0 이면 앞으로 나아갈 수 없음 = 도착할 수 없음 
			{
				Current.energy = 0;
				break;
			}
			Current.energy += Arr[1].energy;
			Arr[1].energy = 0; 
			cnt++;
		}
	}
	
	if(Current.energy < desti) 
	{

		cout << -1 << endl;
	}
	else
	{
		cout << cnt << endl;
	}
	
	return 0;
}
