def solution(n):
    n = sorted(str(n), reverse= True)

    ans = ''.join(n)
    return int(ans)