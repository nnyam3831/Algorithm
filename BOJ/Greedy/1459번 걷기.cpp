#include <iostream>

using namespace std;

int main(void)
{
	long long int X, Y, W, S;
	long long int result;
	cin >> X >> Y >> W >> S;
	
	long long int mod = (X+Y) % 2;
	
	result = min((X+Y)*W, min((max(X,Y)-mod)*S + mod * W, min(X,Y)*S + (max(X,Y)-min(X,Y))*W));
	cout << result << endl;
	return 0;
}
