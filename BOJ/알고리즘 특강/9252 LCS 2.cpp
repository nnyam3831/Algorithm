#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#define MAX 1000+1
using namespace std;

int Dp[MAX][MAX];
int main(void){
	
	
	ifstream readFile;
	string temp[3];
	readFile.open("sample.txt");
	int index = 0;
	if(readFile.is_open()){
		while(!readFile.eof()){
			getline(readFile, temp[index]);
			index++;
		}
	}
	cin >> temp[0] >> temp[1];
	
	for(int i = 0; i < A.length(); i++){
		for(int j = 0; j < B.length(); j++){
			if(A[i] == B[j]) Dp[i][j] = 1;
		}
	}
	for(int i = 0; i < A.length(); i++){
		for(int j = 0; j < B.length(); j++){
			if(i == 0 && j == 0) continue;
			if(A[i] == B[j]){
				if(i == 0 && j != 0){
					Dp[i][j] = 1;
				}else if(i != 0 && j == 0){
					Dp[i][j] = 1;
				}else{
					Dp[i][j] = min(Dp[i-1][j] ,Dp[i][j-1]) + 1;
				}
			}else{
				if(i == 0 && j != 0){
					Dp[i][j] = Dp[i][j-1];
				}else if(i != 0 && j == 0){
					Dp[i][j] = Dp[i-1][j];
				}else{
					Dp[i][j] = max(Dp[i][j-1], Dp[i-1][j]);
				}
				
			}
		}
	}
	cout << Dp[A.length()-1][B.length()-1] << "\n";
	int i = A.length()-1;
	int j = B.length()-1;
	for(int y = 0; y <= i; y++){
		for(int x = 0; x <= j; x++){
			cout << Dp[y][x] << " ";
		}
		cout << "\n";
	}
	vector<int> result;
	
	cout << "\n";
	for(int k = result.size()-1; k >= 0; k--){
		cout << result[k];
	}
	return 0;
}
