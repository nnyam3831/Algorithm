#include <iostream>
#include <algorithm>
// 끝 위치 하나 전에서 웅덩이가 끝남  
using namespace std;

struct Nike{
	int start;
	int end;
};

bool cmp(const Nike &A, const Nike &B)
{
	if(A.start == B.start) return A.end < B.end;
	
	return A.start < B.start;
}
int main(void)
{
	Nike Arr[10001];
	int N, L;
	int cnt = 0;
	int index = 0;
	cin >> N >> L;
	for(int i = 1; i <= N; i++)
	{
		cin >> Arr[i].start >> Arr[i].end;
	}
	sort(Arr+1, Arr+(N+1), cmp);
	
	for(int i = 1; i <= N; i++)
	{
		if(index <= Arr[i].start)
		{
			cnt += (Arr[i].end-Arr[i].start-1)/L + 1;
			index = Arr[i].start + ((Arr[i].end-Arr[i].start-1)/L + 1) * L;
		}
		else
		{
			if(index < Arr[i].end)
			{
				cnt += (Arr[i].end - index-1)/L + 1;
				index += ((Arr[i].end-index-1)/L + 1) * L;
			}
	
		}
		
	}
	
	cout << cnt << endl;
	return 0;
}
