#include <iostream>
using namespace std;

template <class T>
class Stack
{
	public:
		Stack(): head(nullptr){};
		~Stack();
		void push(T data);
		T pop();
	protected:
		class Element{
			public:
				Element(Element* n, T d): next(n), data(d){
				}
				Element *getNext() const {return next;}
				T value() const {return data;}
			private:
				Element* next;
				T data;
		};
		
		Element* head;
};

template<class T>
Stack<T>::~Stack(){
	while(head){
		Element* next = head->getNext();
		delete head;
		head = next;
	}
} 

template<class T>
void Stack<T>::push(T data){
	Element* element = new Element(head, data);
	head = element;
}

template <class T>
T Stack<T>::pop(){
	Element *popElement = head;
	T data;
	
//	if(head == nullptr) throw StackError(E_EMPTY);
	
	data = head->value();
	head = head->getNext();
	delete popElement;
	return data;
}

int main(void){
	
	Stack<int> s;
	s.push(1);
	s.push(2);
	cout << s.pop();
	cout << s.pop();
	
	return 0;
}
