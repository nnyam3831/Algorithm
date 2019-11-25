// AlgoSpot(ID: NUMB3RS)


/*
1번: 시간복잡도 O(n^2dt), search2(here, days) = 두니발 박사가 days일 때에 here번 마을에 숨어있을 때
, 마지막 날에 q번 마을에 있을 조건부 확률 
*/

int n, d, p, q;
double cache[51][101];
// connected[i][j] 마을 i, j가 연결되어 있는가
// deg[i] = 마을 i와 연결된 마을의 개수

int connected[51][51], deg[51];

double search2(int here, int days){
	// 기저: 마지막 날
	if(days == d) return (here == q ? 1.0 : 0.0);
	// 메모이제이션
	double& ret = cache[here][days];
	if(ret > -0.5) return ret;
	ret = 0.0;
	for(int there = 0; there < n; there++){
		if(connected[here][there]){
			ret += search2(there, days+1) / deg[here];
		}
	}
	return ret;
} 


/*
반대 방향으로 풀기: 시간복잡도 O(n^2d)
search3(here, days) = 탈옥 후 days일 째에 두니발 박사가 here번 마을에 숨어있을 확률 
*/

double search3(int here, int days){
	// 기저: 0일째
	if(days == 0) return (here == p ? 1.0 : 0.0);
	// 메모이제이션
	double& ret = cache[here][days];
	if(ret > -0.5) return ret;
	ret = 0.0;
	for(int there = 0; there < n; there++){
		if(connected[here][there]){
			ret += search3(there,days-1) / deg[there];
		}
	} 
	return ret;
}
