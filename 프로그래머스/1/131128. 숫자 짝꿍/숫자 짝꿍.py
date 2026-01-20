def solution(X, Y):
    Xcnt = {}
    Ycnt = {}
    
    for x in X:
        Xcnt[int(x)] = Xcnt.get(int(x), 0) + 1
    for y in Y:
        Ycnt[int(y)] = Ycnt.get(int(y), 0) + 1
    
    ans = ''
    for i in range(9, -1, -1):
        cnt = min(Xcnt.get(i, 0), Ycnt.get(i, 0))
        if ans == '' and i == 0 and cnt > 1:
            cnt = 1
        ans += str(i) * cnt
    
    if ans == '':
        ans = '-1'
    return ans