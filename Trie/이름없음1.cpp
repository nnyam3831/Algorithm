#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 100 + 1
using namespace std;

int state[MAX][MAX];
int cnt = 0;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
long board[MAX][MAX];
int BFS(int y, int x, int value, int m, int n)
{
    cnt++;
    int max_size = 0;
    // value 인 것들 BFS로 묶자
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    state[y][x] = cnt;
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
                	state[nextY][nextX] = cnt;
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
    cnt = 0;
    dy[0] = 1, dy[1] = -1, dy[2] = 0, dy[3] = 0;
    dx[0] = 0, dx[1] = 0, dx[2] = -1, dx[3] = 1;
    for(int y = 0; y < m; y++){
    	for(int x = 0; x < n; x++){
    		board[y][x] = picture[y][x];
    		state[y][x] = 0;
		}
	}
    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            int value = board[y][x];
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
    cout << answer[0] << " " << answer[1] << "\n";
    return answer;
}
int main(void)
{
    solution(6, 4, {{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}});
    return 0;
}
