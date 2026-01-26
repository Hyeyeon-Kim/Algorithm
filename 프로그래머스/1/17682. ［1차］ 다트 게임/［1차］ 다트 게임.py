import re
def solution(dartResult):
    
    dartResult = re.findall(r'(\d+)([SDT])([*#]?)', dartResult)
    
    for i, (n, p, o) in enumerate(dartResult):
        n = int(n)
        
        if p == 'D':
            n **= 2
        elif p == 'T':
            n **= 3
        
        if o == '*':
            n *= 2
            if i != 0:
                dartResult[i-1] *= 2
        elif o == '#':
            n = -n
        
        dartResult[i] = n
        
        
    # print(dartResult)
    
    return sum(dartResult)