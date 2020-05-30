#include <iostream>
#include <string>
#include <vector>

#define HASH_MAX 15
#define a 7
using namespace std;

typedef pair<string,int> psi;
vector<psi> hash_table[HASH_MAX];

int main(void){
	
	for(int i = 0; i < 6; i++){
		string key;
		int value;
		cout << "Key :: ";
		cin >> key;
		cout << "Value ::";
		cin >> value;
		
		int hashKey = (a * key.length()) % HASH_MAX;
		
		hash_table[hashKey].push_back({key, value});
		
		cout << "\n";
	}
	
	cout << "Hash Table에서 탐색\n";
	for(int i = 0; i < 6; i++){
		string key;
		cout << "key :: ";
		cin >> key;
		
		int hashKey = (a*key.length()) % HASH_MAX;
		bool flag = false;
		for(int j = 0; j < hash_table[hashKey].size(); j++){
			if(hash_table[hashKey][j].first == key){
				cout << "value:: " << hash_table[hashKey][j].second << "\n";
				flag = true;
				break;
			}
		}
		if(!flag) cout << "해당 key값이 없습니다.\n";
	}
	return 0;
}
