from collections import deque

def solution(board, moves):
    board = [deque(x for x in col if x != 0) for col in zip(*board) ]
    ans = 0 
    
    basket = deque()
    for m in moves:
        if board[m-1]:
            now = board[m-1].popleft()
            
            if basket and basket[-1] == now:
                basket.pop();
                ans += 2
            else:
                basket.append(now)
            
    return ans