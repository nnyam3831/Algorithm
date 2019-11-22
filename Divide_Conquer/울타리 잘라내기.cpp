// ID : FENCE(algospot)
// �ð����⵵ : O(nlogn) 
#include <iostream>
#include <vector>

using namespace std;

int solve(int left, int right, vector<int> h){
	// ���� : ���� 1 
	if(left == right) return h[left];
	int mid = (left + right) / 2;
	
	// ���� ����  
	int ret = min(solve(left, mid, h), solve(mid+1, right, h));
	
	// �κй���
	int lo = mid, hi = mid + 1;
	int height = min(h[lo],h[hi]);
	
	ret = max(ret, height * 2);
	while(left < lo || hi < right){
		if(hi < right && (lo == right) || h[lo-1] < h[hi+1]){
			hi++;
			height = min(height, h[hi]);
		}else{
			lo--;
			height = min(height, h[lo]);
		}
		ret = max(ret, height *(hi-lo+1));
	}
	return ret;
}
int main(void){
	
	int Test;
	cin >> Test;
	for(int T = 0; T < Test; T++){
		int N;
		cin >> N;
		vector<int> v;
		for(int i = 0; i < N; i++){
			int x;
			cin >> x;
			v.push_back(x);
		}
		int ans = solve(0,N-1, v);
		cout << ans << "\n";
	}
	return 0;
}
