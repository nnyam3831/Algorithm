#include <iostream>
#include <algorithm>

using namespace std;

struct info{
	int time;
	int count;
	int number;
};
int N, M;
info picture[21];
int size;
bool cmp1(const info &A, const info &B){
	if(A.count == B.count) return A.time < B.time;
	return A.count < B.count;
}
bool cmp2(const info &A, const info &B){
	return A.number < B.number;
}
int check(int number){
	for(int i = 1; i <= size; i++){
		if(picture[i].number == number) return i;
	}
	return -1;
}
int main(void){
	
	cin >> N >> M;
	int time = 0;
	for(int i = 0; i < M; i++){
		int x;
		cin >> x;
		size++;
		time++;
		// size over
		if(size > N){
			// 이미 등록된 녀석이면
			if(check(x) != -1){
				int index = check(x);
				picture[index].count++;
				size--;
			}else{
				// 처음 등록된거면
				sort(picture+1, picture+size, cmp1);
				picture[1].number = x;
				picture[1].count = 1;
				picture[1].time = time;
				size--; 
			}
		}
		// size small
		else{
			// 이미 등록된 녀석이면 
			if(check(x) != -1){
				int index = check(x);
				picture[index].count++;
				size--;
			}else{
				picture[size].count = 1;
				picture[size].time = time;
				picture[size].number = x;
			}
		}
		sort(picture+1, picture+1+size, cmp1);
//		cout << "------\n";
//		for(int i = 1; i <= size; i++){
//			cout << picture[i].number << " ";
//		}
//		cout<<"\nc: ";
//		for(int i = 1; i <= size; i++){
//			cout <<  picture[i].count << " ";
//		}
//		cout<<"\n";
//		cout<<"\nt: ";
//		for(int i = 1; i <= size; i++){
//			cout << picture[i].time << " ";
//		}
//		cout<<"\n";
//		cout << "------\n";
//		cout<<"\n";
	}
	sort(picture+1, picture+1+size, cmp2);
	for(int i = 1; i <= size; i++){
		cout << picture[i].number << " ";
	}
	cout << "\n";
	return 0;
}
