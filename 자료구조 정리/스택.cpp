// 스택 2개로 큐 만들기  
#include <iostream>
#include <stack>
using namespace std;

template <class T>
class _Queue{
	private:
		stack<T> main;
		stack<T> temp;
	public:
		_Queue(){}
		~_Queue(){}
		
		T front(){
			if(main.empty()){
				cout << "queue가 비어있음\n";
				
			}else{
				return main.top();
			} 
		}
		void push_back(T data){
			while(!main.empty()){
				T top = main.top();
				temp.push(top);
				main.pop();
			}
			main.push(data);
			while(!temp.empty()){
				T top = temp.top();
				main.push(top);
				temp.pop();
			}
		}
		void pop(){
			main.pop();
		}
		bool empty(){
			return main.empty();
		}
		int Size(){
			return main.size();
		}
};
int main(void){
	
	_Queue<int> Q1;
	_Queue<string> Q2;
	Q1.push_back(10);
	Q1.push_back(30);
	Q1.push_back(40);
	Q1.push_back(20);
	
	while(!Q1.empty()){
		cout << Q1.front() << " ";
		Q1.pop();
	}
	
	Q2.push_back("hello");
	Q2.push_back("hi");
	Q2.push_back("kkk");
	Q2.push_back("drink");
	
	while(!Q2.empty()){
		cout << Q2.front() << " ";
		Q2.pop();
	}
	return 0;
}
