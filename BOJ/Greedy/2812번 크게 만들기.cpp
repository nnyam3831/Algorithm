// string size �� ������ ũ�⸸ !!
// erase �Լ��� ���� ���� 
// �ð� �ʰ� �߹Ƿ� ���������� �ƴ϶� �ݺ��� �ϳ��� �Ἥ �ذ��ؾ��� : ���� or ť  
#include <iostream>
#include <string>
#include <stack> 

using namespace std;
char s[500001];
stack <char> t, tmp;
int main(void)
{
	int n, k, top = 0; char c, stack[500000];
	cin >> n >> k;
	while(n--)
	{
		do{
			cin >> c;
		}while(c < 48 || 57 < c);
		while(k > 0 && top > 0 && stack[top-1] < c) {
			top--; k--;
		}
		stack[top++] = c;
	}
	top -= k;
	stack[top] = 0; puts(stack);
	return 0;
}
