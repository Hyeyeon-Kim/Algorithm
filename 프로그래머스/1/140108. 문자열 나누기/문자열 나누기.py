def solution(s):
    x_cnt = 0
    a_cnt = 0
    x = None
    ans = 0
    
    for i, c in enumerate(s):
        if x == None:
            x = c
            x_cnt += 1
        elif x == c:
            x_cnt += 1
        else:
            a_cnt += 1 
        
        # print(c, x_cnt, a_cnt, ans)
        
        if x_cnt == a_cnt:
            ans += 1
            x_cnt = 0
            x = None
            a_cnt = 0
        else:
            if i == len(s) - 1:
                ans += 1
        
    
    return ans