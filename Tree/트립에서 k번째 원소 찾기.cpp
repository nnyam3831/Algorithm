/*
ũ�� ������ �������� ��, k��°�� ���� ��� ã��
k <= l : ���� ����Ʈ���� ����
k = l+1 : ��Ʈ�� k��° �����
k > l+1 : ������ ����Ʈ���� ����, �����ʿ��� k-l-1��° ��� 
*/


// Ʈ���̵� �ƴϵ� ������� �˻��ϴ� �Լ�, �׷��� �������� Ʈ������ O(logN)�� ���డ��
Node* kth(Node* root, int k){
	// �ϴ� ���� ����Ʈ�� ������ ���
	int leftSize = 0;
	if(root->left != NULL) leftSize = root->left->size;
	if(k <= leftSize) return kth(root->left, k);
	if(k == leftSize + 1) return root;
	if(k > leftSize + 1) return kth(root->right, k-leftSize-1); 
} 

// ���� �ȿ� �ִ� ���� ã��
// x���� ���� ������ ���� ��ȯ�ϴ� countLessThan(x)
// [a, b) => countLessThan(b) - countLessThan(a)

// key���� ���� Ű���� ���� ����
int countLessThan(Node* root, KeyType key){
	if(root == NULL) return 0;
	if(root->key >= key)
		return countLessThan(root->left, key);
	int ls = (root->left ? root->left->size : 0);
	return ls + 1 + countLessThan(root->right, key);
} 


