#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#define MAX 300 + 1
using namespace std;

typedef struct info
{
    int from, to, weight;
    info(int from, int to, int weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
} info;
vector<info> edge;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, -1, 1};
int group[MAX][MAX];
int cnt;
int R, H;
int parent[100001];
int find(int num)
{
    if (parent[num] == num)
        return num;
    else
        return parent[num] = find(parent[num]);
}
void Union(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if (pa < pb)
    {
        parent[pb] = pa;
    }
    else
    {
        parent[pa] = pb;
    }
}
bool cmp(const info &a, const info &b)
{
    if (a.weight < b.weight)
        return true;
    else
        return false;
}
void BFS(int y, int x, vector<vector<int>> land)
{
    group[y][x] = cnt;
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));

    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];
            if (ny >= R || ny < 0 || nx >= R || nx < 0)
                continue;
            if (group[ny][nx] != 0)
                continue;
            if (abs(land[curY][curX] - land[ny][nx]) <= H)
            {
                group[ny][nx] = cnt;
                q.push(make_pair(ny, nx));
            }
        }
    }
}
int solution(vector<vector<int>> land, int height)
{
    int answer = 0;
    R = land.size();
    H = height;
    for (int y = 0; y < R; y++)
    {
        for (int x = 0; x < R; x++)
        {
            if (group[y][x] == 0)
            {
                cnt++;
                BFS(y, x, land);
            }
        }
    }

    for (int i = 1; i <= cnt; i++)
    {
        parent[i] = i;
    }

    for (int y = 0; y < R; y++)
    {
        for (int x = 0; x < R; x++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if (ny >= 0 && ny < R && nx >= 0 && nx < R)
                {
                    if (group[y][x] != group[ny][nx])
                    {
                        edge.push_back(info(group[y][x], group[ny][nx], abs(land[y][x] - land[ny][nx])));
                    }
                }
            }
        }
    }
    sort(edge.begin(), edge.end(), cmp);
    for (int i = 0; i < edge.size(); i++)
    {
        if (find(edge[i].from) != find(edge[i].to))
        {
            Union(edge[i].from, edge[i].to);
            answer += edge[i].weight;
        }
    }
    return answer;
}

int main(void)
{
    vector<vector<int>> v1 = {{1, 4, 8, 10}, {5, 5, 5, 5}, {10, 10, 10, 10}, {10, 10, 10, 20}};
    vector<vector<int>> v2 = {{10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 1}};
    solution(v1, 3);
    return 0;
}