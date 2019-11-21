// DFS�� �̿��� ��Ʈ��ŷ

#include <iostream>

using namespace std;

int N;
int col[15];
int result = 0; 

bool promising(int i)		// �����Լ�  
{
	for(int j = 0; j < i; j++)
	{
		// ���ο� ���� ������ ���� ��ġ���� Ȯ��
		if(col[j] == col[i] || abs(col[i]-col[j]) == (i-j))
			return false; 
	}
	return true;
}

void N_Queen(int i)
{
	if(i == N)
		result += 1;
	else
	{
		for(int j = 0; j < N; j++)
		{
			col[i] = j;
			if(promising(i))
				N_Queen(i+1);
		}
	}
}

int main(void)
{
	cin >> N;
	
	N_Queen(0);
	
	cout << result << endl;
	
	return 0;
}
