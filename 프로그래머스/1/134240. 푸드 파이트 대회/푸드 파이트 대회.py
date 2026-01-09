def solution(food):
    s = ''
    
    for i, cnt in enumerate(food):
        if i == 0:
            pass
        s += str(i) * (cnt // 2)
    
    s += '0' + s[::-1]
    return s