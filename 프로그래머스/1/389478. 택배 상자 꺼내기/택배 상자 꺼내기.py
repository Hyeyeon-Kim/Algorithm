def change(n, y, w):
    x = (n - 1) % w
    
    if y % 2 == 1:
        x = w - ((n - 1) % w) - 1
    
    return x
    
def solution(n, w, num):
    topy = (n - 1) // w
    y = (num - 1) // w
    topx = change(n, topy, w)
    x = change(num, y, w)

    ans = topy - y
    
    if topy % 2 == 0:
        if x <= topx:
            ans += 1
    else: 
        if x >= topx:
            ans += 1
    return ans