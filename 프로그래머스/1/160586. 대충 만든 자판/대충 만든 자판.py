def solution(keymap, targets):
    
    ch = {}
    
    for key in keymap:
        for i, k in enumerate(key, 1):
            ch[k] = min(ch.get(k, i), i)
    
    answer = []
    for target in targets:
        cnt = 0
        for t in target:
            if ch.get(t) == None:
                cnt = -1
                break
            cnt += ch[t]
        answer.append(cnt)
    # print(ch)

            
    
    return answer