/*
�� ���� ���� ����
ex) 256�ڸ� a, b���
a x b = (a1x10^128 + a0) X (b1x10^128 + b0)
�����ϸ� �� ���� ������ �� ���� �������� ���� �� ���� 
�ð����⵵ O(n^log3) 
*/

// a += b(10^k)
void addTo(vector<int>& a, const vector<int>& b, int k);
// a -= b
void subFrom(vector<int>& a, const vector<int>& b);

vector<int> karatsuba(const vector<int> &a, const vector<int>& b){
	int an = a.size(), bn = b.size();
	// ū ���� ������ 
	if(an < bn) return karatsuba(b, a);
	// ���� : a�� b�� ����ִ� ��� 
	if(an == 0 || bn == 0) return vector<int> ();
	// ���� : a�� ���� ª�� ��� o(n^2)���� ����
	if(an <= 50) return multiply(a,b);
	int half = an/2;
	
	// a�� b�� �ؿ��� half �ڸ��� �������� �и�
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
