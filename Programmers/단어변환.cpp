#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[51];
int Length;
bool match(string a, string b)
{
    int cnt = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
            cnt++;
    }
    if (cnt == 1)
        return true;
    return false;
}

int DFS(string current, string target, vector<string> words)
{
    if (target == current)
        return 0;
    bool flag = false;
    int ret = 0;
    for (int i = 0; i < Length; i++)
    {
        if (!visited[i] && match(current, words[i]))
        {
            flag = true;
            visited[i] = true;
            ret = 1 + DFS(words[i], target, words);
            visited[i] = false;
        }
        else
        {
            cout << "??";
        }
    }
    if (!flag)
    {
        // 다음 단계 갈 수 없거나 다 방문함
        return -10000000;
    }
    if (ret < 0)
        return 0;
    return ret;
}
int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    Length = words.size();
    answer = DFS(begin, target, words);
    cout << answer << "\n";
    return answer;
}
int main(void)
{

    return 0;
}