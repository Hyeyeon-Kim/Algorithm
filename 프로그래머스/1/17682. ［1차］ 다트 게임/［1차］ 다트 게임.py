import re 

def solution(dartResult):
    score = list(filter(None, re.split('[SDT][*#]?', dartResult)))
    plus = list(filter(None, re.split('\d+', dartResult)))

    for i in range(3):
        s = int(score[i])
        
        if plus[i][0] == 'D':
            s **= 2
        elif plus[i][0] == 'T':
            s **= 3
        
        if plus[i][-1] == '*':
            if i > 0:
                score[i-1] *= 2
            score[i] = s * 2
                
        elif plus[i][-1] == '#':
            score[i] = -s
            
        else:
            score[i] = s
            
    return sum(score)