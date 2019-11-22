// ID : WILDCARD (algospot)
// �ð����⵵ O(n^3) or O(n^2)
// �޸������̼� ����� ��� �ִ��� �κй����� �ѱ�� ���� �ݺ����� ���̴� ���� ȿ����  
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

string W,S;

// �ִ� 100���� ����
// -1�� ���� ���� X, 1�� �Էµ帵 ���� ������, 0�� �Էµ��� ���� �������� ����  
int cache[101][101];

// ���ϵ�ī�� ���� W[w...] �� ���ڿ� S[s...]�� ���� �Ǵ��� ���θ� ��ȯ�� 
// �׻� ���̻簡 ���� ������ ���̸� �˸� ���ڸ� �� �� �ִ�. => ���������� ����ϴ� ����  
bool match(int w, int s){
	// �޸������̼�
	int& ret = cache[w][s]; 
	if(ret != -1) return ret;
	// W[w]�� S[s]�� ���糪�� 
	if(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])){
		return ret = match(w+1,s+1);
	}
	// ���� ���� �����ؼ� ���� ���� ���ڿ��� ������� True
	if(w == W.size()) return ret = (s == S.size());
	// *�� ������ ������� ��������� ȣ�� 
	if(W[w] == '*'){
		// *�� ��� �ƹ� ���ڵ� ��ġ��Ű�� �������ΰ� or �� ���ڸ� �� ������ų ���ΰ� ����� Ž��  
		if(match(w+1,s) || (s < S.size() && match(w,s+1)))
		{
			return ret = 1;
		}
	}
	return ret = 0;
}
int main(void){
	
	int Test;
	cin >> Test;
	for(int t = 0; t < Test; t++){
		int n;
		cin >> W;
		cin >> n;
		vector<string> v;
		for(int i = 0; i < n; i++){
			memset(cache,-1,sizeof(cache));
			cin >> S;
			if(match(0, 0) == 1){
				v.push_back(S);
			}
			
		}
		for(int i = 0; i < v.size(); i++){
			cout << v[i] << "\n";
		}
	
	}
	return 0;
}
