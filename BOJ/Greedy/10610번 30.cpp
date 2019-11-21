#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char input[100000];
int main(void)
{
	int result = -1;
	int sum = 0;
	int impossible = 0;
	cin >> input;
	int* arr = new int[strlen(input)];
	for(int i = 0; input[i] != NULL; i++)
	{
		arr[i] = input[i] -'0';
		sum += arr[i];
		if(arr[i] == 0) impossible++;
	}
	if(impossible == 0) cout << result << endl;
	else
	{
		if(sum % 3 == 0)
		{
			sort(arr, arr+strlen(input));
			for(int i = strlen(input)-1; i >=0; i--)
			{
				cout << arr[i];
			}
			cout << endl;
		}
		else
			cout << result << endl;
	}
	

	return 0;
}
