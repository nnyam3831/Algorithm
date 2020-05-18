#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 100 + 1

using namespace std;

int dp[101][100010];
int solution(int K, vector<vector<int>> travel)
{
    int answer = 0;
    dp[0][travel[0][0]] = travel[0][1];
    dp[0][travel[0][2]] = travel[0][3];
    for (int i = 1; i < travel.size(); i++)
    {
        for (int k = 0; k <= K; k++)
        {
            if (dp[i - 1][k] == 0)
                continue;
            if (k + travel[i][0] <= K)
            {
                dp[i][k + travel[i][0]] = max(dp[i][k + travel[i][0]], dp[i - 1][k] + travel[i][1]);
                answer = max(answer, dp[i][k + travel[i][0]]);
            }
            if (k + travel[i][2] <= K)
            {
                dp[i][k + travel[i][2]] = max(dp[i][k + travel[i][2]], dp[i - 1][k] + travel[i][3]);
                answer = max(answer, dp[i][k + travel[i][2]]);
            }
        }
    }
    return answer;
}