#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

int board[101][101];
void create(int mode, int x, int y)
{
    if (mode == 0)
    {
        // 기둥
        if (y == 0)
        {
            board[x][y] = 0;
        }
        else if (board[x][y - 1] == 0)
        {
            board[x][y] == -1 ? board[x][y] = 0 : board[x][y] = 2;
        }
        else if (board[x][y] == 1)
        {
            board[x][y] = 2;
        }
        else if (x - 1 >= 0 && board[x - 1][y] == 1)
        {
            board[x][y] == -1 ? board[x][y] = 0 : board[x][y] = 2;
        }

        // 그 외에는 무시
    }
    else
    {
        // 보
        if (x - 1 >= 0 && board[x - 1][y] >= 1 && board[x + 1][y] >= 1)
        {
            board[x][y] == -1 ? board[x][y] = 1 : board[x][y] = 2;
        }
        else if (board[x][y - 1] == 0 || board[x][y - 1] == 2)
        {
            board[x][y] == -1 ? board[x][y] = 1 : board[x][y] = 2;
        }
        else if (board[x + 1][y - 1] == 0 || board[x + 1][y - 1] == 2)
        {
            board[x][y] == -1 ? board[x][y] = 1 : board[x][y] = 2;
        }
    }
};
void remove(int mode, int x, int y)
{
    if (mode == 0)
    {
        // 기둥
        // 위에가 -1, 0, 1, 2 일 때
        if (board[x][y + 1] == -1)
        {
            board[x][y] == 2 ? board[x][y] = 1 : board[x][y] = -1;
        }
        else if (board[x][y + 1] == 0)
        {
            // 왼쪽만
        }
        else if (board[x][y + 1] == 1)
        {
        }
        else if (board[x][y + 1] == 2)
        {
        }
    }
    else
    {
        // 보
    }
};
vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    memset(board, -1, sizeof(board));
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); i++)
    {
        int x, y, a, b;
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];

        if (b == 1)
        {
            // 설치
            create(a, x, y);
        }
        else
        {
            // 삭제
            remove(a, x, y);

            cout << x << " " << y << " " << a << " " << b << " " << board[x][y] << "\n";
        }
    }
    return answer;
}

int main(void)
{
    int n = 5;
    vector<vector<int>> test = {{1, 0, 0, 1},
                                {1, 1, 1, 1},
                                {2, 1, 0, 1},
                                {2, 2, 1, 1},
                                {5, 0, 0, 1},
                                {5, 1, 0, 1},
                                {4, 2, 1, 1},
                                {3, 2, 1, 1}};

    solution(n, test);
    return 0;
}