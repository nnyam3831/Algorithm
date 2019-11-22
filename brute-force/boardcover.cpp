#include <iostream>
#include <vector>
using namespace std;


int H, W;
const int Type[4][3][2] = {
	{
		{0, 0}, {1, 0}, {0, 1}
	},
	{
		{0, 0}, {1, 1}, {0, 1}
	},
	{
		{0, 0}, {1, 0}, {1, 1}
	},
	{
		{0, 0}, {1, 0}, {1, -1}
	}
};

// delta = 1 µ¤À½, delta = -1 µ¤¾ú´ø°Å ¾ø¾Ú
 
bool set(vector<vector<int> > & board, int y, int x, int type, int delta){
	bool ok = true;
	for(int i = 0; i < 3; i++){
		const int nextY = y + Type[type][i][0];
		const int nextX = x + Type[type][i][1];
		if(nextY < 0 || nextY >= board.size() || nextX < 0 || nextX >= board[0].size()){
			ok = false;
		}
		// °ãÄ¡°Å³ª °ËÀº Ä­ µ¤À»¶§ 
		else if((board[nextY][nextX] += delta) > 1)
			ok = false;
	}
	return ok;
}
// boardÀÇ ¸ðµç ºóÄ­À» µ¤´Â °æ¿ìÀÇ ¼ö return
 
int cover(vector<vector<int>>& board){
	int y = -1, x = -1;
	// ¾ÆÁ÷ Ã¤¿ìÁö ¸øÇÑ Ä­ Áß¿¡ °¡Àå À­ÁÙ ¿ÞÂÊ¿¡ ÀÖ´Â Ä­ Ã£±â
	for(int i = 0; i < board.size(); i++){
		for(int j = 0; j < board[0].size(); j++){
			if(board[i][j] == 0){	// ÈòÄ­ 
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1) break;
	}
	
	// ±âÀú : ¸ðµç Ä­ Ã¤¿üÀ¸¸é return  1
	if(y == -1) return 1;
	int ret = 0;
	for(int type = 0; type < 4; type++){
		// ¸¸¾à µ¤À» ¼ö ÀÖÀ¸¸é Àç±ÍÈ£Ãâ
		if(set(board, y, x,type, 1)) 
			ret += cover(board);
		set(board,y, x, type, -1);
	}
	return ret; 
}
int main(void){
	int Test;
	cin >> Test;
	for(int T = 0; T < Test; T++){
		vector<vector<int>> V;
		cin >> H >> W;
		for(int y = 0; y < H; y++)
		{
			vector<int> temp;
			for(int x = 0; x < W; x++){
				char c;
				cin >> c;
				if(c == '#') temp.push_back(1);
			
				else
					temp.push_back(0);
			}
			V.push_back(temp);
		}
		for(int y = 0; y < H; y++)
		{
			for(int x = 0; x < W; x++){
				cout << V[y][x];
			}
			cout << "\n";
		}
		int ret = cover(V);
		cout << ret << "\n";
	}
	
	return 0;
}
