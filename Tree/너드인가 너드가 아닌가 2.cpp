/*
Algospot(ID: NERD2)
이진 검색 트리 
문제 수 p, 라면 그릇 수 q가 다른 참가자들보다 둘 다 작다면 너드가 아님
이차원 평면의 점 중 왼쪽 아래는 참가할 수 없음
a가 b를 지배한다: a가 b보다 오른쪽 위에 있다.
바로 오른쪽에 있는 점을 찾는 연산, 점의 추가와 삭제 등을 빠르게 할 수 있는 자료구조 = 이진 검색 트리
O(NlogN) 
*/

// 현재 다른 점에 지배당하지 않는 점들의 목록을 저장함
// coords[x] = y
map<int, int> coords;
// 새로운 점 (x,y)가 기존의 다른 점들에 지배당하는지 확인한다.

// 한 점이 다른 점에 지배당하는지 확인 
bool isDominated(int x, int y){
	// x보다 오른쪽에 있는 점 중 가장 왼쪽에 있는 점을 찾음
	map<int, int>::iterator it = coords.lower_bound(x);
	// 그런 점이 없으면 (x,y)는 지배당하지 않음
	if(it == coords.end())  return false;
	// 이 점은 x보다 오른쪽에 있는 점 중 가장 위에 있는 점임
	// (x,y)가 지배되려면 이 점에도 지배되어야 함
	return y < it->second; 
} 

// 새로운 점 (x,y)에 지배당하는 점들을 트리에서 지움
void removeDominated(int x, int y){
	map<int, int>::iterator it = coords.lower_bound(x);
	// (x,y)보다 왼쪽에 있는 점이 없으면!
	if(it == coords.begin()) return;
	--it;
	
	// 반복문 불변식: it는 (x,y)의 바로 왼쪽에 있는 점
	while(true){
		// (x,y) 바로 왼쪽에 오는 점을 찾음
		// it가 표시하는 점이 (x,y)에 지배당하지 않는다면 당장 종료
		if(it->second > y) break;
		// 이전 점이 더 없으므로 it만 지우고 종료한다.
		if(it == coords.begin()){
			coords.erase(it);
			break;
		}
		// 이전 점으로 이터레이터를 하나 옮겨 놓고 it를 지운다. 
		else{
			map<int, int>::iterator jt = it;
			--jt;
			coords.erase(it);
			it = jt;
		} 
	} 
} 

// 새 점(x,y)가 추가되었을때 coords를 갱신하고
// 다른 점에 지배당하지 않는 점들의 개수를 리턴함
int registered(int x, int y){
	// (x,y)가 이미 지배당하는 경우에는 그냥 (x,y)를 버림
	if(isDominated(x, y)) return coords.size();
	// 기존에 있던 점 중 (x,y)에 지배당하는 점들을 지움
	removeDominated(x, y);
	coords[x] = y;
	return coords.size(); 
} 
