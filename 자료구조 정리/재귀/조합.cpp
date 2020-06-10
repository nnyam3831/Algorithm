#include <iostream>
using namespace std;


void permutate(int index,string cur,  string target, bool *visited, int size){
	if(size == 3){
		cout << cur << "\n";
		return;
	}
	
	for(int i = index; i < target.length(); i++){
		if(!visited[i]){
			visited[i] = true;
			permutate(i+1, cur + target[i],target, visited, size + 1);
			visited[i] = false;
		}
	}
}
int main(void){
	
	string target = "hello";
	bool *visited = new bool[10];
	for(int i = 0; i  < 10; i++){
		visited[i] = false;
	}
	permutate(0,"" ,target, visited, 0);
	return 0;
}
