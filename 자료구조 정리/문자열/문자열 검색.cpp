// ù ��°�� �ߺ����� �ʴ� ���� ã�´ٰ� ��������
 
#include <iostream>
#include <string>
using namespace std;

int table[27];
int main(void){
	
	string parent = "aldksjaldksjdlasjdlasjfnanwnesbdbqasez";
	cout << 
	// table ����
	for(int i = 0; i < parent.length(); i++){
		table[parent[i]-'a']++;
	}	
	for(int i = 0; i < parent.length(); i++){
		char key = parent[i];
		if(table[key-'a'] == 1){
			cout << key << "���� ó������ �ݺ����� ���� character !!, index: " << i << "\n"; 
		}
	}
	return 0;
}
