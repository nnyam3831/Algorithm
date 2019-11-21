#include <iostream>

#include <cstring> //memset

using namespace std;

 

const long long MOD = 1000000007;

const int MAX = 100 + 1; //1<=N<=100

 

int N, L, R;

long long cache[MAX][MAX][MAX];

 

long long numOfWays(int buildingNum, int left, int right)

{

        //���� ���: ��������, ��������

        if ((left == 1 && right == buildingNum) || (left == buildingNum && right == 1))

                 return 1;

        //�Ұ����� ���

        if (buildingNum == 0 || left == 0 || right == 0)

                 return 0;

 

        long long &result = cache[buildingNum][left][right];

        if (result != -1)

                 return result;

 

        result = 0;

        //1. ������ ������ ������ ���� �߰��ϸ� �״��

        //2. N-1 ���̸� ���� �ǹ��� ������ �߰��ϸ� �������� ���̴� �ǹ� ����

        //3. N-1 ���̸� ���� �ǹ��� ������ �߰��ϸ� �������� ���̴� �ǹ� ����

        result = ((numOfWays(buildingNum - 1, left, right) * (buildingNum - 2)) + numOfWays(buildingNum - 1, left - 1, right) + numOfWays(buildingNum - 1, left, right - 1)) % MOD;

 

        return result;

}

 

int main(void)

{

        cin >> N >> L >> R;

       

        memset(cache, -1, sizeof(cache));

 

        cout << numOfWays(N, L, R) % MOD << endl;

 

        return 0;

}
