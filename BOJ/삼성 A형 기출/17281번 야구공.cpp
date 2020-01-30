//N(2 �� N �� 50)
//�� �̴׿� �ִ� 27��
//��ġ��� 8! = 4�� (4��Ÿ�� ����)
//4�� * 1500 = 6000��
//brute force
//8!�� �ڸ� ��ġ�� ���ϰ�(vector)
//�� �ڸ���ġ��� 1�̴� ~ N�̴ױ��� �ùķ��̼� => MAX ����
//Simulation)
//Queue , outCount, Score
//0.9�ʷ� ���

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#define MAX 51
using namespace std;

int N,result;
int Array[10];
int data[MAX][10];
int batter[10];
vector<int> v;

void simulation(){
	// vector v ��� Ÿ�ڼ���
	int score = 0;
	int start = 1;
	for(int i = 1; i <= N; i++){
		batter[4] = data[i][1];
		for(int x = 0; x < v.size(); x++){
			batter[v[x]] = data[i][x+2];
		}
		// �ϼ��� batter�迭�� ���ؼ� 1��~9�� Ÿ�ڱ��� �� �̴��� ������
		int outCount = 0;
		int index = start;
		queue<int> q;
		while(outCount <= 2){
			if(index > 9) index = 1;
			if(batter[index] == 0){
				outCount++;
				index++;
				continue;
			}else if(batter[index] == 1){
				q.push(1);
			}else if(batter[index] == 2){
				q.push(1);
				q.push(0);
			}else if(batter[index] == 3){
				q.push(1);
				q.push(0);
				q.push(0);
			}else if(batter[index] == 4){
				q.push(1);
				q.push(0);
				q.push(0);
				q.push(0);
			}
			if(q.size() > 3){
				while(q.size() > 3){
					int k = q.front();
					if(k == 1) score++;
					q.pop();
				}
			}
			index++;
		}
		start = index;
	}
	result = max(result, score);
}

void DFS(int index){
	if(index == 8){
		simulation();
		return;
	}
	for(int x = 1; x <= 8; x++){
		if(Array[x] == 0){
			Array[x] = 1;
			index++;
			if(x >= 4){
				v.push_back(x+1);
			}else{
				v.push_back(x);
			}
			DFS(index);
			Array[x] = 0;
			v.pop_back();
			index--;
		}
	}
}
int main(void){
	
	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= 9; j++){
			cin >> data[i][j];
		}
	}
	int size = 0;
	DFS(0);
	cout << result << "\n";
	return 0;
}
