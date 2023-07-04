def find(n, dp):
    if n == 0 or n == 1:
        return n
    if dp[n] != -1:
        return dp[n]
    dp[n] = find(n-1, dp) + find(n-2, dp)
    return dp[n]


# 0 1 1 2 3 5...
n = int(input())
dp = [-1 for i in range(n+1)]
find(n, dp)
print(dp[n])