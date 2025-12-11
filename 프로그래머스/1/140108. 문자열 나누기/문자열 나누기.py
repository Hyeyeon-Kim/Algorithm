def solution(s):
    
    ans = []
    
    l = 0
    r = 0
    
    for i, c in enumerate(s):
        x = 0
        nx = 0
        
        if r != 0 and i <= r:
            continue
        
        l = i
        for j in range(i, len(s)):
            if s[j] == c:
                x += 1
            else:
                nx += 1
            
            if x == nx:
                r = j
                break
            
            if (j == len(s) - 1):
                r = len(s) - 1
                break
        
        # print(s[l : r+1])
        
        ans.append(s[l : r+1])
            
        # print(l, r)
    
    return len(ans)