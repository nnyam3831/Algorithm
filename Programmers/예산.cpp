#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M)
{
    long long answer = 0;
    int length = budgets.size();
    int start = M / length;
    int end = 0;
    long long sum = 0;
    for (int i = 0; i < length; i++)
    {
        end = max(budgets[i], end);
        sum += budgets[i];
    }

    if (sum <= M)
        return end;

    while (start <= end)
    {
        long long mid = (start + end) / 2;
        long long total = 0;
        for (int i = 0; i < length; i++)
        {
            if (budgets[i] <= mid)
            {
                total += budgets[i];
            }
            else
            {
                total += mid;
            }
        }
        if (total <= M)
        {
            answer = max(answer, mid);
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return answer;
}

int main(void)
{
    int M = 485;
    vector<int> bud;
    bud.push_back(120);
    bud.push_back(110);
    bud.push_back(140);
    bud.push_back(150);

    cout << solution(bud, M) << "\n";
    return 0;
}