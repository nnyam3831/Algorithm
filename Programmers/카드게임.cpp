#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <memory.h>

using namespace std;

int Dp[2002][2002];

// 핵심: 모든 경우를 시뮬레이션 하면서 해당 상황에서 가질 수 있는 최대의 point를 리턴한다.
int solution(vector<int> left, vector<int> right)
{
    int answer = 0;
    int L = left.size();
    int R = right.size();

    memset(Dp, -1, sizeof(Dp));

    Dp[0][0] = 0;

    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < R; j++)
        {

            if (Dp[i][j] == -1) // 불가능 케이스
                continue;
            if (left[i] > right[j])
            {
                Dp[i][j + 1] = Dp[i][j] + right[j];
            }

            Dp[i + 1][j + 1] = max(Dp[i + 1][j + 1], Dp[i][j]);
            Dp[i + 1][j] = max(Dp[i + 1][j], Dp[i][j]);
        }
    }
    for (int i = 0; i <= L; i++)
    {
        answer = max(answer, Dp[i][R]);
    }
    for (int i = 0; i <= R; i++)
    {
        answer = max(answer, Dp[L][i]);
    }
    cout << Dp[L][R];
    return answer;
}

int main(void)
{

    vector<int> l, r;
    l.push_back(3);
    l.push_back(2);
    l.push_back(5);
    r.push_back(2);
    r.push_back(4);
    r.push_back(1);

    solution(l, r);
    return 0;
}
