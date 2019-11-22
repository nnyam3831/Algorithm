// ID : WILDCARD (algospot)
// 시간복잡도 O(n^3) or O(n^2)
// 메모이제이션 사용할 경우 최대한 부분문제로 넘기고 내부 반복문을 줄이는 것이 효율적  
#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

string W,S;

// 최대 100글자 각각
// -1은 아직 답계산 X, 1은 입력드링 서로 대응됨, 0은 입력들이 서로 대응되지 않음  
int cache[101][101];

// 와일드카드 패턴 W[w...] 가 문자열 S[s...]에 대응 되는지 여부를 반환함 
// 항상 접미사가 오기 때문에 길이만 알면 문자를 알 수 있다. => 전역변수를 사용하는 이유  
bool match(int w, int s){
	// 메모이제이션
	int& ret = cache[w][s]; 
	if(ret != -1) return ret;
	// W[w]와 S[s]를 맞춰나감 
	if(s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])){
		return ret = match(w+1,s+1);
	}
	// 패턴 끝에 도달해서 끝난 경우는 문자열도 끝났어야 True
	if(w == W.size()) return ret = (s == S.size());
	// *를 만나서 끝난경우 재귀적으로 호출 
	if(W[w] == '*'){
		// *일 경우 아무 글자도 매치시키지 않을것인가 or 한 글자를 더 대응시킬 것인가 재귀적 탐색  
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
