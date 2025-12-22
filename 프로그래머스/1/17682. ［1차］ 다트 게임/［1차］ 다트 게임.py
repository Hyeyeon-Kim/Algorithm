import re

def solution(dartResult):
    score = []
    bonus = []
    option = []
    
    n = -1
    
    pots = re.split(r'([A-Z*#])', dartResult)
    
    for pot in pots:
        if pot == '':
            continue
        elif pot == '*' or pot == '#':
            option[n] = pot
        elif pot == 'S' or pot == 'D' or pot == 'T':
            bonus.append(pot)
        else:
            score.append(pot)
            option.append(0)
            n += 1
    
    answer = 0
    pre = 0
    
    for i in range(n+1):
        print(score[i], bonus[i], option[i], '  ')
        s = int(score[i])
    
        if (bonus[i] == 'D'):
            s **= 2
        elif (bonus[i] == 'T'):
            s **= 3
            
        if (option[i] == '*'):
            pre *= 2
            s *= 2
        elif (option[i] == '#'):
            s = -s
        
        print(answer, pre)
        answer += pre
        pre = s
        
    answer += pre
    print(answer, pre)
    # print(score)
    # print(bonus)
    # print(option)
    

    return answer