#include <iostream>

using namespace std;

int D[100001][2];
int main(void)
{
	int N;
	cin >> N;
	
	D[1][0] = 2;
	D[1][1] = 1;
	
	// D[n][0] => n번째 끝에 사자 넣음, D[n][1] => n번째 끝에 사자 안넣음
	for(int i = 2; i <= N; i++)
	{
		D[i][0] = D[i-1][0] + 2 * D[i-1][1];
		D[i][1] = D[i-1][0] + D[i-1][1];
		D[i][0] %= 9901;
		D[i][1] %= 9901;
	}
	
	cout << (D[N][0] + D[N][1]) % 9901 << endl;
	return 0;
}
