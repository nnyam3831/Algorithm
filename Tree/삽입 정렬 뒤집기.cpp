/*
STL의 set은 k번째 원소를 찾는 기능을 제공하지 않으므로 트립으로 해결하자 
뒤에서 부터 나보다 큰 게 몇 개 있는지 
*/

// shifted[i] = A[i]가 왼쪽으로 몇칸 움직이는가?

int n, shifted[50000];
int A[50000];
// n, shifted[]를 보고 A[]에 값을 저장함
void solve(){
	// 1~N까지의 숫자를 모두 저장하는 트립
	Node* candidates = NULL;
	for(int i = 0; i < n; i++)
		candidates = insert(candidates, new Node(i+1));
	// 뒤에서부터 A[]를 채워나간다.
	for(int i = n-1; i >= 0; i--){
		// 후보 중 이 수보다 큰 수가 larger개 있다.
		int larger = shifted[i];
		Node* k = kth(candidates, i + 1 - larger);
		A[i] = k->key;
		
		// 해결된 값 지우고 계속해서 반복  
		candidates = erase(candidates, k->key); 
	} 
} 
