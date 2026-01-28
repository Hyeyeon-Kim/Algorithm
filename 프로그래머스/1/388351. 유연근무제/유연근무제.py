def change(time):
    h = time // 100
    m = time % 100
    return h * 60 + m

def solution(schedules, timelogs, startday):
    schedules = [change(s) + 10 for s in schedules]
    ans = 0
    
    for i, logs in enumerate(timelogs):
        ok = True
        
        for j, log in enumerate(logs):
            day = (startday + j - 1) % 7
            if day >= 5:
                continue
            
            if change(log) > schedules[i]:
                ok = False
                break
        
        if ok:
            ans += 1
            
    return ans