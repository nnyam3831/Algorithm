// AlgoSpot ID: family tree

// Ʈ���� ���� ���� ã��, �ּ� ���� ���� LCA(u,v)

// u -> v�� �Ѿ���� �׻� LCA(u,v)�� ���ľ� �Ѵ�
// LCA(u,v)���� �θ� ���� �ö󰡷��� �� ���� LCA(u,v)�� ��Ʈ�� �ϴ� ����Ʈ���� ��� ���ƺ�
// �Ŀ��� �ϱ� ������ ������� �� ���� �湮�� ���� ����.
// depth�� �����س��´ٸ�, u to LCA(u,v) = depth[u] - depth[LCA(u,v)] �� ���� �� 
// ���� ��ȸ�� �湮(preorder)

const int MAX_N = 100000;
int n;
vector<int> child[MAX_N];

// Ʈ���� ��ȣ�� �Ϸ� ��ȣ ������ ���� ����
int no2serial[MAX_N], serial2no[MAX_N];

// �� ��尡 trip�� ó�� �����ϴ� ��ġ, �׸��� �� ����� ����
int locInTrip[MAX_N], depth[MAX_N];

// ���� �Ϸ� ��ȣ 
int nextSerial;
// ���̰� d�� ��� here ���ϸ� ���� Ž��
void traverse(int here, int d, vector<int>& trip){
	// traverse()�� �湮���ڸ��� �Ϸ� ��ȣ�� �ο��Ѵ�.
	// �̷��� �ϸ� �׻� �θ�� �ڼպ��� ���� �Ϸ� ��ȣ�� ���Ե�
	no2serial[here] = nextSerial;
	serial2no[nextSerial] = here;
	++nextSerial;
	// ���� ���
	depth[here] = d;
	//trip�� ���� ����� �Ϸ� ��ȣ�� �߰�
	locInTrip[here] = trip.size();
	trip.push_back(no2serial[here]);
	
	// ��� �ڽ� ��带 �湮
	for(int i = 0; i < child[here].size(); i++){
		traverse(child[here][i], d+1, trip);
		// �ڽ� ��带 �湮�ϰ� ���� ���� ���ƿ� ������ �ٽ� �߰��ϱ�
		trip.push_back(no2serial[here]); 
	} 
} 
// Ʈ���� ��ȸ�ϸ� �ʿ��� ������ ����ϰ�,
// RMQ Ʈ���� ����� ����
RMQ* prepareRMQ(){
	nextSerial = 0;
	// ��ȸ �������� ������ ������ �Ϸ� ��ȣ�� ����
	vector<int> trip;
	traverse(0, 0, trip);
	return new RMQ(trip); 
} 

// u�� v ������ �Ÿ��� ���
int distance(RMQ* rmq, int u, int v){
	//trip[] �迭���� u�� v�� ù ���� ��ġ�� ã��
	int lu = locInTrip[u], lv = locInTrip[v];
	if(lu > lv) swap(lu,lv);
	int lca = serial2no[rmq->query(lu,lv)];
	return depth[u]+depth[v] - 2*depth[lca]; 
} 
