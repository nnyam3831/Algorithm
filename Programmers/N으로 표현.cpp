#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

// Dp[N][K] 숫자 N을 K번 써서 만들 수 있는 숫자들
vector<int> Dp[9];
int specialNum(int N, int len)
{
	int ret = 0;
	for (int i = 0; i < len; i++)
	{
		ret += N * pow(10, i);
	}
	return ret;
}
int solution(int N, int number)
{
	int answer = 0;
	Dp[1].push_back(N);
	if (N == number)
		return 1;
	for (int i = 2; i <= 8; i++)
	{
		// 일단 얘는 넣어야됨
		Dp[i].push_back(specialNum(N, i));
		for (int j = 1; j < i; j++)
		{
			int rest = i - j;
			for (auto a : Dp[rest])
			{
				for (auto b : Dp[j])
				{
					Dp[i].push_back(a + b);
					Dp[i].push_back(a * b);
					Dp[i].push_back(a - b);
					Dp[i].push_back(b - a);
					if (a != 0)
						Dp[i].push_back(b / a);
					if (b != 0)
						Dp[i].push_back(a / b);
				}
			}
		}
		for (auto ret : Dp[i])
		{
			if (ret == number)
				return i;
		}
	}

	answer = -1;
	return answer;
}

int main(void)
{

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int N, number;
		cin >> N >> number;
		cout << solution(N, number) << "\n";
		for (int i = 1; i <= 8; i++)
		{
			for (auto a : Dp[i])
			{
				cout << "index: " << i << " " << a << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}