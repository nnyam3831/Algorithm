/*
항상 기저 사례를 제일 먼저 처리해야한다.  
*/

int cache[2500][2500];

int someObscureFunction(int a, int b){
	
	// 기저 사례를 처음에 처리
	if(...) return ...;
	// (a,b) 구한 적이 있으면 바로 반환
	int& ret = cache[a][b];
	if(ret != -1) return ret;
	...
	
	return ret; 
}
