def solution(n):
    dp = [[0, 0, 0] for _ in range(n + 1)]
    mod = 1000000007
    dp[1][1] = 1
    dp[1][2] = 0
    
    dp[2][1] = 1
    dp[2][2] = 1
               
    for i in range(3, n + 1):
        dp[i][1] = (dp[i-1][1] + dp[i-1][2]) % mod
        dp[i][2] = (dp[i-2][1] + dp[i-2][2]) % mod

    return (dp[n][1] + dp[n][2]) % mod