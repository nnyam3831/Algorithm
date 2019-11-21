#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int compareString(char* A, char* B)
{
	int count = 0;
	for(int i = 0; i < strlen(A); i++)
	{
		if(A[i] != B[i]) count++;
	}
	return count;
}
int main(void)
{
	char A[50];
	char B[50];
	int Min = 100;
	cin >> A >> B;
	
	int distance = strlen(B) - strlen(A);
	for(int i = 0; i <= distance; i++)
	{
		Min = min(Min, compareString(A, B+i));
	}
	
	cout << Min << endl;
	
	return 0;
}
