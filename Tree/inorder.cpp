#include <iostream>

using namespace std;

template<typename T>
struct Node{
	Node* left;
	Node* right;
	Node* parent;
	T value;
};

template<typename T>
class BST{
	
	public:
		Node<T>* root;
		
		void Inorder(Node<T>* current){
			if(current != nullptr){
				Inorder(current->left);
				cout << current->value << " ";
				Inorder(current->right);
			}
		}
		BST() :root(nullptr){
		};
		~BST(){
		};
		void AddNode(T _value);		
		void Display();
};

template <typename T>
void BST<T>::Display(){
	Inorder(root);
}

template <typename T>
void BST<T>::AddNode(T _value){
	Node<T>* node = new Node<T>();
	Node<T>* tmpRoot = nullptr;
	node->value = _value;
	
	if(root == nullptr)
		root = node;
	else{
		Node<T>* ptr = root;
		while (ptr != nullptr){
			tmpRoot = ptr;
			if(node->value < ptr->value){
				ptr = ptr->left;
			}else{
				ptr = ptr->right;
			}
		}
		if(node->value < tmpRoot->value)
			tmpRoot->left = node;
		else
			tmpRoot->right = node;
	}
}

int main(void){
	BST<int>* binearySearch = new BST<int>();
	binearySearch->AddNode(1); 
	binearySearch->AddNode(3); 
	binearySearch->AddNode(6); 
	binearySearch->AddNode(9); 
	binearySearch->AddNode(13); 
	binearySearch->AddNode(22); 
	binearySearch->AddNode(17); 
	binearySearch->AddNode(10); 
	binearySearch->AddNode(2);
	binearySearch->Display(); cout << "\n";

}
