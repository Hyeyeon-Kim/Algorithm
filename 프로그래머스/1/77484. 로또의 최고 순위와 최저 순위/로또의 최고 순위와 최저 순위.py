def f(num):
    if 6 - num > 5:
        return 6
    return 6 - num + 1

def solution(lottos, win_nums):
    win_nums = set(win_nums)
    zero = lottos.count(0)
    cnt = 0 
    
    for num in lottos:
         if num in win_nums:
            cnt += 1
            
    return [f(cnt + zero), f(cnt)]