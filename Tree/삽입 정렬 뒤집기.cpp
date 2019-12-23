/*
STL�� set�� k��° ���Ҹ� ã�� ����� �������� �����Ƿ� Ʈ������ �ذ����� 
�ڿ��� ���� ������ ū �� �� �� �ִ��� 
*/

// shifted[i] = A[i]�� �������� ��ĭ �����̴°�?

int n, shifted[50000];
int A[50000];
// n, shifted[]�� ���� A[]�� ���� ������
void solve(){
	// 1~N������ ���ڸ� ��� �����ϴ� Ʈ��
	Node* candidates = NULL;
	for(int i = 0; i < n; i++)
		candidates = insert(candidates, new Node(i+1));
	// �ڿ������� A[]�� ä��������.
	for(int i = n-1; i >= 0; i--){
		// �ĺ� �� �� ������ ū ���� larger�� �ִ�.
		int larger = shifted[i];
		Node* k = kth(candidates, i + 1 - larger);
		A[i] = k->key;
		
		// �ذ�� �� ����� ����ؼ� �ݺ�  
		candidates = erase(candidates, k->key); 
	} 
} 
