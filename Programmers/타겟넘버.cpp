#include <string>
#include <vector>

using namespace std;
int sol = 0;
int N;
int t;
vector<int> buff;
void dfs(int op, int index, int result)
{
    if (index == N - 1)
    {
        if (op == 0)
        {
            result += buff[index];
        }
        else
        {
            result -= buff[index];
        }
        if (result == t)
            sol++;

        return;
    }
    if (op == 0)
    {
        dfs(0, index + 1, result + buff[index]);
        dfs(1, index + 1, result + buff[index]);
    }
    else
    {
        dfs(0, index + 1, result - buff[index]);
        dfs(1, index + 1, result - buff[index]);
    }
}
int solution(vector<int> numbers, int target)
{
    int answer = 0;
    N = numbers.size();
    for (int i = 0; i < N; i++)
    {
        buff.push_back(numbers[i]);
    }
    t = target;
    dfs(0, 0, 0);
    dfs(1, 0, 0);
    answer = sol;
    return answer;
}