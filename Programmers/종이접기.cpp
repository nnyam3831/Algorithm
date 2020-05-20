#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n)
{
    vector<int> temp;
    vector<int> answer;
    temp.push_back(0);
    answer.push_back(0);
    for (int i = 1; i < n; i++)
    {
        temp.assign(answer.begin(), answer.end());
        temp.push_back(0);
        for (int j = answer.size() - 1; j >= 0; j--)
        {
            temp.push_back((answer[j] + 1) % 2);
        }
        answer.assign(temp.begin(), temp.end());
    }

    return answer;
}

int main(void)
{

    solution(4);
    return 0;
}