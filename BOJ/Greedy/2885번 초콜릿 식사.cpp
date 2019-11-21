#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
	int K, Size, Cnt = 0;
	
	cin >> K;
	int i = 0;
	int lastbit;
	lastbit = K & -K;
	
	while(1)
	{
		if(pow(2,i) >= K)
		{
			Size = pow(2,i);
			break;
		}
		
		i++;
	}
	
	int temp = Size;
	while(1)
	{
		if(temp == lastbit)
		{
			break;
		}
		Cnt++;
		temp = temp/2;
		
	}
	
	cout << Size << " " << Cnt << endl;
	return 0;
}
