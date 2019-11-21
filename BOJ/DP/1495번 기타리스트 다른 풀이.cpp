#include <iostream>

#include <algorithm>

#include <cstring> //memset

using namespace std;

 

const int MAX = 100;

const int MAXV = 1000; //�ִ� ����

 

int N, S, M; //���� ��, ������ �� ����, �ִ� ����

int playlist[MAX + 1];

int cache[MAXV + 1][MAX + 1];

 

int maxVolume(int volume, int idx) //���� �Ҹ�, �뷡 ��ȣ

{

        //�������

        if (volume < 0 || volume > M)

               return -100; //�޸������̼� �Ǻ� ���� ���� ��� �ð� �ʰ�

        if (idx == N)

               return volume;

        int &result = cache[volume][idx];

        if (result != -1)

               return result;

        //max(playlist[idx+1]��ŭ ���� ���, playlist[idx+1]��ŭ �� ���)

        return result = max(maxVolume(volume + playlist[idx + 1], idx + 1), maxVolume(volume - playlist[idx + 1], idx + 1));

}

 

int main(void)

{

        cin >> N >> S >> M;

 

        for (int i = 1; i <= N; i++)

               cin >> playlist[i];

 

        memset(cache, -1, sizeof(cache));

        int result = maxVolume(S, 0);

        if (result == -100)

               cout << -1 << endl;

        else

               cout << result << endl;

        return 0;

}
