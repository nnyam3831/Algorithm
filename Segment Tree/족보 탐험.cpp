// AlgoSpot ID: family tree

// 트리의 공통 조상 찾기, 최소 공통 조상 LCA(u,v)

// u -> v로 넘어가려면 항상 LCA(u,v)를 거쳐야 한다
// LCA(u,v)에서 부모 노드로 올라가려면 그 전에 LCA(u,v)를 루트로 하는 서브트리를 모두 돌아본
// 후여야 하기 때문에 조상들을 그 전에 방문할 일은 없다.
// depth를 저장해놓는다면, u to LCA(u,v) = depth[u] - depth[LCA(u,v)] 와 같은 식 
// 전위 순회로 방문(preorder)

const int MAX_N = 100000;
int n;
vector<int> child[MAX_N];

// 트리의 번호와 일련 번호 서아의 대응 관계
int no2serial[MAX_N], serial2no[MAX_N];

// 각 노드가 trip에 처음 등장하는 위치, 그리고 각 노드의 깊이
int locInTrip[MAX_N], depth[MAX_N];

// 다음 일련 번호 
int nextSerial;
// 깊이가 d인 노드 here 이하를 전위 탐색
void traverse(int here, int d, vector<int>& trip){
	// traverse()가 방문하자마자 일련 번호를 부여한다.
	// 이렇게 하면 항상 부모는 자손보다 작은 일련 번호를 갖게됨
	no2serial[here] = nextSerial;
	serial2no[nextSerial] = here;
	++nextSerial;
	// 깊이 계산
	depth[here] = d;
	//trip에 현재 노드의 일련 번호를 추가
	locInTrip[here] = trip.size();
	trip.push_back(no2serial[here]);
	
	// 모든 자식 노드를 방문
	for(int i = 0; i < child[here].size(); i++){
		traverse(child[here][i], d+1, trip);
		// 자식 노드를 방문하고 현재 노드로 돌아올 때마다 다시 추가하기
		trip.push_back(no2serial[here]); 
	} 
} 
// 트리를 순회하며 필요한 정보를 계산하고,
// RMQ 트리를 만들어 리턴
RMQ* prepareRMQ(){
	nextSerial = 0;
	// 순회 과정에서 만나는 노드들의 일련 번호를 담음
	vector<int> trip;
	traverse(0, 0, trip);
	return new RMQ(trip); 
} 

// u와 v 사이의 거리를 계산
int distance(RMQ* rmq, int u, int v){
	//trip[] 배열에서 u와 v의 첫 출현 위치를 찾음
	int lu = locInTrip[u], lv = locInTrip[v];
	if(lu > lv) swap(lu,lv);
	int lca = serial2no[rmq->query(lu,lv)];
	return depth[u]+depth[v] - 2*depth[lca]; 
} 
