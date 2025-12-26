def solution(x):
    
    sum = 0
    for n in str(x):
        sum += int(n)
    
    return x % sum == 0