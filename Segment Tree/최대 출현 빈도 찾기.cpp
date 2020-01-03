struct RangeResult{
	int size;
	int mostFrequent;
	int leftNumber, leftFreq;
	int rightNumber, rightFreq;
};

// ���� �κ��� ��� ��� a, ������ �κ��� ��� ��� b�� ��ħ (���ڰ� ���ĵǾ������Ƿ� ��ģ�ٴ� ���̴ϱ�)

RangeResult merge(const RangeResult& a, const RangeResult& b){
	RangeResult ret;
	
	ret.size = a.size + b.size;
	// ���� ���ڴ� a.leftNumber
	// ���� �κ� ������ ���� a.leftNumber�� ���� ������ ó��
	// ex) [1,1,1,1] [1,2,2,2]
	ret.leftNumber = a.leftNumber;
	ret.leftFreq = a.leftFreq;
	if(a.size == a.leftFreq && a.leftNumber == b.leftNumber)
		ret.leftFreq += b.leftFreq;
	// ������ �� ���ڵ� ����ϰ�
	ret.rightNumber = b.rightNumber;
	ret.rightFreq = b.rightFreq;
	if(b.size == b.rightFreq && a.rightNumber == b.rightNumber)
		ret.rightFreq += a.rightFreq;
	// �⺻������ ���� ���� �����ϴ� ���� �󵵼��� �� �� ū ������
	ret.mostFrequent = max(a.mostFrequent, b.mostFrequent);
	
	// ���� ������ ������ �� ���ڿ� ���� ������ ���� �� ���ڰ� �������� ���
	// �� �� ���� ���ļ� mostFrequent���� Ŀ������ Ȯ��
	if(a.rightNumber == b.leftNumber){
		ret.mostFrequent = max(ret.mostFrequent, a.rightFreq + b.leftFreq);
	} 
	return ret;
} 
