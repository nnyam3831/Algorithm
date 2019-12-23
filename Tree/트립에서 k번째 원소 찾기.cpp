/*
크기 순으로 나열했을 때, k번째로 오는 노드 찾기
k <= l : 왼쪽 서브트리에 있음
k = l+1 : 루트가 k번째 노드임
k > l+1 : 오른쪽 서브트리에 있음, 오른쪽에서 k-l-1번째 노드 
*/


// 트립이든 아니든 상관없이 검색하는 함수, 그러나 균형잡힌 트리여야 O(logN)에 수행가능
Node* kth(Node* root, int k){
	// 일단 왼쪽 서브트리 사이즈 계산
	int leftSize = 0;
	if(root->left != NULL) leftSize = root->left->size;
	if(k <= leftSize) return kth(root->left, k);
	if(k == leftSize + 1) return root;
	if(k > leftSize + 1) return kth(root->right, k-leftSize-1); 
} 

// 범위 안에 있는 원소 찾기
// x보다 작은 원소의 수를 반환하는 countLessThan(x)
// [a, b) => countLessThan(b) - countLessThan(a)

// key보다 작은 키값의 수를 리턴
int countLessThan(Node* root, KeyType key){
	if(root == NULL) return 0;
	if(root->key >= key)
		return countLessThan(root->left, key);
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
} 


