#include <iostream>
#include <vector>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		Node* parent;
		Node(int data){
			this->data = data;
			left = nullptr;
			right = nullptr;
			parent = nullptr;
		}
};

class Tree{
	public:
		Node* root;
		void makeTree(vector<int> array){	
			root = makeTreeR(array, 0, array.size()-1, nullptr);
		};
		Node* makeTreeR(vector<int> array, int start, int end, Node* parent){
			if(start > end) return nullptr;
			int mid = (start + end) / 2;
			Node* nextNode = new Node(array[mid]);
			nextNode->left = makeTreeR(array, start, mid-1, nextNode);
			nextNode->right = makeTreeR(array, mid + 1, end, nextNode);
			nextNode->parent = parent;
			return nextNode;
		}
		void searchBTree(Node* n, int find){
			if(find < n->data){
				cout << "Data is smaller than " <<  n->data << "\n";
				searchBTree(n->left, find);
			}else if(find > n->data){
				cout << "Data is bigger than " << n->data << "\n";
				searchBTree(n->right, find);
			}else{
				cout << "Data found!\n";
			}
		}
		void findNext(Node* node){
			if(node->right == nullptr){
				cout << findAbove(node->parent, node)->data << " is " << node->data << "'s next'";
			}else{
				cout << findBelow(node->right)->data << " is " << node->data << "'s next'";
			}
		}
		Node* findAbove(Node* root, Node* child){
			if(root == nullptr) return nullptr;
			if(root->left == child) return root;
			return findAbove(root->parent, root);
		}
		Node* findBelow(Node* root){
			if(root->left == nullptr) return root;
			return findBelow(root->left);
		}
};
int main(void){
	vector<int> array(10);
	for(int i = 0; i < 10; i++){
		array[i] = i;
	}
	Tree* t = new Tree();
	t->makeTree(array);
	
	t->searchBTree(t->root, 0);
	
	cout << "-----------\n";
	t->findNext(t->root->left->right->right);
	cout << "\n";
	t->findNext(t->root->left);
	cout << "\n";
	t->findNext(t->root);
	cout << "\n";
	return 0;
}
