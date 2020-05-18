#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
#define MAX 81

using namespace std;

long long Dp[81];
void setUp()
{
    Dp[1] = 1;
    Dp[2] = 1;
    for (int i = 3; i <= 80; i++)
    {
        Dp[i] = Dp[i - 1] + Dp[i - 2];
    }
}
long long solution(int N)
{
    if (N == 1)
        return 4;
    if (N == 2)
        return 6;

    setUp();
    long long answer = 0;
    answer = 2 * Dp[N] + 2 * (Dp[N] + Dp[N - 1]);
    return answer;
}

int main(void)
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int N;
        cin >> N;
        int ans = solution(N);
        cout << ans << "\n";
    }
    return 0;
}