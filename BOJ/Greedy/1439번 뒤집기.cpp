#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int Group = 0;
	string input;
	
	cin >> input;
	
	char Key = input[0];
	for(int i = 0; i <= input.size(); i++)
	{
		if(Key == input[i]) continue;
	
		Key = input[i];
		Group++;
	}
	
	cout << Group / 2 << endl;
	return 0;
}
