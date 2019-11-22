#include <iostream>

using namespace std;

// A^m = A^(m/2) * A^(m/2)

class SquareMatrix;

SquareMatrix identity(int n);

SquareMatrix pow(const SquareMatrix& A, int m){
	// ±âÀú A^0 = I
	if(m == 0) return identity(A.size());
	// È¦¼ö 
	if(m % 2 > 0 ) return pow(A,m-1) * A;
	SquareMatrix half = pow(A, m/2);
	return half * half; 
}
