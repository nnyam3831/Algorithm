#include <iostream>
#include <vector>
#define MAX 40000 + 1
using namespace std;

struct Node{
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};


// ���������� �������� �������� �ʰ� �ѹ��� ���� 
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
