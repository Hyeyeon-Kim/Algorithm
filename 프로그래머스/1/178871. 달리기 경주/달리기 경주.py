def solution(players, callings):
    state = {p:i for i, p in enumerate(players)}
    idxs = {i:p for i, p in enumerate(players)}
    
    # print(state.values(0))
    
    for call in callings:
        idx = state[call]
        
        cidx = idx - 1
        c = idxs[cidx]
        
        state[call] = cidx 
        state[c] = idx
        idxs[idx] = c
        idxs[cidx] = call
    
    # print(state)
    return sorted(state, key = lambda k: state[k])
