#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 100 + 1
using namespace std;

int state[MAX][MAX];
int cnt = 0;
const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, -1, 1};
vector<vector<int>> board;
int BFS(int y, int x, int value, int m, int n)
{
    cnt++;
    int max_size = 0;
    // value 인 것들 BFS로 묶자
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    while (!q.empty())
    {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();
        max_size++;
        for (int dir = 0; dir < 4; dir++)
        {
            int nextY = curY + dy[dir];
            int nextX = curX + dx[dir];
            if (nextY >= 0 && nextY < m && nextX >= 0 && nextX < n)
            {
                if (state[nextY][nextX] == 0 && board[nextY][nextX] == value)
                {
                    q.push(make_pair(nextY, nextX));
                }
            }
        }
    }
    return max_size;
}
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    board.assign(picture.begin(), picture.end());
    for (int y = 0; y < picture.size(); y++)
    {
        for (int x = 0; x < picture[y].size(); x++)
        {
            int value = picture[y][x];
            if (state[y][x] == 0 && value != 0)
            {
                max_size_of_one_area = max(max_size_of_one_area, BFS(y, x, value, m, n));
            }
        }
    }
    number_of_area = cnt;

    vector<int> answer(2);

    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
int main(void)
{
    solution(6, 4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}});
    return 0;
}