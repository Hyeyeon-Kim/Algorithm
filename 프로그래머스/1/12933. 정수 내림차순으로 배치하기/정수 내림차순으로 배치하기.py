def solution(n):
    n = sorted(str(n), reverse= True)

    ans = ""
    for t in n:
        ans += t
    return int(ans)