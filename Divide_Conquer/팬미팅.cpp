// 남자들끼리 포옹하는일이 없게 ! 남자: 1, 여자: 0 => 남자X남자만 1이 나오므로 이 때만 피하자
// id : fanmeeting

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> VEC;
 
VEC multi(VEC& A, VEC& B)
{
    int s1 = A.size();
    int s2 = B.size();
 
    VEC res;  
    res.resize(s1 + s2 - 1, 0);
 
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            res[i + j] += A[i] * B[j];
        }
    }
    return res;
}
 
void add(vector<int>& vec1, vector<int>& vec2, int k)
{    
    int s = max(vec2.size() + k, vec1.size());
 
    vec1.resize(s, 0);
    vec2.resize(s, 0);
 
    for (int i = 0; i < s - k; i++)
    {
        vec1[i + k] += vec2[i];
    }
    
}
 
void sub(vector<int>& vec1, vector<int>& vec2)
{
    int s = max(vec1.size(),vec2.size());
 
    vec1.resize(s, 0);
    vec2.resize(s, 0);
 
    for (int i = 0; i < s; i++) vec1[i] -= vec2[i];
}
 
VEC Karatsuba(VEC& A, VEC& B)
{
    if (A.size() < 50)
    {
        VEC res;
        res = multi(A,B);
        return res;
    }
 
    int half = A.size() / 2;
    
    if (A.empty() || B.empty()) return VEC();
 
    VEC a1 = VEC(A.begin(), A.begin() + half);
    VEC a0 = VEC(A.begin() + half, A.end());
    VEC b1 = VEC(B.begin(), B.begin() + min<unsigned long>(half, B.size()));
    VEC b0 = VEC(B.begin() + min<unsigned long>(half, B.size()), B.end());
 
    VEC z0, z1, z2;
    
    z0 = Karatsuba(a0, b0);
    z2 = Karatsuba(a1, b1);
    
    add(a0, a1, 0);
    add(b0, b1, 0);
 
    z1 = Karatsuba(a0, b0);
    sub(z1, z0);
    sub(z1, z2);
 
    VEC res;
    add(res, z2, 0);
    add(res, z1, half);
    add(res, z0, half + half);
 
    return res;
}

int hugs(const string& members, const string& fans){
	int N = members.size(), M = fans.size();
	vector<int> A(N),B(M);
	for(int i = 0; i < N; i++) A[i] = (members[i] == 'M');
	for(int i = 0; i < M; i++) B[i] = (fans[i] == 'M');
	vector<int> C = Karatsuba(A, B);
	int allHugs = 0;
	for(int i = N-1; i < M; i++){
		if(C[i] == 0)
			allHugs++;
	}
	return allHugs;
}
int main(void){
	
	int Test;
	cin >> Test;
	for(int T = 0; T < Test; T++){
		string members, fans;
		cin >> members >> fans;
		int ans = hugs(members, fans);
		cout << ans << "\n";
	}
	return 0;
} 
