def solution(babbling):
    ans = 0
    
    for bab in babbling:
        pre = ''
        ok = True    
        
        while(bab):
            s2 = bab[:2]
            s3 = bab[:3]
            
            if pre == s2 or pre == s3:
                ok = False
                break
            
            if s2 == 'ye' or s2 == 'ma': 
                pre = s2
                bab = bab[2:]
            elif s3 == 'aya' or s3 == 'woo':
                pre = s3
                bab = bab[3:]
            else:
                ok = False
                break
        if ok:
            ans += 1
    return ans