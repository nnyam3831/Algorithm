#include <string>
#include <vector>
#include <iostream>

using namespace std;

int result =  10000000;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int Dp[26][26];

void dfs(int y, int x, int size, int from, vector<vector<int>> &board){
    if(y == size-1 && x == size-1){
        return;
    }
    
    for(int dir = 0; dir < 4; dir++){
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];
        int nextCost = Dp[y][x];
        if(nextY >= size || nextY < 0 || nextX >= size || nextX < 0) continue;
         if(from == dir || from == -1){
             nextCost += 100;
         }else{
             nextCost += 600;
         }
        if(nextCost <= Dp[nextY][nextX] && board[nextY][nextX] == 0){
            // go
            Dp[nextY][nextX] = nextCost;
            dfs(nextY, nextX, size, dir, board);
        }
    }
}
int solution(vector<vector<int>> board) {
    int answer = 0;
    int size = board.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            Dp[i][j] = result;
        }
    }
    Dp[0][0] = 0;
    dfs(0, 0, size, -1, board);
   
    return Dp[size-1][size-1];
}

