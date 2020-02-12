#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 500+1
#define INF 987654321
using namespace std;

typedef pair<int,int> pii;
vector<pii> city[MAX];
int dist[MAX];
int N, M;
int main(void){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int a, b, c;
		cin >> a >> b >> c;
		city[a].push_back(make_pair(b, c));
	}
	
	for(int i = 1; i <= N; i++){
		dist[i] = INF;
	}
	dist[1] = 0;
	// ��������ó�� ���̴� ��������  
	bool flag = false;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			for(int k = 0; k < city[j].size(); k++){
				int next = city[j][k].first;
				int weight = city[j][k].second;
				// update
				if(dist[next] > dist[j] + weight && dist[j] != INF){
					// weight�� ������ �� �����Ƿ� INF�� ������ �� �� ����
					// INF�� �ƿ� ������ �ȵ� ���̱� ������ ���� ��ü�� ���ؾ� ��  
					dist[next] = dist[j] + weight;
					if(i == N){
						// ���� ����Ŭ  
						flag = true;
						break;
					}
				}
			}
		}
	}
	if(flag) cout << -1 << "\n";
	else{
		for(int i = 2; i <= N; i++){
			dist[i] == INF ? cout << "-1\n" : cout << dist[i] << "\n";
		}
	}
	return 0;
}
