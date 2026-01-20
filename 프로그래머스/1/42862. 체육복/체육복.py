def solution(n, lost, reserve):
    ans = n - len(lost)
    reserve = set(reserve)
    lost = set(lost)
    
    both = lost & reserve
    lost -= both
    reserve -= both
    ans += len(both)
    # print(lost)
            
    for l in lost:
        if l - 1 in reserve:
            ans += 1 
            reserve.remove(l-1)
        elif l + 1 in reserve:
            ans += 1 
            reserve.remove(l+1)
    
    return ans