def solution(info, query):
    
    info_map = {}
    
    l = ['cpp', 'java', 'python', '-']
    o = ['backend', 'frontend', '-']
    w = ['junior', 'senior', '-'] 
    f = ['chicken', 'pizza', '-']
    
    for tl in l:
        for to in o:
            for tw in w:
                for tf in f:
                    str = tl + to + tw + tf
                    info_map[str] = []
    
    for i in info:
        lan, op, work, food, test = i.split(' ')
        
        l = [lan, '-']
        o = [op, '-']
        w = [work, '-']
        f = [food, '-']
        
        for tl in l:
            for to in o:
                for tw in w:
                    for tf in f:
                        str = tl + to + tw + tf
                        info_map[str].append(int(test))
                        
    for key in info_map:
        info_map[key].sort()
        
    answer = []
    for q in query:
        lan, op, work, more = q.split(' and ')
        food, test = more.split(' ')
        
        str = lan + op + work + food
        score = info_map[str]
        idx = -1

        s = 0 
        e = len(score) - 1 #1

        while s <= e:
            mid = (s+e) // 2

            if score[mid] >= int(test):
                e = mid - 1
                idx = mid
            else:
                s = mid + 1
                
        if idx != -1:
            answer.append(len(score) - idx)
        else :
            answer.append(0)
    
    return answer