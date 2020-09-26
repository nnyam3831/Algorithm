import sys

n, m = map(int, input().split())
memory = list(map(int, input().split()))
cost = list(map(int, input().split()))

def solution(n, m, memory, cost):
    # total_cost만큼 사용했을때 확보할 수 있는 최대 메모리
    max_cost = 10001
    dp = [0 for _ in range(max_cost)]
    sum = 0
    for c in cost:
        sum += c

    for i in range(n):
        for j in range(sum, cost[i] - 1, -1):
            dp[j] = max(dp[j], dp[j-cost[i]] + memory[i])

    for i in range(sum):
        if dp[i] >= m:
            return i

print(solution(n, m, memory, cost))