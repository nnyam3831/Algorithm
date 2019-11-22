/*
두 개의 정수 곱셈
ex) 256자리 a, b라면
a x b = (a1x10^128 + a0) X (b1x10^128 + b0)
정리하면 한 번의 곱셈을 세 번의 곱셈으로 나눌 수 있음 
시간복잡도 O(n^log3) 
*/

// a += b(10^k)
void addTo(vector<int>& a, const vector<int>& b, int k);
// a -= b
void subFrom(vector<int>& a, const vector<int>& b);

vector<int> karatsuba(const vector<int> &a, const vector<int>& b){
	int an = a.size(), bn = b.size();
	// 큰 수가 앞으로 
	if(an < bn) return karatsuba(b, a);
	// 기저 : a나 b가 비어있는 경우 
	if(an == 0 || bn == 0) return vector<int> ();
	// 기저 : a가 비교적 짧은 경우 o(n^2)으로 변경
	if(an <= 50) return multiply(a,b);
	int half = an/2;
	
	// a와 b를 밑에서 half 자리와 나머지로 분리
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());
	
	// z2 = a1*b1
	vector<int> z2 = karatsuba(a1, b1); 
	// z0 = a0 * b0
	vector<int> z0 = karatsuba(a0, b0);
	//a0 = a0+a1, b0 = b0+b1
	addTo(a0,a1,0); addTo(b0,b1,0);
	// z1 = (a0*b0) - z0 - z2
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);
	
	// ret = z0 + z1*10^half + z2*10^(half*2)
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}
