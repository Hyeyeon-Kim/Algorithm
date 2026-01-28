def solution(N, stages):
    state = {i: 0.0 for i in range(1, N + 1)}
    cnt = len(stages)
    
    for s in stages:
        if s <= N:
            state[s] += 1
    
    for i, s in enumerate(state, start=1):
        if state[i] == 0 or cnt == 0:
            continue
        fail = state[i] / cnt  
        cnt -= state[i]
        state[i] = fail
        
    return sorted(state, key = lambda x:state[x], reverse=True)