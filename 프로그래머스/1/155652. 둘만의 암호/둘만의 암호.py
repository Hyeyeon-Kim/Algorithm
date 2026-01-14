def solution(s, skip, index):
    
    alpa = [chr(c) for c in range(ord('a'), ord('z') + 1) if chr(c) not in skip]
    
    ans = ''
    
    for c in s:
        idx = (alpa.index(c) + index) % len(alpa)
        ans += alpa[idx] 

    
    return ans