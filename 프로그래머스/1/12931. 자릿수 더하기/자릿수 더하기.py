def solution(n):
    n = str(n)
    
    ans = 0
    for t in n:
        ans += int(t)
    return sum(map(int, str(n)))