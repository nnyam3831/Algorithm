#include <iostream>

#include <algorithm>

#include <cstring> //memset

using namespace std;

 

const int MAX = 100;

const int MAXV = 1000; //최대 볼륨

 

int N, S, M; //곡의 수, 시작할 때 볼륨, 최대 볼륨

int playlist[MAX + 1];

int cache[MAXV + 1][MAX + 1];

 

int maxVolume(int volume, int idx) //현재 소리, 노래 번호

{

        //기저사례

        if (volume < 0 || volume > M)

               return -100; //메모이제이션 판별 수와 같을 경우 시간 초과

        if (idx == N)

               return volume;

        int &result = cache[volume][idx];

        if (result != -1)

               return result;

        //max(playlist[idx+1]만큼 더할 경우, playlist[idx+1]만큼 뺄 경우)

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
