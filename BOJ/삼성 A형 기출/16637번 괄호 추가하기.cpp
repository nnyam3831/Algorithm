#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAX 20
#define INF 987654321

using namespace std;

int n, ans;
char map[MAX];
int check[MAX];		// 괄호가 있는 숫자: 1, 없으면: 0 

int calculate(int A, int B, char Op){
	switch(Op){
		case '+':
			return A+B;
		case '-':
			return A-B;
		case '*':
			return A*B;
		default:
			break;
	}
	return 0;
}
int getResult(){
	vector<string> temp;
	string str ="";
	int i = 0;
	while(i < n){
		// 일반 정수, 연산자 push 괄호X 
		if(check[i] == 0){
			str = map[i];
			temp.push_back(str);
			i++;
		}
		// 괄호가 있는 숫자  
		else if(check[i] == 1){
			int a = map[i]-'0';
			int b = map[i+2]-'0';
			char op = map[i+1];
			temp.push_back(to_string(calculate(a,b,op)));
			i+=3;
		}
	}
	int res = stoi(temp[0]);
	for(int i=1; i < temp.size(); i+=2){
		if(temp[i]=="+"){
			res += stoi(temp[i+1]);
		}else if(temp[i]=="-"){
			res -= stoi(temp[i+1]);
		}else if(temp[i]=="*"){
			res *= stoi(temp[i+1]);
		}
	}
	
	return res;
} 
void dfs(int index){
	ans = max(ans, getResult());
	
	// 반복문 이용한 dfs 탐색
	for(int i=index; i+2<n; i+=2){
		if(check[i] == 0 && check[i+2] == 0){
			check[i] = 1; check[i+2] = 1;
			dfs(index+2);
			check[i] = 0; check[i+2] = 0;
		}
	} 
}
int main(void){
	
	cin >> n;
	for(int i=0; i < n; i++){
		cin >> map[i];
	}
	
	ans = -INF;
	dfs(0);
	cout << ans << "\n";
	return 0;
} 
