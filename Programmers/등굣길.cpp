#include <string>
#include <vector>
#include <iostream>
#define MAX 101
using namespace std;

const int mod = 1000000007;

int Dp[MAX][MAX];
int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;
    Dp[1][1] = 1;
    for (int len = 0; len < puddles.size(); len++)
    {
        Dp[puddles[len][1]][puddles[len][0]] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (Dp[i][j] == -1)
                continue;
            int ny = i + 1;
            int nx = j + 1;

            if (ny <= n && Dp[ny][j] != -1)
                Dp[ny][j] += Dp[i][j];
            if (nx <= m && Dp[i][nx] != -1)
                Dp[i][nx] += Dp[i][j];
        }
        cout << "\n";
    }

    return Dp[n][m];
}

int main(void)
{

    vector<vector<int>> v;
    vector<int> temp;
    temp.push_back(2);
    temp.push_back(2);
    v.push_back(temp);
    int M, N;
    cin >> M >> N;

    solution(M, N, v);
    return 0;
}