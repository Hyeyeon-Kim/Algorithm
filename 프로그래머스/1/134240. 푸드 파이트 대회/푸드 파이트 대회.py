def solution(food):
    
    s = []
    
    for i in range(1, len(food)):
        cnt = food[i] // 2
        s.append(str(i) * cnt)
            
    answer = "".join(s)
    return answer + "0" + answer[::-1]