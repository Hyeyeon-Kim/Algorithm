import re

def solution(board, moves):
    board = [[bo[i] for i in range(len(bo)-1, -1, -1) if bo[i] != 0] for bo in list(zip(*board))]
    
    s = []
    ans = 0
    for move in moves:
        if board[move - 1]:
            n = board[move - 1].pop()
            
            if s and s[-1] == n:
                ans += 2
                s.pop()
            else:
                s.append(n)
    
    return ans