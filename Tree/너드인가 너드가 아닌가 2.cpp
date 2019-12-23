/*
Algospot(ID: NERD2)
���� �˻� Ʈ�� 
���� �� p, ��� �׸� �� q�� �ٸ� �����ڵ麸�� �� �� �۴ٸ� �ʵ尡 �ƴ�
������ ����� �� �� ���� �Ʒ��� ������ �� ����
a�� b�� �����Ѵ�: a�� b���� ������ ���� �ִ�.
�ٷ� �����ʿ� �ִ� ���� ã�� ����, ���� �߰��� ���� ���� ������ �� �� �ִ� �ڷᱸ�� = ���� �˻� Ʈ��
O(NlogN) 
*/

// ���� �ٸ� ���� ��������� �ʴ� ������ ����� ������
// coords[x] = y
map<int, int> coords;
// ���ο� �� (x,y)�� ������ �ٸ� ���鿡 ������ϴ��� Ȯ���Ѵ�.

// �� ���� �ٸ� ���� ������ϴ��� Ȯ�� 
bool isDominated(int x, int y){
	// x���� �����ʿ� �ִ� �� �� ���� ���ʿ� �ִ� ���� ã��
	map<int, int>::iterator it = coords.lower_bound(x);
	// �׷� ���� ������ (x,y)�� ��������� ����
	if(it == coords.end())  return false;
	// �� ���� x���� �����ʿ� �ִ� �� �� ���� ���� �ִ� ����
	// (x,y)�� ����Ƿ��� �� ������ ����Ǿ�� ��
	return y < it->second; 
} 

// ���ο� �� (x,y)�� ������ϴ� ������ Ʈ������ ����
void removeDominated(int x, int y){
	map<int, int>::iterator it = coords.lower_bound(x);
	// (x,y)���� ���ʿ� �ִ� ���� ������!
	if(it == coords.begin()) return;
	--it;
	
	// �ݺ��� �Һ���: it�� (x,y)�� �ٷ� ���ʿ� �ִ� ��
	while(true){
		// (x,y) �ٷ� ���ʿ� ���� ���� ã��
		// it�� ǥ���ϴ� ���� (x,y)�� ��������� �ʴ´ٸ� ���� ����
		if(it->second > y) break;
		// ���� ���� �� �����Ƿ� it�� ����� �����Ѵ�.
		if(it == coords.begin()){
			coords.erase(it);
			break;
		}
		// ���� ������ ���ͷ����͸� �ϳ� �Ű� ���� it�� �����. 
		else{
			map<int, int>::iterator jt = it;
			--jt;
			coords.erase(it);
			it = jt;
		} 
	} 
} 

// �� ��(x,y)�� �߰��Ǿ����� coords�� �����ϰ�
// �ٸ� ���� ��������� �ʴ� ������ ������ ������
int registered(int x, int y){
	// (x,y)�� �̹� ������ϴ� ��쿡�� �׳� (x,y)�� ����
	if(isDominated(x, y)) return coords.size();
	// ������ �ִ� �� �� (x,y)�� ������ϴ� ������ ����
	removeDominated(x, y);
	coords[x] = y;
	return coords.size(); 
} 
