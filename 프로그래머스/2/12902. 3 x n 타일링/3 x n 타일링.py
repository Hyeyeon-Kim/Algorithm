def solution(n):
    dp = [0] * (n + 1)
    dp[0] = 1
    dp[2] = 3

    acc = 1
    
    for i in range(4, n + 1):
        if i % 2 == 0:
            dp[i] = (dp[i - 2] * 3 + acc * 2)% 1000000007
            acc = (acc + dp[i - 2]) % 1000000007
    return dp[n]