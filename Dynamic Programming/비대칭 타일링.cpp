// 직접 세기 : 양쪽 끝에서부터 추가하면서 계산함
// 전체수 - 대칭인 수 = 비대칭수 로 구하는 게 훨씬 간단함 


// 직접 구하는 방법

int cache2[101];

int asymmetric2(int width){
	
	// 기저 
	if(width<=2) return 0;
	
	// 메모이제이션
	int& ret = cache2[width];
	if(ret != -1) return ret;
	ret = (ret + asymmetric2(width-2)) % MOD;
	ret = (ret + assymetric2(width-4)) % MOD;
	ret = (ret + tiling(width-3)) % MOD;
	ret = (ret + tiling(width-3)) % MOD;
	
	return ret;
} 
