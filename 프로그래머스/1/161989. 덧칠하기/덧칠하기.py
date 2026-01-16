def solution(n, m, section):
    ans = 1
    pre = section[0]
    
    for sec in section:
        if sec - pre >= m:
            ans += 1
            pre = sec
            
    return ans