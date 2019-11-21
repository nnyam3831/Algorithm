#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long total , s;
pair <int, int> p[100001];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> p[i].first >> p[i].second;
		total += p[i].second;
	}
	sort(p+1, p+1+n);
	for(int i = 1; i <= n; i++)
	{
		s += p[i].second;
		if(s >= (total + 1) / 2)
		{
			cout << p[i].first << endl;
			break;
		}
	}
	return 0;
}
