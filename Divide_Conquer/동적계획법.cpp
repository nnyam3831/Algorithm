/*
�׻� ���� ��ʸ� ���� ���� ó���ؾ��Ѵ�.  
*/

int cache[2500][2500];

int someObscureFunction(int a, int b){
	
	// ���� ��ʸ� ó���� ó��
	if(...) return ...;
	// (a,b) ���� ���� ������ �ٷ� ��ȯ
	int& ret = cache[a][b];
	if(ret != -1) return ret;
	...
	
	return ret; 
}
