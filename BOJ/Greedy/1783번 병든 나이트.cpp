#include <iostream>

using namespace std;

int main(void)
{
	int N, M;
	int result;
	cin >> N >> M;
	if(N == 1)
	{
		result = 1;
	}
	else if(N == 2)
	{
		if(M <= 2)
		{
			result = 1;
		}
		else if(M >= 3 && M <=4)
		{
			result = 2;
		}
		else if(M >= 5 && M <=6)
		{
			result = 3;
		}
		else
		{
			result = 4;
		}
	}
	else if(N >= 3)
	{
		if(M == 1)
			result = 1;
		else if(M == 2)
		{
			result = 2;
		}
		else if(M == 3)
		{
			result = 3;
		}					// �ִ� 4ĭ�̹Ƿ� min (4, )~ ����ϸ� �ڵ�ȿ�� ����  
		else if(M >= 4 && M <= 6)
		{
			result = 4;
		}
		else		// M >= 7�̻�  
		{
			result = M-2;
		}
	}
	
	cout << result << endl;
	return 0;
}
