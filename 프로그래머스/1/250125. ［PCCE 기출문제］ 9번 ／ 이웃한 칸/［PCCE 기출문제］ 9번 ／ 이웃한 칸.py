def solution(board, h, w):
    n = len(board)

    nextx = [1,0,-1,0]
    nexty = [0,-1,0,1]

    cnt = 0
    for i in range(4):
        nx = nextx[i] + w
        ny = nexty[i] + h
        
        if nx < 0 or nx >= n or ny < 0 or ny >= n:
            continue
        
        if board[h][w] == board[ny][nx]:
            cnt += 1

    return cnt