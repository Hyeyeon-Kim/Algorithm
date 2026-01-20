def solution(N, stages):
    cnt = [0] * (N + 1)
    
    for s in stages:
        cnt[s-1] += 1
    
    state = {n+1: (cnt[n] / sum(cnt[n:N+1]) if sum(cnt[n:N+1]) > 0 else 0) for n in range(N)}

    return sorted(state, key = lambda x:state[x], reverse = True)