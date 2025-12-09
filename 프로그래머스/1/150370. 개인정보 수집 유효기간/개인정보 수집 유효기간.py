def day_count(date):
    date = date.split(".")
    
    year = int(date[0]) * 28 * 12
    mon = int(date[1]) * 28
    day = int(date[2])
    
    today = year + mon + day
    return today

def change_look(date):
    ny = date // (28 * 12)
    nm = (date % (28 * 12)) // 28
    nd = (date % (28 * 12)) % 28
    
    print(date, ny, nm , nd) 

def solution(today, terms, privacies):
    today = day_count(today)
    change_look(today)
    print()
    
    term = {}
    
    for tmp in terms:
        tmp = tmp.split(" ")
        term[tmp[0]] = int(tmp[1])
    
    # print(term)
    
    answer = []
    i = 1
    for pri in privacies:
        date, ty = pri.split(" ")
        # print(date, ty)
        
        date = day_count(date)        
        dead = date + (term[ty] * 28) - 1
        
        if dead < today:
            answer.append(i)
            
        i += 1
        change_look(dead)
    

    return answer