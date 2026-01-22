import re

def solution(babbling):
    ans = 0
    
    for bab in babbling:
        b = re.split("(aya)|(ye)|(woo)|(ma)", bab)
        token = list(filter(lambda x: x not in(None, ''), b))
        
        ok = True
        pre = ''
        for t in token:
            if pre == t or t not in ('aya','ye','woo','ma'):
                ok = False
                break
            pre = t
        
        if ok:
            ans += 1
    
    return ans