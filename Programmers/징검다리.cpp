#include <bits/stdc++.h>

using namespace std;

bool is_possible(int distance, vector<int> rocks, int n, int min_dist)
{
    int gap, last = -1, removed = 0;
    for (int i = 0; i <= rocks.size(); i++)
    {
        gap = (last == -1 ? rocks[i] : (i == rocks.size() ? distance - rocks.back() : rocks[i] - rocks[last]));
        if (gap < min_dist)
        {
            removed++;
        }
        else
        {
            last = i;
        }
    }
    return removed <= n;
}

int solution(int distance, vector<int> rocks, int n)
{
    int left = 0, right = distance, mid;
    sort(rocks.begin(), rocks.end());

    while (left + 1 < right)
    {
        mid = (left + right) / 2;
        if (is_possible(distance, rocks, n, mid))
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    return is_possible(distance, rocks, n, left) ? left : right;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solution(25, {2, 14, 11, 21, 17}, 2);

    return 0;
}