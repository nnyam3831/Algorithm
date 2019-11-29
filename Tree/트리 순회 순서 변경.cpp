/*
Algospot(ID: TRAVERSAL)
Ʈ���� preorder, inorder�� �־����� �̸� postorder�� ����϶� 
O(n^2)
*/

vector<int> slice(const vector<int>& v, int a, int b){
	return vector<int>(v.begin()+a, v.begin()+b);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder){
	const int N = preorder.size();
	if(preorder.empty()) return;
	const int root = preorder[0];
	
	// ������ ���� 
	const int Left = find(inorder.begin(), inorder.end(), root)-inorder.begin();
	const int Right = N - Left - 1;
	
	// ���� ���  
	printPostOrder(slice(preorder, 1 , Left+1), slice(inorder, 0, Left));  
	// ������ ���
	printPostOrder(slice(preorder,Left+1,N), slice(inorder, Left+1,N));
	cout << root << ' '; 
} 
