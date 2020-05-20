#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

int d[301][301];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt = 0;
int parent[100001];

void bfs(int x, int y, int cnt, vector<vector<int>> land, int height)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    d[x][y] = cnt;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < land.size() && ny >= 0 && ny < land[0].size())
            {
                if (d[nx][ny] == 0 && abs(land[x][y] - land[nx][ny]) <= height)
                {
                    q.push(make_pair(nx, ny));
                    d[nx][ny] = cnt;
                }
            }
        }
    }
}

struct edge
{
    int v1, v2, weight;

    edge(int v1, int v2, int weight)
    {
        this->v1 = v1;
        this->v2 = v2;
        this->weight = weight;
    }
};

int find(int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = find(parent[node]);
}

void _union(int a, int b)
{
    int pa = find(a);
    int pb = find(b);

    if (pa == pb)
        return;
    parent[pb] = pa;
}

int compareTo(const edge &a, const edge &b)
{
    if (a.weight < b.weight)
        return 1;
    else
        return 0;
}

int solution(vector<vector<int>> land, int height)
{

    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[0].size(); j++)
        {
            if (d[i][j] == 0)
                bfs(i, j, ++cnt, land, height);
        }
    }

    for (int i = 1; i <= cnt; i++)
        parent[i] = i;

    vector<edge> v;
    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[0].size(); j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= 0 && nx < land.size() && ny >= 0 && ny < land[0].size())
                {
                    if (d[i][j] != d[nx][ny])
                        v.push_back(edge(d[i][j], d[nx][ny], abs(land[i][j] - land[nx][ny])));
                }
            }
        }
    }
    sort(v.begin(), v.end(), compareTo);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].v1 << " " << v[i].v2 << " " << v[i].weight << "\n";
    }
    int answer = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (find(v[i].v1) != find(v[i].v2))
        {
            _union(v[i].v1, v[i].v2);
            answer += v[i].weight;
        }
    }
    return answer;
}

int main(void)
{
    vector<vector<int>> v1 = {{1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}};
    vector<vector<int>> v2 = {{10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 1}};
    solution(v2, 3);
    return 0;
}