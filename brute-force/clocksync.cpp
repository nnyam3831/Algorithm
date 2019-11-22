/*
������ ������ ��� ����  
�ð�� 0������ 3������ ���� �� �ִ�. (4�� = 0��), 4^10 �� ��쿡 ���� Ž���̹Ƿ� ����Ž�� ����
10�������� ������ �� �������� �� ����ġ�� ���� Ƚ�� ���ϱ� 
*/

const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

// linked[i][j] : i�� ����ġ�� j�� ����ġ�� ����Ǿ��ִ°�

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

// ��� �ð谡 12�ø� ����Ű���� Ȯ��
bool areAligned(const vector<int>& clocks);

// switch�� ����ġ�� ����
void push(vector<int>& clocks, int switch){
	for(int clock = 0; clock < CLOCKS; clock++){
		if(linked[switch][clock] == 'x'){
			clocks[clock] += 3;
			if(clocks[clock] == 15) clocks[clock] = 3;
		}
	}
} 

// clocks : ���� �ð���� ����
// switch : �̹��� ���� ����ġ�� ��ȣ
// ���� ����ġ���� ������ clocks�� 12�÷� ���� �� �ִ� �ּ� Ƚ���� ����
// �Ұ����ϸ� INF �̻��� �� ����
// 0�� ȣ��Ǵ°ͺ��� 3��ȣ��Ǵ� �ͱ��� ����Ž�� => �ּ� Ƚ�� ��ȯ��  
int solve(vector<int>& clocks, int switch){
	if(switch == SWITCHES) return areAligned(clocks) ? 0 : INF;
	int ret = INF;
	for(int cnt = 0; cnt < 4; cnt++){
		ret = min(ret, cnt + solve(clocks, switch + 1));
		push(clocks, switch);
	}
	
	return ret; 
} 
