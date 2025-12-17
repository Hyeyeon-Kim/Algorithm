def solution(id_list, report, k):
    n = len(id_list)
    give = []
    useridx = {}
    take = [0] * n
    
    for i in range(n):
        s = set()
        give.append(s)
        useridx[id_list[i]] = i
    
    for rep in report:
        user, reuser = rep.split(' ')
        
        if reuser in give[useridx[user]]:
            continue
        
        give[useridx[user]].add(reuser)
        take[useridx[reuser]] += 1
    
    stop = set()
    
    for i in range(n):
        if take[i] >= k:
            stop.add(id_list[i])
    
    answer = []
    
    for i in range(n):
        cnt = 0
        for user in give[i]:
            if user in stop:
                cnt += 1
        answer.append(cnt)

    return answer