def solution(n, m, section):
    ans = 1
    s = section[0]
    
    for num in section:
        if s <= num < s + m:
            continue
        s = num
        ans += 1
        
    return ans 