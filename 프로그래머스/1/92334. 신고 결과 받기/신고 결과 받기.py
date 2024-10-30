def solution(id_list, report, k):
    
    cum = {}
    mail = {}
    stop = set()
    
    
    for id in id_list:
        mail[id] = set()
        cum[id] = 0
    
    for re in report:
        use, puser = re.split(' ');
        
        if puser not in mail[use]:
            cum[puser] = cum.get(puser) + 1
        
        mail[use].add(puser)
    
    for key, value in cum.items():
        if value >= k:
            stop.add(key)
    
    answer = []
    
    for user in id_list :
        cnt = 0
        if user in mail:
            for li in mail[user]:
                if li in stop:
                    cnt += 1
        answer.append(cnt)
    
    return answer