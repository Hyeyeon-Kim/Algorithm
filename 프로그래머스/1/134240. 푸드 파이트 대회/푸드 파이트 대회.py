def solution(food):
    str_len = 1
    
    for i in range(1, len(food)):
        if (food[i] % 2 != 0) :
            food[i] -= 1
        str_len += food[i]
    
    result = [0] * str_len
    
    s = 0;
    e = str_len - 1;
    typ = 1;
    cnt = 0
    
    print(food)
    print(len(result))
                   
    while (s <= e):
        if (s == e):
            result[s] = 0
            break
            
        for i in range(food[typ] // 2):
            result[s] = typ
            result[e] = typ
            s += 1
            e -= 1

        typ += 1 
    
    answer = ""
    
    for n in result:
        answer += str(n)
        
    print(result)
    return answer