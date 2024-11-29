
def solution(n, times):
    answer = 0
    
    s = 0
    e = max(times) * n
    
    while s <= e:
        mid = (s + e) // 2
        cnt = 0
        for time in times:
            cnt += mid // time
        
        if cnt >= n:
            answer = mid
            e = mid - 1
        else :
            s = mid + 1
            
    return answer

