#include <iostream>
#include <vector>
#define MAX 40000 + 1
using namespace std;

struct Node{
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};


// 위에서부터 내려가야 복잡하지 않게 한번에 가능 
void setTree(Node* n, int value){
	
	return;
}
void postOrder(Node* n){
	if(n == nullptr) return;
	postOrder(n->left);
	postOrder(n->right);
	cout << n->data << "\n";
}
int main(void){
	
	int N;
	cin >> N;
	
	Node* root;
	root->data = 10;
	cout << root->data << "\n";
	for(int i = 0; i < N; i++){
		int val;
		cin >> val;
		setTree(root, val);
	}
	postOrder(root);
	return 0;
}
