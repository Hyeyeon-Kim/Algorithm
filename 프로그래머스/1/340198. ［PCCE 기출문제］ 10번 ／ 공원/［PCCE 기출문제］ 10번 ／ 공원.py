def solution(mats, park):
    n, m = len(park), len(park[0])
    state = [[0] * (m + 1) for i in range(n+1)]
    
    for i in range(1, n+1):
        for j in range(1, m+1):
            if park[i - 1][j - 1] != '-1':
                continue
            state[i][j] = min(state[i-1][j], state[i][j-1], state[i-1][j-1]) + 1        
    
    max_ = 0
    for s in state:
        if max(s) > max_:
            max_ = max(s)
        
    mats = sorted(mats, reverse = True)
    
    for m in mats:
        if m <= max_:
            return m
        
    return -1