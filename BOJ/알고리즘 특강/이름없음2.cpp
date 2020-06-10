#include <iostream>
#include <vector>
#define MAX 40000 + 1
using namespace std;

int size;
int arr[100002];
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int data){
			this->data = data;
			this->left = nullptr;
			this->right = nullptr;
		}
};


// 위에서부터 내려가야 복잡하지 않게 한번에 가능 
void setTree(Node* n, int value){
	if(n->data < value){
		if(n->right == nullptr){
			Node* child = new Node(value);
			n->right = child;
			return;
		}else{
			setTree(n->right, value);
		}
	}else{
		if(n->left == nullptr){
			Node* child = new Node(value);
			n->left = child;
			return;
		}else{
			setTree(n->left, value);
		}
	}
	return;
}
void postOrder(Node* n){
	if(n == nullptr) return;
	postOrder(n->left);
	postOrder(n->right);
	cout << n->data << "\n";
}
void input(){
	int num;
	while(scanf("%d", &num) != EOF){ arr[size++] = num; }

}
int main(void){
	
	input();
	Node* root = new Node(0);
	
	for(int i = 0; i < size-1; i++){
		int value = arr[i];
		if(i == 0){
			root->data = value;
		}else{
			setTree(root, value);
		}
	}
	
	postOrder(root);
	return 0;
}
