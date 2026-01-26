def solution(friends, gifts):
    
    state = {f: {ff: 0 for ff in friends if ff != f} for f in friends}
    score = {f: 0 for f in friends}
    
    for gift in gifts:
        g, t = gift.split(' ')
        
        state[g][t] += 1
        score[g] += 1
        score[t] -= 1
    
    next_ = []
    
    for g in friends:
        cnt = 0
        
        for t in state[g]:
            if state[g][t] > state[t][g]:
                cnt += 1
            elif state[g][t] == state[t][g] and score[g] > score[t]:
                cnt += 1
                
        next_.append(cnt)

    return max(next_)