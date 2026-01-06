def solution(friends, gifts):
    state = {}
    give = {}
    take = {}
    result = {}
    
    for friend in friends:
        state[friend] = {f: 0 for f in friends}
        give[friend] = 0
        take[friend] = 0
        result[friend] = 0
        
    for gift in gifts:
        g, t = gift.split(' ')
        state[g][t] += 1
        give[g] += 1
        take[t] += 1
        
    
    for friend in friends:
        cnt = 0
        for author in friends:
            if friend == author:
                continue
            
            if state[friend][author] > state[author][friend]:
                cnt += 1
            elif state[friend][author] == state[author][friend] and give[friend] - take[friend] > give[author] - take[author]:
                cnt += 1
        
        result[friend] = cnt
    
    return max(result.values())