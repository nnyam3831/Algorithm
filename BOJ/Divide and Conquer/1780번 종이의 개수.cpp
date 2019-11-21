#include <iostream>
#include <math.h>
#define MAX (int)pow(3,7)

using namespace std;

int n;
int a[MAX][MAX];
int answer[3];

string solve(int n, int i, int j)
{
	if(n==1){
		return to_string(a[i][j]+1);
	}
	string temp[9];
	temp[0] = solve(n/3, i, j);
	temp[1] = solve(n/3, i, j + n/3);
	temp[2] = solve(n/3, i, j + (n*2)/3);
	temp[3] = solve(n/3, i+n/3, j);
	temp[4] = solve(n/3, i+n/3, j+n/3);
	temp[5] = solve(n/3, i+n/3, j+(n*2)/3);
	temp[6] = solve(n/3, i+(n*2)/3, j);
	temp[7] = solve(n/3, i+(n*2)/3, j+n/3);
	temp[8] = solve(n/3, i+(n*2)/3, j+(n*2)/3);
	bool same = true;
	string value = temp[0];
	for(int i = 0; i < 9; i++)
	{
		if(temp[i] != value) same = false;
	}
	if(same && temp[0].length() == 1)
	{
		return temp[0];
	}
	string res = "(";
	for(int i = 0; i < 9; i++)
	{
		res += temp[i];
	}
	res += ")";
	return res;
}
int main(void)
{
	cin >> n;
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cin >> a[i][j];
		}
	}
	string res = solve(n, 0, 0);
	for(int i = 0; i < res.length(); i++)
	{
		if(res[i] == '0') answer[0]++;
		if(res[i] == '1') answer[1]++;
		if(res[i] == '2') answer[2]++;
	}
	cout << answer[0] << '\n' << answer[1] << '\n' << answer[2];
	return 0;
} 
