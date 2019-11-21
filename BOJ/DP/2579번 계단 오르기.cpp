#include <iostream>
using namespace std;

int D[301];
int n, stair[301];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> stair[i];
	}
	D[1] = stair[1];
	D[2] = max(stair[1]+stair[2], stair[2]);
	D[3] = max(stair[1]+stair[3], stair[2]+stair[3]);
	
	for(int i = 4; i <= n; i++)
	{
		D[i] = max(D[i-2] + stair[i], D[i-3] + stair[i-1]+stair[i]);
	}
	
	cout << D[n] << endl;
	return 0;
}
