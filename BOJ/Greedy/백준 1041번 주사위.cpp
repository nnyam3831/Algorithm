/*
N == 1�� ���� �ƴҶ��� ������ sort �ϴϱ� �ذ�� => �޸� �����ε� ? 
*/

#define MIN(A, B) (A < B ? A : B)
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	long N;
	int list[6];
	long result = 0;
	
	cin >> N;
	for(int i =0; i< 6; i++)
	{
		cin >> list[i];
	}
	// �������� ���� 

	

	if(N==1)
	{
		sort(list, list+6);
		for(int i = 0; i < 5; i++)
		{
			result += list[i];
		}
	}
	else
	{
		list[0] = MIN(list[0], 	list[5]);
        list[1] = MIN(list[1], 	list[4]);
        list[2] = MIN(list[2],	list[3]);
        sort(list, list+3);
	result += list[0] * ((N-2)*(N-2)*5 + 4*(N-2));
	result += (list[0] + list[1]) * (4*(N-1) + 4*(N-2));
	result += (list[0] + list[1] + list[2]) * 4;
	}
	cout << result << endl;
	return 0;
}
