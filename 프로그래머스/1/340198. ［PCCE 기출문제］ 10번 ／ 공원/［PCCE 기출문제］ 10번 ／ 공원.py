from itertools import groupby

def solution(mats, park):
    
    n, m = len(park), len(park[0])
    
    dp = [[0] * m for _ in range(n)]
    max_len = 0
    
    for i in range(n):
        for j in range(m):
             if park[i][j] == '-1':
                if i == 0 and j == 0:
                    dp[i][j] = 1
                else:
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                max_len = max(max_len, dp[i][j]) 
    
    mats.sort(reverse=True)
    
    for x in mats:
        if x <= max_len:
            return x
                
    return -1