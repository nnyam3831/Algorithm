#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 501
using namespace std;

int Dp[MAX][MAX];
int solution(vector<vector<int>> triangle)
{
    int answer = 0;

    for (int h = 0; h < triangle.size(); h++)
    {
        for (int j = 0; j < h + 1; j++)
        {
            if (h == 0)
            {
                Dp[h][j] = triangle[h][j];
            }
            else
            {
                if (j == 0)
                {
                    Dp[h][j] = Dp[h - 1][j] + triangle[h][j];
                }
                else if (j == h)
                {
                    Dp[h][j] = Dp[h - 1][j - 1] + triangle[h][j];
                }
                else
                {
                    Dp[h][j] = max(Dp[h - 1][j - 1] + triangle[h][j], Dp[h - 1][j] + triangle[h][j]);
                }
            }
        }
    }
    int height = triangle.size();
    for (int i = 0; i < height; i++)
    {
        answer = max(Dp[height - 1][i], answer);
    }
    return answer;
}
