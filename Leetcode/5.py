def sol(s):
    if len(s) == 1:
        return s
    ret = ""
    Dp = [[False for col in range(1001)]for row in range(1001)]
    maxLength = 0

    # for i in range(len(s)-1, -1, -1):
    #     print(i)
    #     for j in range(i, len(s)):
    #         Dp[i][j] = ((s[i] == s[j]) and (j-i <= 2 or Dp[i+1][j-1]))
    #         if(Dp[i][j] and j-i >= maxLength):
    #             maxLength = j-i
    #             ret = s[i:j+1]

    for j in range(0, len(s)):
        for i in range(0, j+1):
            Dp[i][j] = ((s[i] == s[j]) and (j-i <= 2 or Dp[i+1][j-1]))
            if Dp[i][j] and j-i >= maxLength:
                maxLength = j-i
                ret = s[i:j+1]

    return ret


# print(sol("babad"))
# print(sol("cbbd"))
# print(sol("s"))
# print(sol("ccc"))
print(sol("dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"))
