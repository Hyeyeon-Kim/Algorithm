def solution(friends, gifts):
    
    log = {}
    give = {}
    take = {}
    next = {}
    
    for fri in friends:
        give[fri] = 0
        take[fri] = 0
        next[fri] = 0
        log[fri] = {}
        for fr in friends:
            log[fri][fr] = 0
        
 
    # print(log)

    for gift in gifts:
        to, fro = gift.split(' ')
        log[to][fro] += 1
        give[to] += 1
        take[fro] += 1
    

    
    
    for fri in friends:
        for fr in friends:
            if fri == fr:
                continue
            
            if log[fri][fr] > log[fr][fri]:
                next[fri] += 1
            elif log[fri][fr] == log[fr][fri]:
                if give[fri]-take[fri] > give[fr]-take[fr]:
                    next[fri] += 1
    

    return next[max(next, key = next.get)]