#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
 
typedef pair<int, int> p;
p ramen[200000];
priority_queue<int> pq;
int n, i, m, cnt, dl, sum;
 
int main() {
    scanf("%d", &n);
    for (i = 0; i < n; ++i)
        scanf("%d %d", &ramen[i].first, &ramen[i].second);
    sort(ramen, ramen + n);
    for (i = 0; i < n; ++i) {
        dl = ramen[i].first;
        pq.push(-ramen[i].second);
 
        while (dl < pq.size())
            pq.pop();
    }
    while (!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    printf("%d", -sum);
    return 0;
}

