#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
	char input[100];
	int firstIndex = 0;
	int Sum1 = 0;
	int Sum2 = 0;
	int Sum = 0;
	char buff[100];
	int stop = 0;
	int i = 0;
	
	buff[0] = '\0';
	cin >> input;
	while(1)
	{
	
		if(input[i] == '\0')
			break;
		if(input[i] == '-')
		{
		
			firstIndex = i;
			break;
		}
		i++;
	}
	
	if(firstIndex == 0)
	{
		for(int j = 0; stop != 1; j++)
		{
		if(input[j] == NULL)
			stop = 1;
		
		
		
		if(input[j] >= '0' && input[j] <= '9')
		{
			strncat(buff, input+j, 1);
		
		}
		else
		{
			int A = atoi(buff);
			Sum1 += A;
			buff[0] = '\0';
		
		}
	}
		Sum = Sum1;
	}
	else
	{
	

	for(int j = 0; j <= firstIndex; j++)
	{
		
		
		
		if(input[j] >= '0' && input[j] <= '9')
		{
			strncat(buff, input+j, 1);
			
		}
		else
		{
			int A = atoi(buff);
			Sum1 += A;
			buff[0] = '\0';
		
		}
	}
	for(int j = firstIndex; stop != 1; j++)
	{
		if(input[j] == NULL)
			stop = 1;
		if(input[j] >= '0' && input[j] <= '9')
		{
		
			strncat(buff, input+j, 1);
		}
		else
		{
			int A = atoi(buff);
			Sum2 += A;	
			buff[0] = '\0';
		
		}
	}
	 Sum = Sum1 - Sum2;
	}

	cout << Sum << endl;
	return 0;
}
