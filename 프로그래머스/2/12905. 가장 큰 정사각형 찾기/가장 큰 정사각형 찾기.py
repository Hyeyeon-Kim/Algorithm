def solution(board):
    n, m = len(board) + 1, len(board[0]) + 1
    dp = [[0] * m for _ in range(n)]
    
    # print(dp)
    
    for i in range(1, n):
        for j in range(1, m):
            if board[i-1][j-1] == 1:
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + board[i-1][j-1]
    
    ans = 0
    for n in dp:
        ans = max(ans, max(n))
    
    return ans ** 2

# 1 1 1 1
# 1 0 1 1 
# 1 0 1 1 
# 0 0 1 0