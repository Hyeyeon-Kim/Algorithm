def change(s):
    return int((s // 100 * 60) + (s % 100))

def solution(schedules, timelogs, startday):
    deadline = [change(s) + 10 for s in schedules]
    
    # print(deadline)
    ans = 0
    
    for i, tt in enumerate(timelogs):
        cnt = 0
        
        for j, t in enumerate(tt):
            day = (j + startday - 1) % 7 + 1
            if (day == 6 or day == 7):
                continue

            if deadline[i] >= change(t):
                cnt += 1 

        if (cnt == 5):
            ans += 1
            
    return ans