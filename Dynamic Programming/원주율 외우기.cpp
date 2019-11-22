
const int INF = 987654321;
string N;
//  N[a,b] 구간의 난이도를 반환

int classify(int a, int b){
	// 숫자 조각을 가져옴
	string M = N.substr(a, b-a+1);
	if(M == string(M.size(), M[0]))	return 1;
	// 등차 수열 검사
	bool progressive = true;
	for(int i = 0; i < M.size()-1; i++){
		if(M[i+1]-M[i] != M[1] - M[0])
			progressive = false;
	} 
	
	// 등차수열이고 공차가 1 혹은 -1이면 난이도는 2
	if(progressive && abs(M[1]-M[0]) == 1)
		return 2;
		
	bool alternating = true;
	for(int i = 0; i < M.size(); i++){
		if(M[i] != M[i%2])
			alternating = false;
	} 
	if(alternating) return 4;
	if(progressive) return 5;
	return 10;
} 

int cache[10002];
// 수열 N[begin..]중 최소 난이도 

int memorize(int begin){
	// 기저 : 수열의 끝
	if(begin == N.size()) return 0;
	
	// 메모이제이션
	int& ret = cache[begin];
	if(ret != -1) return ret;
	ret = INF;
	for(int L = 3; L <= 5; L++){
		if(begin + L <= N.size()){
			ret = min(ret, memorize(begin+L) + classify(begin, begin+L-1));
		}
	} 
	return ret;
} 
