/*
누르는 순서가 상관 없음  
시계는 0번에서 3번까지 누를 수 있다. (4번 = 0번), 4^10 의 경우에 대한 탐색이므로 완전탐색 가능
10조각으로 나누어 각 조각에서 한 스위치를 누를 횟수 정하기 
*/

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

// linked[i][j] : i번 스위치와 j번 스위치가 연결되어있는가

const char linked[SWITCHES][CLOCKS] ={
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x..",
};

// 모든 시계가 12시를 가르키는지 확인
bool areAligned(const vector<int>& clocks);

// switch번 스위치를 누름
void push(vector<int>& clocks, int switch){
	for(int clock = 0; clock < CLOCKS; clock++){
		if(linked[switch][clock] == 'x'){
			clocks[clock] += 3;
			if(clocks[clock] == 15) clocks[clock] = 3;
		}
	}
} 

// clocks : 현재 시계들의 상태
// switch : 이번에 누를 스위치의 번호
// 남은 스위치들을 눌러서 clocks를 12시로 맞출 수 있는 최소 횟수를 리턴
// 불가능하면 INF 이상의 수 리턴
// 0번 호출되는것부터 3번호출되는 것까지 완전탐색 => 최소 횟수 반환함  
int solve(vector<int>& clocks, int switch){
	if(switch == SWITCHES) return areAligned(clocks) ? 0 : INF;
	int ret = INF;
	for(int cnt = 0; cnt < 4; cnt++){
		ret = min(ret, cnt + solve(clocks, switch + 1));
		push(clocks, switch);
	}
	
	return ret; 
} 
