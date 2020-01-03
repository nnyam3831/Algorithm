struct RangeResult{
	int size;
	int mostFrequent;
	int leftNumber, leftFreq;
	int rightNumber, rightFreq;
};

// 왼쪽 부분의 계산 결과 a, 오른쪽 부분의 계산 결과 b를 합침 (숫자가 정렬되어있으므로 겹친다는 뜻이니까)

RangeResult merge(const RangeResult& a, const RangeResult& b){
	RangeResult ret;
	
	ret.size = a.size + b.size;
	// 왼쪽 숫자는 a.leftNumber
	// 왼쪽 부분 구간이 전부 a.leftNumber인 경우는 별도로 처리
	// ex) [1,1,1,1] [1,2,2,2]
	ret.leftNumber = a.leftNumber;
	ret.leftFreq = a.leftFreq;
	if(a.size == a.leftFreq && a.leftNumber == b.leftNumber)
		ret.leftFreq += b.leftFreq;
	// 오른쪽 끝 숫자도 비슷하게
	ret.rightNumber = b.rightNumber;
	ret.rightFreq = b.rightFreq;
	if(b.size == b.rightFreq && a.rightNumber == b.rightNumber)
		ret.rightFreq += a.rightFreq;
	// 기본적으로 가장 많이 출현하는 수의 빈도수는 둘 중 큰 쪽으로
	ret.mostFrequent = max(a.mostFrequent, b.mostFrequent);
	
	// 왼쪽 구간의 오른쪽 끝 숫자와 오른 구간의 왼쪽 끝 숫자가 합쳐지는 경우
	// 이 두 수를 합쳐서 mostFrequent보다 커지는지 확인
	if(a.rightNumber == b.leftNumber){
		ret.mostFrequent = max(ret.mostFrequent, a.rightFreq + b.leftFreq);
	} 
	return ret;
} 
