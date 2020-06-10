#include <iostream>
using namespace std;

template <class T>
class Node{
	public:
		T value;
		Node* next = nullptr;
};

template <class T>
class SingleLinkedList{
	private:
		Node<T> *head;
		Node<T> *tail;
		int size = 0;
	public:
		SingleLinkedList() : head(nullptr), tail(nullptr){}
		~SingleLinkedList() {}
		
		void AddNode(T _value){
			Node<T> *node = new Node<T>;
			
			size++;
			node->value = _value;
			node->next = nullptr;
			
			if(head == nullptr){
				// 헤드가 됨
				head = node;
				tail = node; 
			}else{
				tail->next = node;
				tail = tail->next;
			}
		}
		void RemoveNode(T _value){
			Node<T> *ptr = head;
			Node<T> *tmp = ptr;
			
			while(ptr != nullptr){
				if(ptr->value == _value){
					break; 
				}else{
					tmp = ptr;
					ptr = ptr->next;
				}
			}
			if(ptr == nullptr){
				cout << "없음\n"; 
			}else{
				size--;
				tmp->next =  ptr->next;
				delete ptr;
			}
		}
		void Show(){
			Node<T> *node = head;
			while(node != nullptr){
				cout << node->value << "->";
				node = node->next;
			}
			cout << "\n";
		}
		void SearchValue(T _value){
			Node<T> *ptr = head;
			int index = 0;
			bool isFind = false;
			
			while(ptr != nullptr){
				index++;
				if(ptr->value == _value){
					cout << _value << " 값은 인덱스 " << index << " 번째에 있음\n";
					isFind = true;
					break;
				}else{
					ptr = ptr->next;
				}
			}
			if(!isFind){
				cout << _value << "값은 리스트에 없습니다\n";
			}
		}
		void DeleteList(){
			Node<T> *ptr = head;
			while(ptr != nullptr){
				head = ptr->next;
				delete ptr;
				ptr = head;
			}
			delete head;
			size = 0;
			
		}
		int Size()
		{
			return size;
		}
		
};

int main(void){
	
	SingleLinkedList<int> list;
	list.AddNode(1);
	list.AddNode(10);
	list.AddNode(3);
	list.AddNode(4);
	list.AddNode(9);
	list.AddNode(123);
	list.AddNode(2);
	list.AddNode(3);
	list.Show();
	list.SearchValue(123);
	list.RemoveNode(77);
	list.RemoveNode(3);
	
	list.SearchValue(123);
	list.DeleteList();
	cout << list.Size();
//	cout << &list;
	return 0;
}
