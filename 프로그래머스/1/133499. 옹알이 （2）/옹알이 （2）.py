def solution(babbling):
    ans = 0
    for b in babbling:
        ok = True
        pre = ''
        
        while (b):
            two = b[:2]
            the = b[:3]
            
            if two in ["ye", "ma"] and two != pre:
                pre = two
                b = b[2:]
            elif the in ["aya", "woo"] and the != pre:
                pre = the
                b = b[3:]
            else:
                ok = False
                break

        if ok:
            ans += 1
    
    return ans