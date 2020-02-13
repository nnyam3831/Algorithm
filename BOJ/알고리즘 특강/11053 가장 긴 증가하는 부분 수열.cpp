#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1000+1
using namespace std;

vector<int> LIS;
int input[MAX];
int main(void){
	int N;
	cin >> N;
	int start = 0;
	for(int i = 0; i < N; i++){
		int num;
		cin >> num;
		if(num > start){
			// ũ�� �־��ָ� ��.. ���� ����  
			LIS.push_back(num);
		}else{
			// �װ� �ƴϸ� ó������ ������ ã��
			int size = LIS.size();
			int index = 0;
			for(int j = 0; j < size; j++){
				if(num <= LIS[j]){
					// ó������ �۰ų� �������� ���� ���� 
					LIS[j] = num;
					break;
				}
			} 
		}
		start = LIS[LIS.size()-1];
//		for(int k = 0; k < LIS.size(); k++){
//			cout << LIS[k] << " ";
//		}
//		cout << "\n";
	}
	
	cout << LIS.size() << "\n";
	
	return 0;
}
