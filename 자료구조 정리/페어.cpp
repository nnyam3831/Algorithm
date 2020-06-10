#include <iostream>
using namespace std;

template <class T1, class T2>
class _pair{
	public:
		T1 first;
		T2 second;
		
		_pair(const T1& f, const T2& s): first(f), second(s){}
		
};

int main(void){
	
	pair<int,int> p(1, 2);
	cout << p.first << " " << p.second << "\n";
		return 0;
}
