def solution(id_list, reports, k):
    
    get = {id : 0 for id in id_list}
    post = {id : set() for id in id_list}
    
    for report in reports:
        p , g = report.split(' ')
        if g not in post[p]:
            get[g] += 1
            post[p].add(g)
    
    ban = set()
    
    for id in id_list: 
        if get[id] >= k:
            ban.add(id)
    
    answer = [0] * len(id_list)
    
    for i, id in enumerate(id_list): 
        for p in post[id]:
            if p in ban:
                answer[i] += 1
        
    
    # print(get, post)
    
    return answer