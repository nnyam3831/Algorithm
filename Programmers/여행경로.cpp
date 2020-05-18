#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool dfs(string cur, vector<vector<string>> &tickets, vector<string> &answer, vector<string> &temp, vector<bool> &visited, int cnt)
{
    temp.push_back(cur);
    if (cnt == tickets.size())
    {
        answer = temp;
        return true;
    }
    for (int i = 0; i < tickets.size(); i++)
    {
        if (!visited[i] && tickets[i][0] == cur)
        {
            visited[i] = true;
            bool success = dfs(tickets[i][1], tickets, answer, temp, visited, cnt + 1);
            if (success)
                return true;
            visited[i] = false;
        }
    }
    temp.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer, temp;
    vector<bool> visited(tickets.size(), false);
    sort(tickets.begin(), tickets.end());
    dfs("ICN", tickets, answer, temp, visited, 0);
    return answer;
}
