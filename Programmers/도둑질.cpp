#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 1000000 + 1
using namespace std;

int Dp[MAX][2][2];

int solution(vector<int> money)
{
    int answer = 0;
    Dp[0][0][0] = 0;
    Dp[0][1][1] = money[0];
    Dp[1][0][0] = 0;
    Dp[1][0][1] = money[0];
    Dp[1][1][0] = money[1];

    for (int i = 2; i < money.size(); i++)
    {
        Dp[i][1][0] = max(Dp[i - 2][1][0] + money[i], Dp[i - 2][0][0] + money[i]);
        Dp[i][1][1] = max(Dp[i - 2][1][1] + money[i], Dp[i - 2][0][1] + money[i]);

        Dp[i][0][0] = max(Dp[i - 1][1][0], Dp[i - 1][0][0]);
        Dp[i][0][1] = max(Dp[i - 1][1][1], Dp[i - 1][0][1]);
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i == 1 && j == 1)
                continue;
            answer = max(answer, Dp[money.size() - 1][i][j]);
        }
    }
    return answer;
}

int main(void)
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    cout << solution(v);
    return 0;
}