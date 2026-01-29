import re

def solution(dartResult):
    dartResult = re.findall('(\d+)([SDT])([*#]?)', dartResult)
    
    score = []
    for dart in dartResult:
        n, p ,o = int(dart[0]), dart[1], dart[2]
        
        if p == 'D':
            n **= 2
        elif p == 'T':
            n **= 3
        
        if o == '*':
            n *= 2
            if score:
                score[-1] *= 2
        elif o == '#':
            n = -n
            
        score.append(n)

    return sum(score)