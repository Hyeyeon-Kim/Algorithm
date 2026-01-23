def change(day):
    y, m, d = list(map(int,day.split('.')))
    
    return y * 28 * 12 + m * 28 + d

def rev(day):
    y = day // (28 * 12)
    t = day % (28 * 12)
    m = t // 28
    d = t % 28
    
    return str(y) + '.' + str(m).zfill(2) + '.' + str(d).zfill(2)

def solution(today, terms, privacies):
    today = change(today)
    
    t = {}
    
    for term in terms:
        a, b = term.split(' ')
        t[a] = int(b) * 28
        
        
    ans = []
    for i, p in enumerate(privacies, start = 1):
        d, ty = p.split(' ')
        d = change(d)
        
        # print(rev(today), rev(d))
        if (d + t[ty] <= today):
            ans.append(i)
    
    return ans