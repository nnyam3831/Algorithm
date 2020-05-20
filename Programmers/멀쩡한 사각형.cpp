#include <iostream>
#include <math.h>

using namespace std;

int calc(double a, double b)
{
    double ret = a * b;
    if (ret - floor(ret) > 0)
        return (int)ceil(ret);
    return (int)ret;
}
long long solution(int w, int h)
{
    long long answer = 1;
    double gradient = (double)h / (double)w;

    long long sum = 0;
    for (int i = 1; i <= w; i++)
    {
        sum = sum + h - calc(gradient, (double)i);
    }

    answer = sum * 2;
    return answer;
}

int main(void)
{

    cout << solution(8, 12);
    return 0;
}