#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int Min[10];
int Max[10];
char input[100];
int main(void)
{
	char c;
	int MaxCount = 0;
	int MinCount = 0;
	int N;
	cin >> N;

	int index = 0;
	while(index != N)
	{
		cin >> c;
		if(c != ' ')
		{
			input[index] = c;
			index++;
		}
	}
	for(int i = 0; i < N; i++)
	{
		printf("%c\n", input[i]);
	}
	for(int i = 0; i <= N; i++)
	{
		printf("%d", Min[i]);
	}
	printf("\n");
	return 0;
}
