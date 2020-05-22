#include <iostream>
#include <string>
#include <vector>

using namespace std;

int visited[9];
int distSize;
int result = -1;
vector<int> dest;
vector<int> w;
vector<int> target;
void simulation()
{
    int index = 0;
    for (int i = 0; i < w.size(); i++)
    {
        vector<int> temp;
        for (int j = 0; j < w.size(); j++)
        {
            if (j + index < w.size())
            {
                temp.push_back(w[j + index]);
            }
            else
            {
                temp.push_back(w[(j + index) % w.size()] + 12);
            }
        }
        index++;
        int curIndex = 0;
        int lastIndex = 0;
        int cnt = 0;

        while (1)
        {
            cout << lastIndex << " " << curIndex << "\n";
            if (lastIndex >= temp.size())
            {
                result = target.size();
                break;
            }
            if (cnt == target.size())
                break;
            int seq = target[cnt];
            if (temp[lastIndex] - temp[curIndex] <= dest[seq])
            {
                lastIndex++;
            }
            else
            {
                curIndex = lastIndex;
                cnt++;
            }
        }
    }
};
void perm(int N)
{
    if (N == target.size())
    {
        simulation();
    }
    for (int i = 0; i < distSize; i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            target.push_back(i);
            perm(N);
            visited[i] = 0;
            target.pop_back();
        }
    }
};
int solution(int n, vector<int> weak, vector<int> dist)
{
    int answer = 0;
    dest.assign(dist.begin(), dist.end());
    w.assign(weak.begin(), weak.end());
    distSize = dist.size();
    for (int i = 0; i < dest.size(); i++)
    {
        perm(i + 1);
        if (result != -1)
            break;
    }
    return result;
};

int main(void)
{

    vector<int> v1 = {1, 3, 4, 9, 10};
    vector<int> v2 = {3, 5, 7};
    int n = 12;
    solution(n, v1, v2);
    cout << result << "\n";
    return 0;
}