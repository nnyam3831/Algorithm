#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers)
{
    vector<int> answer;
    int size = answers.size();
    int a = 0, b = 0, c = 0;
    int first[] = {1, 2, 3, 4, 5};
    int second[] = {2, 1, 2, 3, 2, 4, 2, 5};
    int third[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    for (int i = 0; i < size; i++)
    {
        int x, y, z;
        x = i % 5;
        y = i % 8;
        z = i % 10;
        if (answers[i] == first[x])
            a++;
        if (answers[i] == second[y])
            b++;
        if (answers[i] == third[z])
            c++;
    }
    if (a > b)
    {
        if (a > c)
        {
            answer.push_back(1);
        }
        else if (a == c)
        {
            answer.push_back(1);
            answer.push_back(3);
        }
        else
        {
            answer.push_back(3);
        }
    }
    else if (a == b)
    {
        if (a > c)
        {
            answer.push_back(1);
            answer.push_back(2);
        }
        else if (a == c)
        {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else
        {
            answer.push_back(3);
        }
    }
    else
    {
        if (b > c)
        {
            answer.push_back(2);
        }
        else if (b == c)
        {
            answer.push_back(2);
            answer.push_back(3);
        }
        else
        {
            answer.push_back(3);
        }
    }
    return answer;
}