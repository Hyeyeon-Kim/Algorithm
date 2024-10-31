def solution(today, terms, privacies):
    
    term = {}
    
    for t in terms:
        kind, m = t.split(' ')
        term[kind] = m
    
    ty, tm, td = map(int, today.split('.'))
    
    answer = []
    i = 0
    for p in privacies :
        i += 1
        date, typ = p.split(' ')
        year, mon, day = map(int, date.split('.'))
        
        plus = int(term[typ])
    
        if (mon + plus > 12):
            year += (mon+plus) // 12
            if (mon+plus) % 12 == 0:
                year -= 1
                m = 12
            else:
                m = (mon+plus) % 12
        else :
            m = mon + plus
        
        print(year, m, day)
        
        if day - 1 <= 0 :
            day = 28
            if m - 1 <= 0:
                year -= 1
                m = 12
            else :
                m -= 1
        else:
            day -= 1
        
        print(year, m, day)
        
        if year == ty:
            if m < tm:
                answer.append(i)
            elif m == tm:
                if day < td:
                    answer.append(i)
        elif (year < ty):
            answer.append(i)
        
    return answer