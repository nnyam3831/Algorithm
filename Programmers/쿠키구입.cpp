#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int sum[2001];
int solution(vector<int> cookie) {

    int answer = 0;
    for(int i = 0; i < cookie.size(); i++){
        sum[i+1] = sum[i] + cookie[i];
    }
    for(int a = 1; a < cookie.size(); a++){
        int temp1 = sum[a];
        for(int b = a+1; b <= cookie.size(); b++){
            int temp2 = sum[b] - temp1;
            if(answer >= temp2 || temp2 > temp1) continue;
            for(int c = 0; c < a; c++){
                if(temp2 == temp1-sum[c]){
                    answer = max(answer, temp2);
                    break;
                }
            }
        }
    }
    
    
    
    return answer;
}
