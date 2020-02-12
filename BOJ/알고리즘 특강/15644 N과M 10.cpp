#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#define MAX 9
using namespace std;

vector<string> buffer;
int N, M;
string input[MAX];
bool check[MAX];
vector<vector<int>> result;
map<string, int> m;
// 출력까지 해결

bool isChecked(vector<vector<int>> &A, vector<int> &B){
	// A안에 B가 있나 ?? 
	if(A.size() == 0) return false;
	
	for(int i = 0; i < A.size(); i++){
		sort(A[i].begin(), A[i].end());
		sort(B.begin(), B.end());
		bool flag = true;
		for(int j = 0; j < M; j++){
			if(A[i][j] != B[j]){
				flag = false;
			}
		}
		if(flag) return flag;
	}
	return false;
}
void DFS() {
	if (buffer.size() == M) {
		string temp = "";
		vector<int> v;
		for (int i = 0; i < M; i++) {
			temp += buffer[i];
			temp += ".";
			v.push_back(atoi(buffer[i].c_str()));
		}
		if (m[temp] == 0) {
			m[temp]++;
			if(!isChecked(result, v)) result.push_back(v);
		}
	}
	for (int i = 0; i < N; i++) {
		// N개의 input에 대한 순열
		if (check[i] == 0) {	
			buffer.push_back(input[i]);
			check[i] = 1;
			DFS();
			check[i] = 0;
			buffer.pop_back();
		}
	}
}
int main(void) {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	DFS();
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
