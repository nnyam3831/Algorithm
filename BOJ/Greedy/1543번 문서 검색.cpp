// 공백포함 받기  

#include <iostream>
#include <string.h>

using namespace std;
int findString(char* parent, char* pattern)
{
	int parentSize = strlen(parent);
	int patternSize = strlen(pattern);
	if(patternSize > parentSize) return -1;
	for(int i = 0; i <= parentSize - patternSize; i++)
	{
		bool finded = true;
		for(int j = 0; j < patternSize; j++)
		{
			
			if(parent[i+j] != pattern[j])
			{
				finded = false;
				break;
			}
		}
		if(finded) 
		{
			return i+patternSize;
		}
	}
	
	return -1;
}
int main(void)
{
	char parent[2500];
	char pattern[2500];
	int cnt = 0;
	int index = 0;
	scanf("%[^\n]%*c", parent);
	scanf("%[^\n]%*c", pattern);
	char *c = parent;
	while(index != -1)
	{
	
		index = findString(c,pattern);
	
		if(index != -1)
		{
			cnt++;
			c = (c+index);
		}
	}
	
	cout << cnt << endl;
	return 0;
}
