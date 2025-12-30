def solution(s):
    s = s.split(' ')
    
    ans = ''
    for j , t in enumerate(s):
        for i, tt in enumerate(t) :
            if i % 2 == 0:
                ans += tt.upper()
            else:
                ans += tt.lower()
        if j < len(s)-1:
            ans += ' '
    return ans