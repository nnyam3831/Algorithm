#include <iostream>

using namespace std;

long long int D[91];

long long int pinary(int N)
{
	if(N==1) return D[1] = 1;
	if(N==2) return D[2] = 1;
	if(D[N]) return D[N];
	return D[N] = pinary(N-1) + pinary(N-2);
}
int main(void)
{
	int N;
	cin >> N;
	cout << pinary(N) << endl;
	return 0;
}
