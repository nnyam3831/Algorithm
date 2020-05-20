#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000 + 1
using namespace std;

// 입구를 따로 처리하는게 관건 
typedef struct edge
{
    int from, to, weight;
    edge(int from, int to, int weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
} edge;

int parent[MAX];

int find(int num)
{
    if (parent[num] == num)
        return num;
    return parent[num] = find(parent[num]);
}

void Union(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if (pa > pb)
        parent[pa] = pb;
    else
    {
        parent[pb] = pa;
    }
}
bool cmp1(const edge &a, const edge &b)
{
    // 내리막 기준
    
    return a.weight > b.weight;
}
bool cmp2(const edge &a, const edge &b)
{
    // 오르막 기준
    
    return a.weight < b.weight;
}
int main(void)
{
    int N, M;
    cin >> N >> M;
    vector<edge> v;

	int a,b,c;
	int temp = 0;
//	cin >> a >> b >> c;
//	if(c == 1) temp = 0;
//	else temp = 1;
    for (int i = 0; i < M+1; i++)
    {
        cin >> a >> b >> c;
        v.push_back(edge(a, b, c));
    }

    int max_cost = temp;
    int min_cost = temp;
    sort(v.begin(), v.end(), cmp1);

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < v.size(); i++)
    {	
        int from = v[i].from;
        int to = v[i].to;
        if (find(from) != find(to))
        {
        	
            Union(from, to);
            int weight = v[i].weight;
            if (weight == 0)
            {
                min_cost++;
            }
        }
    }

    sort(v.begin(), v.end(), cmp2);

    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < v.size(); i++)
    {
        int from = v[i].from;
        int to = v[i].to;
        if (find(from) != find(to))
        {
            Union(from, to);
            int weight = v[i].weight;
            if (weight == 0)
            {
                max_cost++;
            }
        }
    }
    
    cout << max_cost*max_cost - min_cost*min_cost << "\n";

    return 0;
}
