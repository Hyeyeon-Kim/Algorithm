def solution(n, lost, reserve):
    ans = n - len(lost)
    
    slost = set(lost)
    reserve = set(reserve)
    
    for l in lost:
        if l in reserve:
            slost.remove(l)
            reserve.remove(l)
            ans += 1

    lost = slost
    
    for l in lost:
        if l - 1 in reserve:
            ans += 1
            reserve.remove(l - 1)
        elif l + 1 in reserve:
            ans += 1
            reserve.remove(l+1)
    
    return ans