def strToDay(day):
    y,m,d = map(int, day.split('.'))
    return y * 336 + (m - 1) * 28 + (d - 1)

def dayToStr(day):
    y = day // 336
    rem = day % 336
    m = rem // 28
    d = rem % 28
    
    return f"{y}.{m+1:02d}.{d+1:02d}"

def solution(today, terms, privacies):
    today = strToDay(today)
    terms = {t: int(d) for term in terms for t, d in [term.split(' ')]}
    
    answer = []

    for i, privacie in enumerate(privacies, start = 1):
        day, t = privacie.split(' ')
        day = strToDay(day) + (terms[t] * 28) - 1
        
        if today > day:
            answer.append(i)
    
    return answer