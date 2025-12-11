def solution(s):
    cnt = 0
    i = 0
    n = len(s)
    
    while i < n:
        x = 0
        nx = 0
        base = s[i]

        j = i
        while j < n:
            if s[j] == base:
                x += 1
            else:
                nx += 1
            if x == nx:
                break    
            j += 1
            
        cnt += 1
        i = j + 1
            
        print(s[i : j])
        
        # ans.append(s[l : r+1])
            
        # print(l, r)
    
    return cnt