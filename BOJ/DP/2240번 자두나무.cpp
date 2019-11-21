#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1000;
const int MOVE = 30 + 1;

int T, W;
int plum[MAX];
int cache[3][MAX][MOVE];

int maxPlum(int tree, int second, int move)
{
	if(second == T)		// ±âÀú 
		return 0;
	
	if(cache[tree][second][move] != -1) return cache[tree][second][move];
	
	if(plum[second] == tree)
	{
		if(move < W)
		{
			return cache[tree][second][move] = max(1+maxPlum(tree, second+1, move), maxPlum(3-tree, second+1, move+1));
		}
		else
			return cache[tree][second][move] = 1 + maxPlum(tree, second+1, move);
	}
	else
	{
		if(move < W)
		{
			return cache[tree][second][move] = max(maxPlum(tree, second+1, move), 1 + maxPlum(3-tree, second+1, move+1));
		}
		else
			return cache[tree][second][move] = maxPlum(tree, second+1, move);
	}
}

int main(void)
{
	cin >> T >> W;	
	for(int i = 0; i < T; i++)
	{
		cin >> plum[i];
	}
	
	memset(cache, -1, sizeof(cache));
	cout << maxPlum(1, 0, 0) << endl;
	return 0;
}
