#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
	char board[500];

	int XCount = 0;
	string temp = "";
	bool flag = true;
	
	cin >> board;
	for(int i = 0; i <= strlen(board); i++)
	{
		if(board[i] == 'X')
		{
			XCount++;
			if(XCount == 4) {
				temp += "AAAA";
				XCount = 0;
			}
		}
		else if(board[i] == '.' || board[i] == NULL)
		{
			if(board[i] == NULL)
			{
				if(XCount == 2)
				{
					temp += "BB";
				}
				else if(XCount == 0)
				{
					break;
				}
				else
					flag = false;
			}
			else
			{
				if(XCount == 2)
				{
					temp += "BB.";
					XCount = 0;
				}
				else if(XCount == 0)
				{
					temp += ".";
				}
				else
				{
					flag = false;
				}
			}
		}
	}
	
	if(!flag)	cout << -1 << endl;
	else
		cout << temp << endl;
	return 0;
}
