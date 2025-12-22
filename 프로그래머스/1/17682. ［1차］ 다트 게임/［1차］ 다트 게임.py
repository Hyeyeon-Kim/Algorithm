import re

def solution(dartResult):
    pattern = re.findall(r'(\d+)([SDT])([*#]?)',dartResult)

    answer = 0
    scores = []
    
    for i, (num, bonus, option) in enumerate(pattern):
        s = int(num)
        
        if (bonus == 'D'):
            s **= 2
        elif (bonus == 'T'):
            s **= 3
            
        if (option == '*'):
            if scores: 
                scores[-1] *= 2
            s *= 2
        elif (option == '#'):
            s = -s
        scores.append(s)
        
    return sum(scores)