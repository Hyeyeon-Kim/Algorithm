def solution(array, commands):
    answer = []
    
    for c in commands:
        s = sorted(array[c[0]-1:c[1]])
        answer.append(s[c[2]-1])
    
    return answer