def solution(t, p):
    plen = len(p)
    p = int(p)

    answer = 0
    for i in range(0, (len(t) - plen) + 1):
        num = int(t[i:i + plen])
        
        if num <= p:
            answer += 1
    
    

    return answer