#include <iostream>
using namespace std;

template <class T>
class Stack{
	private:
		T *values;
		int size;
		int top;
	public:
		Stack(){
			this->size = size;
			this->values = new T[size];
			this->top = -1;
		}	
		~Stack(){
			delete[] values;
		}
		
		void push(T data){
			values[++top] = data;
		}
		T pop(){
			int ret = values[top--];
			return ret;
		}
};

int main(void){
	
	Stack<int> s;
	s.push(1);
	s.push(2);
	cout << s.pop();
	cout << s.pop();
	
	return 0;
}
