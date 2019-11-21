// string size 는 문자의 크기만 !!
// erase 함수로 제거 가능 
// 시간 초과 뜨므로 이중포문이 아니라 반복문 하나만 써서 해결해야함 : 스택 or 큐  
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
